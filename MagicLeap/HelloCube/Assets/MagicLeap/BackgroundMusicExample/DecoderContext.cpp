// %BANNER_BEGIN%
// ---------------------------------------------------------------------
// %COPYRIGHT_BEGIN%
//
// Copyright (c) 2019 Magic Leap, Inc. All Rights Reserved.
// Use of this file is governed by the Creator Agreement, located
// here: https://id.magicleap.com/creator-terms
//
// %COPYRIGHT_END%
// ---------------------------------------------------------------------
// %BANNER_END%

#include "DecoderContext.h"

#include <ml_logging.h>
#include <ml_media_format.h>
#include <ml_media_extractor.h>
#include <ml_media_codec.h>
#include <ml_media_error.h>
#include <ml_music_service_provider.h>

MLResult OnAudioFrameDecoded(const uint8_t* bufferPtr, size_t bufferSize, int64_t pts_us)
{
    if (nullptr == bufferPtr)
    {
        ML_LOG(Error, "OnAudioFrameDecoded failed. Reason: bufferPtr was null.");
        return MLResult_InvalidParam;
    }

    if (!(bufferSize > 0))
    {
        ML_LOG(Error, "OnAudioFrameDecoded failed. Reason: invalid bufferSize.");
        return MLResult_InvalidParam;
    }

    MLResult result = MLMusicServiceProviderWriteAudioOutput(bufferPtr, bufferSize, true);
    if (MLResult_Ok != result)
    {
        ML_LOG(Error, "OnAudioFrameDecoded call to MLMusicServiceProviderWriteAudioOutput failed. Reason: %s.", MLMediaResultGetString(result));
        return result;
    }

    result = MLMusicServiceProviderNotifyPositionChange((uint32_t)pts_us / 1000);
    if (MLResult_Ok != result)
    {
        ML_LOG(Error, "OnAudioFrameDecoded call to MLMusicServiceProviderNotifyPositionChange failed. Reason: %s.", MLMediaResultGetString(result));
        return result;
    }

    return MLResult_Ok;
}

MLResult OnAudioFormatChanged(int32_t sampleRate, int32_t channelCount)
{
    MLResult result = MLMusicServiceProviderSetAudioOutput(sampleRate, channelCount);
    if (MLResult_Ok != result)
    {
        ML_LOG(Error, "OnAudioFormatChanged call to MLMusicServiceProviderSetAudioOutput failed. Reason: %s.", MLMediaResultGetString(result));
        return result;
    }

    return MLResult_Ok;
}

