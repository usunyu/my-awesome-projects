//
//  main.cpp
//  simplest-ffmpeg-audio-encoder
//
//  Created by Yu Sun on 6/13/20.
//  Copyright © 2020 usunyu. All rights reserved.
//

/**
 *最简单的基于FFmpeg的音频编码器
 *Simplest FFmpeg Audio Encoder
 *
 *雷霄骅 Lei Xiaohua
 *leixiaohua1020@126.com
 *中国传媒大学/数字电视技术
 *Communication University of China / Digital TV Technology
 *http://blog.csdn.net/leixiaohua1020
 *
 *本程序实现了音频PCM采样数据编码为压缩码流（MP3，WMA，AAC等）。
 *是最简单的FFmpeg音频编码方面的教程。
 *通过学习本例子可以了解FFmpeg的编码流程。
 *This software encode PCM data to AAC bitstream.
 *It's the simplest audio encoding software based on FFmpeg.
 *Suitable for beginner of FFmpeg
 */

#include <stdio.h>

#define __STDC_CONSTANT_MACROS

#ifdef _WIN32
//Windows
extern "C"
{
#include "libavutil/opt.h"
#include "libavcodec/avcodec.h"
#include "libavutil/imgutils.h"
};
#else
//Linux...
#ifdef __cplusplus
extern "C"
{
#endif
#include <libavutil/opt.h>
#include <libavcodec/avcodec.h>
#include <libavutil/imgutils.h>
#ifdef __cplusplus
};
#endif
#endif

int main(int argc, const char * argv[]) {
  AVCodec *pCodec;
  AVCodecContext *pCodecCtx= NULL;
  int i, ret, got_output;
  FILE *fp_in;
  FILE *fp_out;
  
  AVFrame *pFrame;
  uint8_t* frame_buf;
  int size=0;
  
  AVPacket pkt;
  int y_size;
  int framecnt=0;
  
  char filename_in[]="tdjm.pcm";
  
  AVCodecID codec_id=AV_CODEC_ID_AAC;
  char filename_out[]="tdjm.aac";
  
  int framenum=1000;
  
  avcodec_register_all();
  
  pCodec = avcodec_find_encoder(codec_id);
  if (!pCodec) {
    printf("Codec not found\n");
    return -1;
  }
  pCodecCtx = avcodec_alloc_context3(pCodec);
  if (!pCodecCtx) {
    printf("Could not allocate video codec context\n");
    return -1;
  }
  
  pCodecCtx->codec_id = codec_id;
  pCodecCtx->codec_type = AVMEDIA_TYPE_AUDIO;
  pCodecCtx->sample_fmt = AV_SAMPLE_FMT_S16;
  pCodecCtx->sample_rate= 44100;
  pCodecCtx->channel_layout=AV_CH_LAYOUT_STEREO;
  pCodecCtx->channels = av_get_channel_layout_nb_channels(pCodecCtx->channel_layout);
  pCodecCtx->bit_rate = 64000;
  
  if (avcodec_open2(pCodecCtx, pCodec, NULL) < 0) {
    printf("Could not open codec\n");
    return -1;
  }
  
  pFrame = av_frame_alloc();
  pFrame->nb_samples= pCodecCtx->frame_size;
  pFrame->format= pCodecCtx->sample_fmt;
  size = av_samples_get_buffer_size(NULL, pCodecCtx->channels,pCodecCtx->frame_size,pCodecCtx->sample_fmt, 1);
  frame_buf = (uint8_t *)av_malloc(size);
  avcodec_fill_audio_frame(pFrame, pCodecCtx->channels, pCodecCtx->sample_fmt,(const uint8_t*)frame_buf, size, 1);
  
  //Input raw data
  fp_in = fopen(filename_in, "rb");
  if (!fp_in) {
    printf("Could not open %s\n", filename_in);
    return -1;
  }
  //Output bitstream
  fp_out = fopen(filename_out, "wb");
  if (!fp_out) {
    printf("Could not open %s\n", filename_out);
    return -1;
  }
  
  //Encode
  for (i = 0; i < framenum; i++) {
    av_init_packet(&pkt);
    pkt.data = NULL;    // packet data will be allocated by the encoder
    pkt.size = 0;
    //Read raw data
    if (fread(frame_buf, 1, size, fp_in) <= 0){
      printf("Failed to read raw data! \n");
      return -1;
    }else if(feof(fp_in)){
      break;
    }
    
    pFrame->pts = i;
    ret = avcodec_encode_audio2(pCodecCtx, &pkt, pFrame, &got_output);
    if (ret < 0) {
      printf("Error encoding frame\n");
      return -1;
    }
    if (got_output) {
      printf("Succeed to encode frame: %5d\tsize:%5d\n",framecnt,pkt.size);
      framecnt++;
      fwrite(pkt.data, 1, pkt.size, fp_out);
      av_free_packet(&pkt);
    }
  }
  //Flush Encoder
  for (got_output = 1; got_output; i++) {
    ret = avcodec_encode_audio2(pCodecCtx, &pkt, NULL, &got_output);
    if (ret < 0) {
      printf("Error encoding frame\n");
      return -1;
    }
    if (got_output) {
      printf("Flush Encoder: Succeed to encode 1 frame!\tsize:%5d\n",pkt.size);
      fwrite(pkt.data, 1, pkt.size, fp_out);
      av_free_packet(&pkt);
    }
  }
  
  fclose(fp_out);
  avcodec_close(pCodecCtx);
  av_free(pCodecCtx);
  av_freep(&pFrame->data[0]);
  av_frame_free(&pFrame);
  
  return 0;
}
