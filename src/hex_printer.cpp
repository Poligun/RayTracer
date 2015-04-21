//
//  hex_printer.cpp
//  RayTracer
//
//  Created by ZhaoYuhan on 4/20/15.
//  Copyright (c) 2015 ZhaoYuhan. All rights reserved.
//

#include "hex_printer.h"

void HexPrinter::printFile(const char * filePath, FILE * output)
{
    FILE * input = fopen(filePath, "rb");
    size_t bytesRead;
    unsigned char buffer[256];
    
    while ((bytesRead = fread(buffer, sizeof(unsigned char), 256, input)) > 0) {
        for (int i = 0; i < bytesRead; i++) {
            fprintf(output, "%.2x ", buffer[i]);
        }
    }
    
    fclose(input);
}