DecoderContext::DecoderContext(const std::string& mediaUri, const std::string& trackType) :
    _extractor(ML_INVALID_HANDLE),
    _format(ML_INVALID_HANDLE),
    _codec(ML_INVALID_HANDLE),
    _trackSamplesDemuxed(0),
    _trackSamplesEnd(false),
    _trackFramesDecoded(0),
    _trackFramesEnd(false),
    _positionUs(0),
    _durationUs(-1)
{
    MLResult result = MLMediaExtractorCreate(&_extractor);
    if (MLResult_Ok != result)
    {
        ML_LOG(Error, "DecoderContext::DecoderContext call to MLMediaExtractorCreate failed. Reason: %s.", MLMediaResultGetString(result));
        throw result;
    }

    result = MLMediaExtractorSetDataSourceForPath(_extractor, mediaUri.c_str());
    if (MLResult_Ok != result)
    {
        ML_LOG(Error, "DecoderContext::DecoderContext call to MLMediaExtractorSetDataSourceForPath failed. Reason: %s.", MLMediaResultGetString(result));
        Release();
        throw result;
    }

    //
    // select the first track that matches the desired track type
    //

    uint64_t track_count = 0;
    result = MLMediaExtractorGetTrackCount(_extractor, &track_count);
    if (MLResult_Ok != result)
    {
        ML_LOG(Error, "DecoderContext::DecoderContext call to MLMediaExtractorGetTrackCount failed. Reason: %s.", MLMediaResultGetString(result));
        Release();
        throw result;
    }

    ML_LOG(Info, "source: \"%s\" track_count: %ju\n", mediaUri.c_str(), track_count);

    std::string mimeType;

    size_t trackIndex = 0;
    for (; trackIndex < track_count; trackIndex++)
    {
        MLHandle formatTemp = ML_INVALID_HANDLE;

        result = MLMediaExtractorGetTrackFormat(_extractor, trackIndex, &formatTemp);
        if (MLResult_Ok != result || ML_INVALID_HANDLE == formatTemp )
        {
            continue;
        }

        {
            char mimeTypeRaw[MAX_KEY_STRING_SIZE] = "";
            result = MLMediaFormatGetKeyString(formatTemp, MLMediaFormat_Key_Mime, mimeTypeRaw);
            mimeType = mimeTypeRaw;
        }

        if (MLResult_Ok != result)
        {
            if (ML_INVALID_HANDLE != formatTemp)
            {
                MLMediaFormatDestroy(formatTemp);
                formatTemp = ML_INVALID_HANDLE;
            }
            continue;
        }

        char formatRaw[MAX_FORMAT_STRING_SIZE] = "";
        result = MLMediaFormatObjectToString(formatTemp, formatRaw);
        if (MLResult_Ok != result)
        {
            if (ML_INVALID_HANDLE != formatTemp)
            {
                MLMediaFormatDestroy(formatTemp);
                formatTemp = ML_INVALID_HANDLE;
            }
            continue;
        }

        ML_LOG(Info, "trackIndex: %zu mimeType: \"%s\" trackType: \"%s\" format: \"%s\"\n",
            trackIndex,
            mimeType.c_str(),
            trackType.c_str(),
            formatRaw);

        if (mimeType.find(trackType) == 0)
        {
            _format = formatTemp; // save the selected track's format
            break;
        }

        if (ML_INVALID_HANDLE != formatTemp)
        {
            MLMediaFormatDestroy(formatTemp);
            formatTemp = ML_INVALID_HANDLE;
        }
    }

    if (trackIndex >= track_count)
    {
        ML_LOG(Error, "No track starting with mime_type: \"%s\" found in media source: \"%s\"\n", trackType.c_str(), mediaUri.c_str());
        Release();
        throw MLResult_InvalidParam;
    }

    result = MLMediaExtractorSelectTrack(_extractor, trackIndex);
    if (MLResult_Ok != result)
    {
        ML_LOG(Error, "DecoderContext::DecoderContext call to MLMediaExtractorSelectTrack failed. Reason: %s.", MLMediaResultGetString(result));
        Release();
        throw result;
    }

    result = MLMediaFormatGetKeyValueInt64(_format, MLMediaFormat_Key_Duration, &_durationUs);
    if (MLResult_Ok != result)
    {
        ML_LOG(Error, "DecoderContext::DecoderContext call to MLMediaFormatGetKeyValueInt64 failed. Reason: %s.", MLMediaResultGetString(result));
        Release();
        throw result;
    }

    result = MLMediaCodecCreateCodec(MLMediaCodecCreation_ByType, MLMediaCodecType_Decoder, mimeType.c_str(), &_codec);
    if (MLResult_Ok != result)
    {
        ML_LOG(Error, "DecoderContext::DecoderContext call to MLMediaCodecCreateCodec failed. Reason: %s.", MLMediaResultGetString(result));
        Release();
        throw result;
    }

    result = MLMediaCodecConfigure(_codec, _format, (MLHandle)0);
    if (MLResult_Ok != result)
    {
        ML_LOG(Error, "DecoderContext::DecoderContext call to MLMediaCodecConfigure failed. Reason: %s.", MLMediaResultGetString(result));
        Release();
        throw result;
    }

    result = MLMediaCodecStart(_codec);
    if (MLResult_Ok != result)
    {
        ML_LOG(Error, "DecoderContext::DecoderContext call to MLMediaCodecStart failed. Reason: %s.", MLMediaResultGetString(result));
        Release();
        throw result;
    }

    ML_LOG(Info, "%s() line: %d media_source: \"%s\" returned: %s",
        __FUNCTION__, __LINE__, mediaUri.c_str(), MLMediaResultGetString(result));
}

