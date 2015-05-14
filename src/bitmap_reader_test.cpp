//
//  bitmap_reader_test.cpp
//  RayTracer
//
//  Created by ZhaoYuhan on 5/13/15.
//  Copyright (c) 2015 ZhaoYuhan. All rights reserved.
//

#include "bitmap_reader_test.h"
#include "bitmap.h"
#include "bitmap_reader.h"
#include "bitmap_writer.h"

void BitmapReaderTest::run()
{
    BitmapReader reader;
    Bitmap * bitmap = reader.readBitmap(inputPath);
    BitmapWriter writer;
    writer.writeBitmap(*bitmap, outputPath);
    delete bitmap;
}
