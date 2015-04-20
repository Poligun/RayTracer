//
//  main.cpp
//  RayTracer
//
//  Created by ZhaoYuhan on 4/20/15.
//  Copyright (c) 2015 ZhaoYuhan. All rights reserved.
//

#include <iostream>
#include "bitmap.h"
#include "bitmap_writer.h"
#include "hex_printer.h"

int main(int argc, const char * argv[])
{
    Bitmap bitmap(1920, 1080);
    BitmapWriter writer("/Users/zhaoyuhan/Documents/tmp.bmp");
    
    writer.writeBitmap(&bitmap);
    writer.close();

    return 0;
}