DecoderContext::~DecoderContext()
{
    Release();
}

void DecoderContext::Release()
{
    if (ML_INVALID_HANDLE != _codec)
    {
        MLMediaCodecFlush(_codec);
        MLMediaCodecStop(_codec);
        MLMediaCodecDestroy(_codec);
        _codec = ML_INVALID_HANDLE;
    }

    if (ML_INVALID_HANDLE != _format)
    {
        MLMediaFormatDestroy(_format);
        _format = ML_INVALID_HANDLE;
    }

    if (ML_INVALID_HANDLE != _extractor)
    {
        MLMediaExtractorDestroy(_extractor);
        _extractor = ML_INVALID_HANDLE;
    }
}

MLResult DecoderContext::ProcessInput(int32_t& samplesDemuxed)
{
    if (_extractor == ML_INVALID_HANDLE)
    {
        ML_LOG(Error, "DecoderContext::ProcessInput failed. Reason: invalid _extractor handle.");
        return MLResult_InvalidParam;
    }

    if (_codec == ML_INVALID_HANDLE)
    {
        ML_LOG(Error, "DecoderContext::ProcessInput failed. Reason: invalid _codec handle.");
        return MLResult_InvalidParam;
    }

    samplesDemuxed = 0;

    // demuxing ended, nothing to do
    if (_trackSamplesEnd)
    {
        return MLResult_Ok;
    }

    //note: no need to return error, retry or wait at all
    //      - quite ordinary to have no input buffer available until a decode completes
    //      - no matter how long you wait or how many times you retry, until:
    //      - a sample is decoded and you dequeue it; this will not succeed

    int64_t  bufferIndex = MLMediaCodec_TryAgainLater;
    uint8_t* bufferPtr = nullptr;
    size_t   bufferSize = 0;

    MLResult result = MLMediaCodecDequeueInputBuffer(_codec, 0, &bufferIndex);
    if (MLResult_Ok != result)
    {
        ML_LOG(Error, "DecoderContext::ProcessInput call to MLMediaCodecDequeueInputBuffer failed. Reason: %s.", MLMediaResultGetString(result));
        return result;
    }

    if (bufferIndex == MLMediaCodec_TryAgainLater)
    {
        return result;
    }

    result = MLMediaCodecGetInputBufferPointer(_codec, (MLHandle)bufferIndex, &bufferPtr, &bufferSize);
    if (MLResult_Ok != result)
    {
        ML_LOG(Error, "DecoderContext::ProcessInput call to MLMediaCodecGetInputBufferPointer failed. Reason: %s.", MLMediaResultGetString(result));
        return result;
    }

    if (bufferPtr == nullptr)
    {
        ML_LOG(Error, "DecoderContext::ProcessInput failed. Reason: unspecified failure.");
        return MLResult_UnspecifiedFailure;
    }

    if (!(bufferSize > 0))
    {
        ML_LOG(Error, "DecoderContext::ProcessInput failed. Reason: unspecified failure.");
        return MLResult_UnspecifiedFailure;
    }

    int64_t sampleSize = -1;  // -1 if no more samples are available

    result = MLMediaExtractorReadSampleData(_extractor, bufferPtr, bufferSize, 0, &sampleSize);
    if (MLResult_Ok != result)
    {
        ML_LOG(Error, "DecoderContext::ProcessInput call to MLMediaExtractorReadSampleData failed. Reason: %s.", MLMediaResultGetString(result));
        return result;
    }

    if (sampleSize < 0)
    {
        ML_LOG(Info, "track end of input samples marked by sampleSize: %jd\n", sampleSize);
        _trackSamplesEnd = true;

        // queue an empty buffer marked EOS to denote the end of demuxing - otherwise infinite loop
        result = MLMediaCodecQueueInputBuffer(_codec, (MLHandle)bufferIndex, 0, 0, 0, MLMediaCodecBufferFlag_EOS);
        if (MLResult_Ok != result)
        {
            ML_LOG(Error, "DecoderContext::ProcessInput call to MLMediaCodecQueueInputBuffer failed. Reason: %s.", MLMediaResultGetString(result));
            return result;
        }
        return result;
    }

    int64_t sampleTrack = -1;  // important when we process multiple tracks like audio, video, subtitle
    int64_t samplePts = -1;  // -1 if no more samples are available
    int     sampleFlags = 0;  // sampleFlags & MLMediaCodecBufferFlag_EOS

    result = MLMediaExtractorGetSampleTrackIndex(_extractor, &sampleTrack);
    if (MLResult_Ok != result)
    {
        ML_LOG(Error, "DecoderContext::ProcessInput call to MLMediaExtractorGetSampleTrackIndex failed. Reason: %s.", MLMediaResultGetString(result));
        return result;
    }

    result = MLMediaExtractorGetSampleTime(_extractor, &samplePts);
    if (MLResult_Ok != result)
    {
        ML_LOG(Error, "DecoderContext::ProcessInput call to MLMediaExtractorGetSampleTime failed. Reason: %s.", MLMediaResultGetString(result));
        return result;
    }

    result = MLMediaExtractorGetSampleFlags(_extractor, &sampleFlags);
    if (MLResult_Ok != result)
    {
        ML_LOG(Error, "DecoderContext::ProcessInput call to MLMediaExtractorGetSampleFlags failed. Reason: %s.", MLMediaResultGetString(result));
        return result;
    }

    _trackSamplesDemuxed += 1;
    samplesDemuxed += 1;

    result = MLMediaCodecQueueInputBuffer(_codec, (MLHandle)bufferIndex, 0, (size_t)sampleSize, (uint64_t)samplePts, sampleFlags);
    if (MLResult_Ok != result)
    {
        ML_LOG(Error, "DecoderContext::ProcessInput call to MLMediaCodecQueueInputBuffer failed. Reason: %s.", MLMediaResultGetString(result));
        return result;
    }

    result = MLMediaExtractorAdvance(_extractor);
    if (MLResult_Ok != result)
    {
        ML_LOG(Error, "DecoderContext::ProcessInput call to MLMediaExtractorAdvance failed. Reason: %s.", MLMediaResultGetString(result));
        return result;
    }

    return MLResult_Ok;
}

