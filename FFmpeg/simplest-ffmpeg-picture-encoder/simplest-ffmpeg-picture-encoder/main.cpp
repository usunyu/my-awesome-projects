//
//  main.cpp
//  simplest-ffmpeg-picture-encoder
//
//  Created by Yu Sun on 6/9/20.
//  Copyright © 2020 usunyu. All rights reserved.
//

/**
 * 最简单的基于FFmpeg的图像编码器
 * Simplest FFmpeg Picture Encoder
 *
 * 雷霄骅 Lei Xiaohua
 * leixiaohua1020@126.com
 * 中国传媒大学/数字电视技术
 * Communication University of China / Digital TV Technology
 * http://blog.csdn.net/leixiaohua1020
 *
 * 本程序实现了YUV420P像素数据编码为JPEG图片。是最简单的FFmpeg编码方面的教程。
 * 通过学习本例子可以了解FFmpeg的编码流程。
 */

#include <stdio.h>

#define __STDC_CONSTANT_MACROS

#ifdef _WIN32
//Windows
extern "C"
{
#include "libavcodec/avcodec.h"
#include "libavformat/avformat.h"
};
#else
//Linux...
#ifdef __cplusplus
extern "C"
{
#endif
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#ifdef __cplusplus
};
#endif
#endif


int main(int argc, const char * argv[]) {
  AVFormatContext* pFormatCtx;
  AVOutputFormat* fmt;
  AVStream* video_st;
  AVCodecContext* pCodecCtx;
  AVCodec* pCodec;
  
  uint8_t* picture_buf;
  AVFrame* picture;
  AVPacket pkt;
  int y_size;
  int got_picture=0;
  int size;
  
  int ret=0;
  
  FILE *in_file = NULL;                            //YUV source
  int in_w=480,in_h=272;                           //YUV's width and height
  const char* out_file = "cuc_view_encode.jpg";    //Output file
  
  in_file = fopen("../../cuc_view_480x272.yuv", "rb");
  
  av_register_all();
  
  //Method 1
  pFormatCtx = avformat_alloc_context();
  //Guess format
  fmt = av_guess_format("mjpeg", NULL, NULL);
  pFormatCtx->oformat = fmt;
  //Output URL
  if (avio_open(&pFormatCtx->pb,out_file, AVIO_FLAG_READ_WRITE) < 0){
    printf("Couldn't open output file.");
    return -1;
  }
  
  //Method 2. More simple
  //avformat_alloc_output_context2(&pFormatCtx, NULL, NULL, out_file);
  //fmt = pFormatCtx->oformat;
  
  video_st = avformat_new_stream(pFormatCtx, 0);
  if (video_st==NULL){
    return -1;
  }
  pCodecCtx = video_st->codec;
  pCodecCtx->codec_id = fmt->video_codec;
  pCodecCtx->codec_type = AVMEDIA_TYPE_VIDEO;
  pCodecCtx->pix_fmt = AV_PIX_FMT_YUVJ420P;
  
  pCodecCtx->width = in_w;
  pCodecCtx->height = in_h;
  
  pCodecCtx->time_base.num = 1;
  pCodecCtx->time_base.den = 25;
  //Output some information
  av_dump_format(pFormatCtx, 0, out_file, 1);
  
  pCodec = avcodec_find_encoder(pCodecCtx->codec_id);
  if (!pCodec){
    printf("Codec not found.");
    return -1;
  }
  if (avcodec_open2(pCodecCtx, pCodec,NULL) < 0){
    printf("Could not open codec.");
    return -1;
  }
  picture = av_frame_alloc();
  size = avpicture_get_size(pCodecCtx->pix_fmt, pCodecCtx->width, pCodecCtx->height);
  picture_buf = (uint8_t *)av_malloc(size);
  if (!picture_buf)
  {
    return -1;
  }
  avpicture_fill((AVPicture *)picture, picture_buf, pCodecCtx->pix_fmt, pCodecCtx->width, pCodecCtx->height);

  //Write Header
  avformat_write_header(pFormatCtx,NULL);

  y_size = pCodecCtx->width * pCodecCtx->height;
  av_new_packet(&pkt,y_size*3);
  //Read YUV
  if (fread(picture_buf, 1, y_size*3/2, in_file) <=0)
  {
    printf("Could not read input file.");
    return -1;
  }
  picture->data[0] = picture_buf;              // Y
  picture->data[1] = picture_buf+ y_size;      // U
  picture->data[2] = picture_buf+ y_size*5/4;  // V

  //Encode
  ret = avcodec_encode_video2(pCodecCtx, &pkt,picture, &got_picture);
  if(ret < 0){
    printf("Encode Error.\n");
    return -1;
  }
  if (got_picture==1){
    pkt.stream_index = video_st->index;
    ret = av_write_frame(pFormatCtx, &pkt);
  }

  av_free_packet(&pkt);
  //Write Trailer
  av_write_trailer(pFormatCtx);

  printf("Encode Successful.\n");

  if (video_st){
    avcodec_close(video_st->codec);
    av_free(picture);
    av_free(picture_buf);
  }
  avio_close(pFormatCtx->pb);
  avformat_free_context(pFormatCtx);

  fclose(in_file);
  
  return 0;
}
