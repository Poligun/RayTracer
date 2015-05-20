//
//  phong_light.h
//  RayTracer
//
//  Created by ZhaoYuhan on 5/19/15.
//  Copyright (c) 2015 ZhaoYuhan. All rights reserved.
//

#ifndef __RayTracer__phong_light__
#define __RayTracer__phong_light__

#include "light.h"

class PhongLight : public Light
{
public:
    virtual Color shadeIntersection(const Intersection & intersection, const Vector4 & lightDirection);
};

#endif /* defined(__RayTracer__phong_light__) */
