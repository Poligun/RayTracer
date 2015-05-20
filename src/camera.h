//
//  camera.h
//  RayTracer
//
//  Created by ZhaoYuhan on 4/20/15.
//  Copyright (c) 2015 ZhaoYuhan. All rights reserved.
//

#ifndef __RayTracer__camera__
#define __RayTracer__camera__

#include <memory>
#include "vector.h"
#include "material.h"
#include "scene.h"
#include "bitmap.h"
#include "color.h"

class Camera
{
private:
    struct result
    {
        double distance;
        Vector4 location;
        Vector4 normal;
        std::shared_ptr<Material> material;
    };
    
public:
    Vector4 location;
    Vector4 xAxis = {1.0, 0.0, 0.0, 0.0};
    Vector4 yAxis = {0.0, 1.0, 0.0, 0.0};
    Vector4 zAxis = {0.0, 0.0, 1.0, 0.0};
    
    double focalLength;
    double xyRatio = 1.0;
    
    void lookAt(Vector4 vertex);
    Color rayObject(const Object & object, const std::vector<std::shared_ptr<Light>> & lights, Vector4 source, Vector4 direction, double n1, int depth);
};

#endif /* defined(__RayTracer__camera__) */