MLResult DecoderContext::ProcessOutput(int32_t& framesDecoded)
{
    int64_t bufferIndex = MLMediaCodec_TryAgainLater;
    MLMediaCodecBufferInfo bufferInfo = { 0 };
    MLResult result = MLResult_Ok;

    if (_codec == ML_INVALID_HANDLE)
    {
        ML_LOG(Error, "DecoderContext::ProcessOutput failed. Reason: invalid codec handle.");
        return MLResult_InvalidParam;
    }

    framesDecoded = 0;

    // decoding ended, nothing to do
    if (_trackFramesEnd)
    {
        return MLResult_Ok;
    }

    //note: no need to return error, retry or wait at all
    //      - quite ordinary to have no output buffer until decoding completes, no point in waiting
    //      - if you did not queue an input, you cannot dequeue an output no matter how long you wait
    //      - instead of waiting for dequeing, better to queue extract and queue an input buffer

    result = MLMediaCodecDequeueOutputBuffer(_codec, &bufferInfo, 0, &bufferIndex);
    if (MLResult_Ok != result)
    {
        ML_LOG(Error, "DecoderContext::ProcessOutput call to MLMediaCodecDequeueOutputBuffer failed. Reason: %s.", MLMediaResultGetString(result));
        if (bufferIndex >= 0)
        {
            MLMediaCodecReleaseOutputBuffer(_codec, (MLHandle)bufferIndex, false);
            bufferIndex = MLMediaCodec_TryAgainLater;
        }
        return result;
    }

    if (bufferIndex < 0)
    {
        if (bufferIndex == MLMediaCodec_OutputBuffersChanged)
        {
            ML_LOG(Info, "MLMediaCodec_OutputBuffersChanged");
        }
        else if (bufferIndex == MLMediaCodec_FormatChanged)
        {
            ML_LOG(Info, "MLMediaCodec_FormatChanged");

            MLHandle codecFormat = ML_INVALID_HANDLE;

            result = MLMediaCodecGetOutputFormat(_codec, &codecFormat);
            if (MLResult_Ok != result)
            {
                ML_LOG(Error, "DecoderContext::ProcessOutput call to MLMediaCodecGetOutputFormat failed. Reason: %s.", MLMediaResultGetString(result));
                return result;
            }

            if (codecFormat == ML_INVALID_HANDLE)
            {
                ML_LOG(Error, "DecoderContext::ProcessOutput failed. Reason: invalid codec format.");
                return MLResult_UnspecifiedFailure;
            }

            // changing sampling rate on-the-fly is not supported by Audio Service.
            // we can still "fake" this by changing the "pitch" of the stream.
            int32_t sampleRate = 0;
            int32_t channelCount = 0;

            result = MLMediaFormatGetKeyValueInt32(codecFormat, MLMediaFormat_Key_Sample_Rate, &sampleRate);
            if (MLResult_Ok != result)
            {
                ML_LOG(Error, "DecoderContext::ProcessOutput call to MLMediaFormatGetKeyValueInt32 failed. Reason: %s.", MLMediaResultGetString(result));
                return result;
            }

            result = MLMediaFormatGetKeyValueInt32(codecFormat, MLMediaFormat_Key_Channel_Count, &channelCount);
            if (MLResult_Ok != result)
            {
                ML_LOG(Error, "DecoderContext::ProcessOutput call to MLMediaFormatGetKeyValueInt32 failed. Reason: %s.", MLMediaResultGetString(result));
                return result;
            }

            if (!(sampleRate > 0))
            {
                ML_LOG(Error, "DecoderContext::ProcessOutput failed. Reason: invalid sample rate.");
                return MLResult_UnspecifiedFailure;
            }

            if (!(channelCount > 0))
            {
                ML_LOG(Error, "DecoderContext::ProcessOutput failed. Reason: invalid channel count.");
                return MLResult_UnspecifiedFailure;
            }

            char* codecFormatStr = new char[MAX_FORMAT_STRING_SIZE];
            if (nullptr != codecFormatStr)
            {
                if (MLResult_Ok == MLMediaFormatObjectToString(codecFormat, codecFormatStr))
                {
                    ML_LOG(Info, "format changed to: %s", codecFormatStr);
                }
                delete[] codecFormatStr;
                codecFormatStr = nullptr;
            }

            result = OnAudioFormatChanged(sampleRate, channelCount);
            if (MLResult_Ok != result)
            {
                ML_LOG(Error, "DecoderContext::ProcessOutput callback to audio format changed failed. Reason: %s.", MLMediaResultGetString(result));
                return result;
            }
        }
        // no decoded frames in output buffer queue for now
        return MLResult_Ok;
    }

    if (bufferInfo.flags & MLMediaCodecBufferFlag_EOS)
    {
        ML_LOG(Info, "track end of output frames marked by eos flag\n");
        _trackFramesEnd = true;
        if (bufferInfo.size <= 0)
        {
            if (bufferIndex >= 0)
            {
                MLMediaCodecReleaseOutputBuffer(_codec, (MLHandle)bufferIndex, false);
                bufferIndex = MLMediaCodec_TryAgainLater;
            }
            return MLResult_Ok;
        }
    }

    _trackFramesDecoded += 1;
    framesDecoded += 1;

    //process decoded buffer
    const uint8_t* bufferPtr = nullptr;
    size_t         bufferSize = 0;

    result = MLMediaCodecGetOutputBufferPointer(_codec, (MLHandle)bufferIndex, &bufferPtr, &bufferSize);
    if (MLResult_Ok != result)
    {
        ML_LOG(Error, "DecoderContext::ProcessOutput call to MLMediaCodecGetOutputBufferPointer failed. Reason: %s.", MLMediaResultGetString(result));
        if (bufferIndex >= 0)
        {
            MLMediaCodecReleaseOutputBuffer(_codec, (MLHandle)bufferIndex, false);
            bufferIndex = MLMediaCodec_TryAgainLater;
        }
        return result;
    }

    if (nullptr == bufferPtr)
    {
        ML_LOG(Error, "DecoderContext::ProcessOutput failed. Reason: bufferPtr is nullptr.");
        if (bufferIndex >= 0)
        {
            MLMediaCodecReleaseOutputBuffer(_codec, (MLHandle)bufferIndex, false);
            bufferIndex = MLMediaCodec_TryAgainLater;
        }
        return MLResult_UnspecifiedFailure;
    }

    if (!(bufferSize > 0))
    {
        // nothing to decode
        return MLResult_Ok;
    }

    _positionUs = bufferInfo.presentation_time_us;

    result = OnAudioFrameDecoded(bufferPtr, bufferSize, bufferInfo.presentation_time_us);
    if (MLResult_Ok != result)
    {
        ML_LOG(Error, "DecoderContext::ProcessOutput callback to on audio frame decoded failed. Reason: %s.", MLMediaResultGetString(result));
        if (bufferIndex >= 0)
        {
            MLMediaCodecReleaseOutputBuffer(_codec, (MLHandle)bufferIndex, false);
            bufferIndex = MLMediaCodec_TryAgainLater;
        }
        return result;
    }

    if (bufferIndex >= 0)
    {
        MLMediaCodecReleaseOutputBuffer(_codec, (MLHandle)bufferIndex, false);
        bufferIndex = MLMediaCodec_TryAgainLater;
    }

    return result;
}

