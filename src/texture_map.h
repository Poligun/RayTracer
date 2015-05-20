//
//  texture_map.h
//  RayTracer
//
//  Created by ZhaoYuhan on 5/18/15.
//  Copyright (c) 2015 ZhaoYuhan. All rights reserved.
//

#ifndef __RayTracer__texture_map__
#define __RayTracer__texture_map__

#include "bitmap.h"
#include "color.h"

class TextureMap
{
private:
    int width = 0;
    int height = 0;
    Color * textureColors = NULL;
    
    Color & getColor(int x, int y) { return textureColors[x * height + y]; }
    
public:
    Color getColor(double u, double v)
    {
        int x = u * width;
        int y = v * height;
        return textureColors[x * height + y];
    }
    
    TextureMap(Bitmap & bitmap, double weight)
    {
        width = bitmap.width;
        height = bitmap.height;
        
        textureColors = new Color[width * height];
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                struct pixel & pixel = bitmap.get(i, j);
                getColor(i, height - j - 1).set(pixel.red / 255.0, pixel.green / 255.0, pixel.blue / 255.0);
                getColor(i, height - j - 1).multiply(weight);
            }
        }
    }
    
    ~TextureMap()
    {
        delete[] textureColors;
    }
};

#endif /* defined(__RayTracer__texture_map__) */
