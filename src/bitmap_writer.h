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
    void writeWord(word word, FILE * file);
    void writeDWord(dword dword, FILE * file);
    
    void writeFileHeader(struct fileheader & fileheader, FILE * file);
    void writeInfoHeader(struct infoheader & infoheader, FILE * file);
    void writePixel(struct pixel & pixel, FILE * file);
    
public:
    void writeBitmap(Bitmap & bitmap, const char * filePath);
};

#endif /* defined(__RayTracer__bitmap_writer__) */
