//
//  color.cpp
//  RayTracer
//
//  Created by ZhaoYuhan on 5/7/15.
//  Copyright (c) 2015 ZhaoYuhan. All rights reserved.
//

#include "color.h"
#include <cmath>

void Color::add(const Color & color)
{
    this->red += color.red;
    this->green += color.green;
    this->blue += color.blue;
}

void Color::multiply(double multiplier)
{
    this->red *= multiplier;
    this->green *= multiplier;
    this->blue *= multiplier;
}


void Color::multiply(const Color & color)
{
    this->red *= color.red;
    this->green *= color.green;
    this->blue *= color.blue;
}

void Color::scale()
{
    this->red = sqrt(this->red);
    this->green = sqrt(this->green);
    this->blue = sqrt(this->blue);
}