MLResult DecoderContext::Flush()
{
    MLResult result = MLResult_Ok;

    if (_codec == ML_INVALID_HANDLE)
    {
        ML_LOG(Error, "DecoderContext::Flush failed. Reason: invalid codec.");
        return MLResult_InvalidParam;
    }

    result = MLMediaCodecFlush(_codec);
    if (MLResult_Ok != result)
    {
        ML_LOG(Error, "DecoderContext::Flush call to MLMediaCodecFlush failed. Reason: %s.", MLMediaResultGetString(result));
        return result;
    }

    return result;
}

MLResult DecoderContext::Seek(int64_t timeUs)
{
    MLResult result = MLResult_Ok;

    if (_codec == ML_INVALID_HANDLE)
    {
        ML_LOG(Error, "DecoderContext::Seek failed. Reason: invalid _codec.");
        return MLResult_InvalidParam;
    }

    if (_extractor == ML_INVALID_HANDLE)
    {
        ML_LOG(Error, "DecoderContext::Seek failed. Reason: invalid _extractor.");
        return MLResult_InvalidParam;
    }

    result = MLMediaCodecFlush(_codec);
    if (MLResult_Ok != result)
    {
        ML_LOG(Error, "DecoderContext::Seek call to MLMediaCodecFlush failed. Reason: %s.", MLMediaResultGetString(result));
        return result;
    }

    result = MLMediaExtractorSeekTo(_extractor, timeUs, MLMediaSeekMode_Next_Sync);
    if (MLResult_Ok != result)
    {
        ML_LOG(Error, "DecoderContext::Seek call to MLMediaExtractorSeekTo failed. Reason: %s.", MLMediaResultGetString(result));
        return result;
    }

    return result;
}

MLResult DecoderContext::GetPosition(int64_t& positionUs)
{
    positionUs = _positionUs;
    return MLResult_Ok;
}

MLResult DecoderContext::GetDuration(int64_t& durationUs)
{
    durationUs = _durationUs;
    return MLResult_Ok;
}

MLResult DecoderContext::GetDecodeCompleted(bool& decodeCompleted)
{
    decodeCompleted = _trackFramesEnd;
    return MLResult_Ok;
}
