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
    Color color = Light::shadeIntersection(intersection, lightDirection);
    
    Vector4 h = lightDirection;
    h.add(intersection.inversedRayDirection);
    h.normalize();
    
    double power = pow(std::max(0.0, intersection.normal.dotProduct(h)), intersection.material->specularExponent);
    
    Color specularColor = Color(this->lightColor);

    specularColor.multiply(intersection.material->getSpecular(intersection));
    specularColor.multiply(power);
    
    color.add(specularColor);
    return color;
}
