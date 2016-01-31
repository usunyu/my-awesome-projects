/*
 * =====================================================================================
 *
 *       Filename:  gl_data.hpp
 *
 *    Description:  load data
 *
 *        Version:  1.0
 *        Created:  06/18/2014 20:53:16
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Pablo Colapinto (), gmail -> wolftype
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef  gl_data_INC
#define  gl_data_INC

#include <fstream>
#include <stdexcept>
#include <vector>

#include <stdint.h>

namespace lynda {


struct Bitmap{


    int width;
    int height;
    short BitsPerPixel;
    std::vector<unsigned char> pixels;

    Bitmap(const char* FilePath) : width(0), height(0), BitsPerPixel(0){
      load(FilePath);  
    }

    //adapted from http://stackoverflow.com/questions/20595340/loading-a-tga-bmp-file-in-c-opengl
    void load(const char* FilePath)
    {
        std::fstream hFile;
       
        //search for file by going up file directory tree up to 5 times
        int attempts = 0;
        string nfilepath = FilePath;
        while (!hFile.is_open() && attempts < 5) {
            hFile.open(nfilepath.c_str(), std::ios::in | std::ios::binary);
            nfilepath = "../" + nfilepath;   
            attempts += 1;
        }
        if (!hFile.is_open()) throw std::invalid_argument("Error: File Not Found.");

        hFile.seekg(0, std::ios::end);
        int Length = hFile.tellg();
        hFile.seekg(0, std::ios::beg);
        std::vector<uint8_t> FileInfo(Length);
        hFile.read(reinterpret_cast<char*>(FileInfo.data()), 54);

        if(FileInfo[0] != 'B' && FileInfo[1] != 'M')
        {
            hFile.close();
            throw std::invalid_argument("Error: Invalid File Format. Bitmap Required.");
        }

        if (FileInfo[28] != 24 && FileInfo[28] != 32)
        {
            hFile.close();
            throw std::invalid_argument("Error: Invalid File Format. 24 or 32 bit Image Required.");
        }

        BitsPerPixel = FileInfo[28];
        width = FileInfo[18] + (FileInfo[19] << 8);
        height = FileInfo[22] + (FileInfo[23] << 8);
        uint32_t pixelsOffset = FileInfo[10] + (FileInfo[11] << 8);
        uint32_t size = ((width * BitsPerPixel + 31) / 32) * 4 * height;
        pixels.resize(size);

        hFile.seekg (pixelsOffset, std::ios::beg);
        hFile.read(reinterpret_cast<char*>(pixels.data()), size);
        hFile.close();
    }

};

} //lynda::

#endif   /* ----- #ifndef gl_data_INC  ----- */
