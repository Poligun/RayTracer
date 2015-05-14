//
//  intersection.h
//  RayTracer
//
//  Created by ZhaoYuhan on 5/8/15.
//  Copyright (c) 2015 ZhaoYuhan. All rights reserved.
//

#ifndef __RayTracer__intersection__
#define __RayTracer__intersection__

#include <memory>
#include "vector.h"
#include "material.h"

class Intersection
{
public:
    double distance;
    double u, v;
    Vector4 location;
    Vector4 normal;
    Vector4 computedNormal; // This is the surface normal interpolated by location & vertex normals.
    Vector4 inversedRayDirection;
    std::shared_ptr<Material> material;
    
    Vector4 * getReflectionDirection() const;
    Vector4 * getRefractionDirection() const;
};

#endif /* defined(__RayTracer__intersection__) */
