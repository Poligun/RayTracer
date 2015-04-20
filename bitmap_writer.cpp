//
//  bitmap_writer.cpp
//  RayTracer
//
//  Created by ZhaoYuhan on 4/20/15.
//  Copyright (c) 2015 ZhaoYuhan. All rights reserved.
//

#include "bitmap_writer.h"
#include "bitmap.h"

void BitmapWriter::writeWord(word word)
{
    fwrite(&word, sizeof(byte), 2, this->file);
}

void BitmapWriter::writeDWord(dword dword)
{
    fwrite(&dword, sizeof(byte), 4, this->file);
}

void BitmapWriter::writeFileHeader(struct fileheader * fileheader)
{
    writeWord(fileheader->type);
    writeDWord(fileheader->fileSize);
    writeWord(fileheader->reserved1);
    writeWord(fileheader->reserved2);
    writeDWord(fileheader->offset);
}

void BitmapWriter::writeInfoHeader(struct infoheader * infoheader)
{
    writeDWord(infoheader->size);
    writeDWord(infoheader->width);
    writeDWord(infoheader->height);
    writeWord(infoheader->planes);
    writeWord(infoheader->bitCount);
    writeDWord(infoheader->compression);
    writeDWord(infoheader->imageSize);
    writeDWord(infoheader->xPixelsPerMeter);
    writeDWord(infoheader->yPixelsPerMeter);
    writeDWord(infoheader->colorUsed);
    writeDWord(infoheader->colorImportant);
}

void BitmapWriter::writePixel(struct pixel * pixel)
{
    fwrite(&pixel->blue, sizeof(byte), 1, this->file);
    fwrite(&pixel->green, sizeof(byte), 1, this->file);
    fwrite(&pixel->red, sizeof(byte), 1, this->file);
}

BitmapWriter::BitmapWriter(const char * filePath)
{
    this->file = fopen(filePath, "wb");
}

void BitmapWriter::close()
{
    fclose(this->file);
}

void BitmapWriter::writeBitmap(Bitmap * bitmap)
{
    writeFileHeader(&bitmap->fileheader);
    writeInfoHeader(&bitmap->infoheader);
    
    byte zero = 0;
    
    for (int i = 0; i < bitmap->height; i++) {
        for (int j = 0; j < bitmap->width; j++)
            writePixel(bitmap->get(j, i));
        
        for (int j = 0; j < bitmap->paddingZeros; j++)
            fwrite(&zero, sizeof(byte), 1, this->file);
    }
}
