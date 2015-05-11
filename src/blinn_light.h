//
//  blinn_light.h
//  RayTracer
//
//  Created by ZhaoYuhan on 5/8/15.
//  Copyright (c) 2015 ZhaoYuhan. All rights reserved.
//

#ifndef __RayTracer__blinn_light__
#define __RayTracer__blinn_light__

#include "light.h"

class BlinnLight : public Light
{
public:
    double blinnPowerCoefficient = 30.0;
    
    virtual Color shadeIntersection(const Intersection & intersection, const Vector4 & lightDirection);
};

#endif /* defined(__RayTracer__blinn_light__) */
