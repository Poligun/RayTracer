//
//  color.h
//  RayTracer
//
//  Created by ZhaoYuhan on 5/7/15.
//  Copyright (c) 2015 ZhaoYuhan. All rights reserved.
//

#ifndef __RayTracer__color__
#define __RayTracer__color__

class Color
{
private:
    inline int getIntegerValue(double doubleValue)
    {
        if (doubleValue <= 0)
            return 0;
        else if (doubleValue >= 1)
            return 255;
        else
            return (int) (doubleValue * 255);
    }
    
public:
    double red = 0.0;
    double green = 0.0;
    double blue = 0.0;
    double alpha = 1.0;
    
    void set(double red, double green, double blue)
    {
        this->red = red;
        this->green = green;
        this->blue = blue;
    }
    
    inline int r() { return getIntegerValue(red); }
    inline int g() { return getIntegerValue(green); }
    inline int b() { return getIntegerValue(blue); }
    inline int a() { return getIntegerValue(alpha); }
    
    void add(const Color & color);
    void multiply(double multiplier);
    void multiply(const Color & color);
    
    void scale();
};

#endif /* defined(__RayTracer__color__) */
