//
//  material.h
//  RayTracer
//
//  Created by ZhaoYuhan on 4/20/15.
//  Copyright (c) 2015 ZhaoYuhan. All rights reserved.
//

#ifndef __RayTracer__material__
#define __RayTracer__material__

#include "color.h"

class Intersection;

class Material
{
public:
    double specularExponent = 20.0;
    bool reflects = false;
    double refractiveIndex = 0.0001;
    
    virtual Color getAmbient(const Intersection & intersection) = 0;
    virtual Color getDiffuse(const Intersection & intersection) = 0;
    virtual Color getSpecular(const Intersection & intersection) = 0;
};

#endif /* defined(__RayTracer__material__) */
