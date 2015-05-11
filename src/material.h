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

class Material
{
public:
    Color ambientColor;
    Color diffuseColor;
    Color specularColor;
    
    double reflectivity = 0.0;
    
    double refractivity = 0.0;
    double refractiveIndex = 1.0;
};

#endif /* defined(__RayTracer__material__) */
