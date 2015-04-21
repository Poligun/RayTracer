//
//  bitmap_writer.h
//  RayTracer
//
//  Created by ZhaoYuhan on 4/20/15.
//  Copyright (c) 2015 ZhaoYuhan. All rights reserved.
//

#ifndef __RayTracer__bitmap_writer__
#define __RayTracer__bitmap_writer__

#include <cstdio>
#include "headers.h"

class Bitmap;

class BitmapWriter
{
private:
    FILE * file;
    
    void writeWord(word word);
    void writeDWord(dword dword);
    
    void writeFileHeader(struct fileheader * fileheader);
    void writeInfoHeader(struct infoheader * infoheader);
    void writePixel(struct pixel * pixel);
    
public:
    BitmapWriter(const char * filePath);
    void writeBitmap(Bitmap * bitmap);
    void close();
};

#endif /* defined(__RayTracer__bitmap_writer__) */
