//
//  sphere.h
//  RayTracer
//
//  Created by ZhaoYuhan on 5/8/15.
//  Copyright (c) 2015 ZhaoYuhan. All rights reserved.
//

#ifndef __RayTracer__sphere__
#define __RayTracer__sphere__

#include "geometry.h"

class SphereGeometry : public Geometry
{
private:
    Vector4 transformedCenter;
    double transformedRadius;
    
public:
    double radius = 1.0;
    
    virtual void updateGeometry(const Matrix4 & transformMatrix);
    virtual Intersection * getIntersection(const Vector4 & source, const Vector4 & direction);
};

#endif /* defined(__RayTracer__sphere__) */
