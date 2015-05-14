//
//  bitmap_reader.h
//  RayTracer
//
//  Created by ZhaoYuhan on 5/13/15.
//  Copyright (c) 2015 ZhaoYuhan. All rights reserved.
//

#ifndef __RayTracer__bitmap_reader__
#define __RayTracer__bitmap_reader__

#include <cstdio>
#include "headers.h"

class Bitmap;

class BitmapReader
{
private:
    word readWord(FILE * file);
    dword readDWord(FILE * file);

    void readFileHeader(struct fileheader & fileheader, FILE * file);
    void readInfoHeader(struct infoheader & infoheader, FILE * file);
    void readPixel(struct pixel & pixel, FILE * file);
    
public:
    Bitmap * readBitmap(const char * filePath);
};

#endif /* defined(__RayTracer__bitmap_reader__) */
