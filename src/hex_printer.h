//
//  hex_printer.h
//  RayTracer
//
//  Created by ZhaoYuhan on 4/20/15.
//  Copyright (c) 2015 ZhaoYuhan. All rights reserved.
//

#ifndef __RayTracer__hex_printer__
#define __RayTracer__hex_printer__

#include <cstdio>

class HexPrinter
{
public:
    void printFile(const char * filePath, FILE * output);
};

#endif /* defined(__RayTracer__hex_printer__) */