//
//  blinn_light.cpp
//  RayTracer
//
//  Created by ZhaoYuhan on 5/8/15.
//  Copyright (c) 2015 ZhaoYuhan. All rights reserved.
//

#include "blinn_light.h"
#include <cmath>

Color BlinnLight::shadeIntersection(const Intersection & intersection, const Vector4 & lightDirection)
{
    Color color;
    
    Color diffuseColor = Color(this->lightColor);
    diffuseColor.multiply(intersection.material->diffuseColor);
    diffuseColor.multiply(intersection.normal.dotProduct(lightDirection));
    
    Vector4 h = lightDirection;
    h.add(intersection.inversedRayDirection);
    h.normalize();
    
    double power = pow(std::max(0.0, intersection.normal.dotProduct(h)), this->blinnPowerCoefficient);
    
    Color specularColor = Color(this->lightColor);
    specularColor.multiply(intersection.material->specularColor);
    specularColor.multiply(power);
    
    color.add(diffuseColor);
    color.add(specularColor);
    
    return color;
}
