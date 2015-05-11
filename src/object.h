//
//  object.h
//  RayTracer
//
//  Created by ZhaoYuhan on 5/8/15.
//  Copyright (c) 2015 ZhaoYuhan. All rights reserved.
//

#ifndef __RayTracer__object__
#define __RayTracer__object__

#include <memory>
#include <vector>
#include "geometry.h"
#include "material.h"

class Object
{
private:
    struct triple
    {
        double x = 0.0, y = 0.0, z = 0.0;
        inline void setAll(double v) { x = y = z = v; }
    };
    
public:
    
    std::shared_ptr<Geometry> geometry;
    std::shared_ptr<Material> material;
    std::vector<std::shared_ptr<Object>> subObjects;
    
    struct triple scale;
    struct triple rotate;
    struct triple translate;
    
    Object();
    
    void addObject(std::shared_ptr<Object> object)
    {
        subObjects.push_back(object);
    }
    
    Matrix4 transformMatrix;
    virtual void updateTransformMatrix(const Matrix4 & parentMatrix);
    Intersection * getIntersection(const Vector4 & source, const Vector4 & direction) const;
};

#endif /* defined(__RayTracer__object__) */
