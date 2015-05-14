//
//  bitmap_writer.cpp
//  RayTracer
//
//  Created by ZhaoYuhan on 4/20/15.
//  Copyright (c) 2015 ZhaoYuhan. All rights reserved.
//

#include "bitmap_writer.h"
#include "bitmap.h"

void BitmapWriter::writeWord(word word, FILE * file)
{
    fwrite(&word, sizeof(byte), 2, file);
}

void BitmapWriter::writeDWord(dword dword, FILE * file)
{
    fwrite(&dword, sizeof(byte), 4, file);
}

void BitmapWriter::writeFileHeader(struct fileheader & fileheader, FILE * file)
{
    writeWord(fileheader.type, file);
    writeDWord(fileheader.fileSize, file);
    writeWord(fileheader.reserved1, file);
    writeWord(fileheader.reserved2, file);
    writeDWord(fileheader.offset, file);
}

void BitmapWriter::writeInfoHeader(struct infoheader & infoheader, FILE * file)
{
    writeDWord(infoheader.size, file);
    writeDWord(infoheader.width, file);
    writeDWord(infoheader.height, file);
    writeWord(infoheader.planes, file);
    writeWord(infoheader.bitCount, file);
    writeDWord(infoheader.compression, file);
    writeDWord(infoheader.imageSize, file);
    writeDWord(infoheader.xPixelsPerMeter, file);
    writeDWord(infoheader.yPixelsPerMeter, file);
    writeDWord(infoheader.colorUsed, file);
    writeDWord(infoheader.colorImportant, file);
}

void BitmapWriter::writePixel(struct pixel & pixel, FILE * file)
{
    fwrite(&pixel.blue, sizeof(byte), 1, file);
    fwrite(&pixel.green, sizeof(byte), 1, file);
    fwrite(&pixel.red, sizeof(byte), 1, file);
}

void BitmapWriter::writeBitmap(Bitmap & bitmap, const char * filePath)
{
    FILE * file = fopen(filePath, "wb");

    writeFileHeader(bitmap.fileheader, file);
    writeInfoHeader(bitmap.infoheader, file);
    
    byte zero = 0;
    
    for (int i = 0; i < bitmap.height; i++) {
        for (int j = 0; j < bitmap.width; j++)
            writePixel(bitmap.get(j, i), file);
        
        for (int j = 0; j < bitmap.paddingZeros; j++)
            fwrite(&zero, sizeof(byte), 1, file);
    }
    
    fclose(file);
}
