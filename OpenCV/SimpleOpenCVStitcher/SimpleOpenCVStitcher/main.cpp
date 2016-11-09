//
//  main.cpp
//  SimpleOpenCVStitcher
//
//  Created by Yu Sun on 11/10/16.
//  Copyright © 2016 Yu Sun. All rights reserved.
//

#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/stitching.hpp>

#define OUTPUT_FILE "output.jpg"

int main(int argc, const char * argv[]) {
    
    std::vector< cv::Mat > vImg = {
        cv::imread( "1.jpg" ),
        cv::imread( "2.jpg" ),
        cv::imread( "3.jpg" ),
        cv::imread( "4.jpg" ),
    };
    // create a Stitcher object
    auto stitcher = cv::Stitcher::createDefault();
    // Mat to store the output pano image
    cv::Mat rImg;
    // stitch the input images together
    cv::Stitcher::Status status = stitcher.stitch(vImg, rImg);
    
    if (status != cv::Stitcher::OK)
    {
        std::cout << "Can't stitch images, error code = " << int(status) << std::endl;
        return -1;
    }
    // write the result to the output image
    imwrite(OUTPUT_FILE, rImg);
    return 0;
}
