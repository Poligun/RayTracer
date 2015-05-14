//
//  bitmap_reader.cpp
//  RayTracer
//
//  Created by ZhaoYuhan on 5/13/15.
//  Copyright (c) 2015 ZhaoYuhan. All rights reserved.
//

#include "bitmap_reader.h"
#include "bitmap.h"

word BitmapReader::readWord(FILE * file)
{
    word word;
    fread(&word, sizeof(byte), 2, file);
    return word;
}

dword BitmapReader::readDWord(FILE * file)
{
    dword dword;
    fread(&dword, sizeof(byte), 4, file);
    return dword;
}


void BitmapReader::readFileHeader(struct fileheader & fileheader, FILE * file)
{
    fileheader.type = readWord(file);
    fileheader.fileSize = readDWord(file);
    fileheader.reserved1 = readWord(file);
    fileheader.reserved2 = readWord(file);
    fileheader.offset = readDWord(file);
}

void BitmapReader::readInfoHeader(struct infoheader & infoheader, FILE * file)
{
    infoheader.size = readDWord(file);
    infoheader.width = readDWord(file);
    infoheader.height = readDWord(file);
    infoheader.planes = readWord(file);
    infoheader.bitCount = readWord(file);
    infoheader.compression = readDWord(file);
    infoheader.imageSize = readDWord(file);
    infoheader.xPixelsPerMeter = readDWord(file);
    infoheader.yPixelsPerMeter = readDWord(file);
    infoheader.colorUsed = readDWord(file);
    infoheader.colorImportant = readDWord(file);
}

void BitmapReader::readPixel(struct pixel & pixel, FILE * file)
{
    fread(&pixel.blue, sizeof(byte), 1, file);
    fread(&pixel.green, sizeof(byte), 1, file);
    fread(&pixel.red, sizeof(byte), 1, file);
}

Bitmap * BitmapReader::readBitmap(const char * filePath)
{
    FILE * file = fopen(filePath, "rb");
    
    struct fileheader fileheader;
    readFileHeader(fileheader, file);
    
    struct infoheader infoheader;
    readInfoHeader(infoheader, file);
    
    if (infoheader.bitCount != 24) {
        printf("Error: only 24-bit supported currently.\n");
        return NULL;
    }
    
    Bitmap * bitmap = new Bitmap(infoheader.width, infoheader.height);
    
    bitmap->fileheader = fileheader;
    bitmap->infoheader = infoheader;
    
    byte byte;
    
    for (int i = 0; i < bitmap->height; i++) {
        for (int j = 0; j < bitmap->width; j++)
            readPixel(bitmap->get(j, i), file);
        
        for (int j = 0; j < bitmap->paddingZeros; j++)
            fread(&byte, sizeof(byte), 1, file);
    }

    return bitmap;
}
