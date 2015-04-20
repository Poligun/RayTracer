//
//  bitmap.h
//  RayTracer
//
//  Created by ZhaoYuhan on 4/20/15.
//  Copyright (c) 2015 ZhaoYuhan. All rights reserved.
//

#ifndef __RayTracer__bitmap__
#define __RayTracer__bitmap__

#include "headers.h"
#include "bitmap_writer.h"

class Bitmap
{
private:
    struct fileheader fileheader;
    struct infoheader infoheader;

    struct pixel ** pixels;
    unsigned int bytesPerLine;
    unsigned int paddingZeros;
    
    friend void BitmapWriter::writeBitmap(Bitmap *);

public:
    unsigned int width;
    unsigned int height;

    Bitmap(unsigned int width, unsigned int height);
    ~Bitmap();
    
    inline struct pixel * get(unsigned int x, unsigned int y)
    {
        return & this->pixels[y][x];
    }
};

#endif /* defined(__RayTracer__bitmap__) */
