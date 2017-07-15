/**
 * Simplest Librtmp Send 264
 *
 * 雷霄骅，张晖
 * leixiaohua1020@126.com
 * zhanghuicuc@gmail.com
 * 中国传媒大学/数字电视技术
 * Communication University of China / Digital TV Technology
 * http://blog.csdn.net/leixiaohua1020
 *
 * 本程序用于将内存中的H.264数据推送至RTMP流媒体服务器。
 * This program can send local h264 stream to net server as rtmp live stream.
 */

// LibRTMPSendH264Sample.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <stdio.h>
#include "librtmp_send264.h"

FILE *fp_send1;

//读文件的回调函数
//we use this callback function to read data from buffer
int read_buffer1(unsigned char *buf, int buf_size)
{
    if (!feof(fp_send1))
    {
        int true_size = fread(buf, 1, buf_size, fp_send1);
        return true_size;
    }
    else
    {
        return -1;
    }
}

char* rtmp_url = "rtmp://txy.live-send.acg.tv/live-txy/?streamname=live_6235300_5849362&key=10fc91777ea6f60a940ab13fab01c7f5";

int main(int argc, char* argv[])
{
    fp_send1 = fopen("cuc_ieschool.h264", "rb");

    //初始化并连接到服务器
    RTMP264_Connect(rtmp_url);

    //发送
    RTMP264_Send(read_buffer1);

    //断开连接并释放相关资源
    RTMP264_Close();

    std::cout << "Press Enter to Continue" << std::endl;
    std::cin.ignore();

    return 0;
}
