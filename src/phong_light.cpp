//
//  phong_light.cpp
//  RayTracer
//
//  Created by ZhaoYuhan on 5/19/15.
//  Copyright (c) 2015 ZhaoYuhan. All rights reserved.
//

#include "phong_light.h"
#include <cmath>

Color PhongLight::shadeIntersection(const Intersection & intersection, const Vector4 & lightDirection)
{
    Color color = Light::shadeIntersection(intersection, lightDirection);
    
    Vector4 r = Vector4(intersection.normal).multiply(2.0 * intersection.normal.dotProduct(lightDirection));
    r.subtract(lightDirection);
    
    double power = pow(std::max(0.0, r.dotProduct(intersection.inversedRayDirection)), intersection.material->specularExponent);
    
    Color specularColor = Color(this->lightColor);
    specularColor.multiply(intersection.material->getSpecular(intersection));
    specularColor.multiply(power);
    
    color.add(specularColor);
    
    return color;
}
