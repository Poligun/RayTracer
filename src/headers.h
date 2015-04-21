//
//  fileheader.h
//  RayTracer
//
//  Created by ZhaoYuhan on 4/20/15.
//  Copyright (c) 2015 ZhaoYuhan. All rights reserved.
//

#ifndef RayTracer_fileheader_h
#define RayTracer_fileheader_h

typedef unsigned char byte;
typedef unsigned short word;
typedef unsigned int dword;

const unsigned int FILE_HEADER_SIZE = 14;
const unsigned int INFO_HEADER_SIZE = 40;

struct fileheader
{
    word type = 0x4D42;
    dword fileSize = 0;
    word reserved1 = 0;
    word reserved2 = 0;
    dword offset = FILE_HEADER_SIZE + INFO_HEADER_SIZE;
};

struct infoheader
{
    dword size = 40;
    dword width;
    dword height;
    word planes = 1;
    word bitCount = 24;
    dword compression = 0;
    dword imageSize;
    dword xPixelsPerMeter = 0x2E20;
    dword yPixelsPerMeter = 0x2E20;
    dword colorUsed = 0;
    dword colorImportant = 0;
};

struct pixel
{
    byte blue = 0x00;
    byte green = 0x00;
    byte red = 0x00;
};

#endif
