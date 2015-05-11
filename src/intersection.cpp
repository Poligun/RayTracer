//
//  intersection.cpp
//  RayTracer
//
//  Created by ZhaoYuhan on 5/8/15.
//  Copyright (c) 2015 ZhaoYuhan. All rights reserved.
//

#include "intersection.h"
#include <cmath>

Vector4 * Intersection::getReflectionDirection() const
{
    Vector4 * direction = new Vector4(this->normal);
    direction->multiply(2.0 * this->normal.dotProduct(this->inversedRayDirection));
    direction->subtract(this->inversedRayDirection);
    return direction;
}

Vector4 * Intersection::getRefractionDirection() const
{
    double cosT1 = this->normal.dotProduct(this->inversedRayDirection);
    double sinT2 = pow(this->material->refractiveIndex, 2.0) * (1.0 - pow(cosT1, 2.0));
    
    if (sinT2 > 1.0)
        return NULL;
    
    Vector4 * direction = new Vector4(this->inversedRayDirection);
    direction->multiply(- this->material->refractiveIndex);
    direction->add(Vector4(this->normal).multiply(this->material->refractiveIndex * cosT1 - sqrt(1.0 - sinT2)));
    
    return direction;
}
