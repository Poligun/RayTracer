//
//  light.h
//  RayTracer
//
//  Created by ZhaoYuhan on 5/7/15.
//  Copyright (c) 2015 ZhaoYuhan. All rights reserved.
//

#ifndef __RayTracer__light__
#define __RayTracer__light__

#include "object.h"

class Light : public Object
{
public:
    Vector4 location = {0.0, 0.0, 0.0, 1.0};
    Vector4 transformedLocation;
    Color lightColor;
    
    virtual void updateTransformMatrix(const Matrix4 & parentMatrix);
    virtual Color shadeIntersection(const Intersection & intersection, const Vector4 & lightDirection);
};

#endif /* defined(__RayTracer__light__) */
