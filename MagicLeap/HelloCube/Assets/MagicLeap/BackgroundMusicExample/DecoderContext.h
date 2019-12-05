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

#pragma once

#include <string>
#include <ml_api.h>

class DecoderContext
{
public:
    DecoderContext(const std::string& mediaUri, const std::string& trackType);
    ~DecoderContext();

    MLResult ProcessInput(int32_t& samplesDemuxed);
    MLResult ProcessOutput(int32_t& framesDecoded);
    MLResult Flush();
    MLResult Seek(int64_t timeUs);
    MLResult GetPosition(int64_t& positionUs);
    MLResult GetDuration(int64_t& durationUs);
    MLResult GetDecodeCompleted(bool& decodeCompleted);

private:
    MLHandle    _extractor;             // extractor for source (demuxer)
    MLHandle    _format;                // track format
    MLHandle    _codec;                 // track codec
    int64_t     _trackSamplesDemuxed;   // number of samples demuxed for the track
    bool        _trackSamplesEnd;       // samples demuxed for the track ended
    int64_t     _trackFramesDecoded;    // number of frames decoded for the track
    bool        _trackFramesEnd;        // frames  decoded for the track ended
    int64_t     _positionUs;            // pts of the last decoded frame in microseconds
    int64_t     _durationUs;            // format duration in microseconds

    void Release();
};
