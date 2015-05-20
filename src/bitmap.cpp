//
//  bitmap.cpp
//  RayTracer
//
//  Created by ZhaoYuhan on 4/20/15.
//  Copyright (c) 2015 ZhaoYuhan. All rights reserved.
//

#include "bitmap.h"

Bitmap::Bitmap(unsigned int width, unsigned int height)
{
    initialize(width, height);
}

void Bitmap::clean()
{
    if (this->pixels) {
        for (auto i = 0; i < this->height; i++)
            delete [] this->pixels[i];
        delete [] this->pixels;
    }
    this->pixels = NULL;
}

void Bitmap::initialize(unsigned int width, unsigned int height)
{
    this->width = width;
    this->height = height;
    
    this->infoheader.width = width;
    this->infoheader.height = height;
    
    this->bytesPerLine = (width * this->infoheader.bitCount + 31) / 32 * 4;
    this->paddingZeros = this->bytesPerLine - (width * this->infoheader.bitCount) / 8;
    this->infoheader.imageSize = this->bytesPerLine * height;
    this->fileheader.fileSize = this->infoheader.imageSize + FILE_HEADER_SIZE + INFO_HEADER_SIZE;
    
    clean();
    
    this->pixels = new struct pixel *[height];
    for (auto i = 0; i < height; i++)
        this->pixels[i] = new struct pixel[width];
}

