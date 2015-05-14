//
//  bitmap_reader_test.h
//  RayTracer
//
//  Created by ZhaoYuhan on 5/13/15.
//  Copyright (c) 2015 ZhaoYuhan. All rights reserved.
//

#ifndef __RayTracer__bitmap_reader_test__
#define __RayTracer__bitmap_reader_test__

#include "test.h"

class BitmapReaderTest : public Test
{
public:
    const char * inputPath;
    const char * outputPath;

    virtual void run();
};

#endif /* defined(__RayTracer__bitmap_reader_test__) */
