//
//  geometry.h
//  RayTracer
//
//  Created by ZhaoYuhan on 4/20/15.
//  Copyright (c) 2015 ZhaoYuhan. All rights reserved.
//

#ifndef __RayTracer__geometry__
#define __RayTracer__geometry__

#include "matrix.h"
#include "intersection.h"

class Geometry
{
public:
    virtual void updateGeometry(const Matrix4 & transformMatrix) = 0;
    virtual Intersection * getIntersection(const Vector4 & source, const Vector4 & direction) = 0;
};

#endif /* defined(__RayTracer__geometry__) */
