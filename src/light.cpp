//
//  light.cpp
//  RayTracer
//
//  Created by ZhaoYuhan on 5/7/15.
//  Copyright (c) 2015 ZhaoYuhan. All rights reserved.
//

#include "light.h"

void Light::updateTransformMatrix(const Matrix4 & parentMatrix)
{
    Object::updateTransformMatrix(parentMatrix);
    this->transformedLocation = this->location;
    this->transformedLocation.multipliedBy(this->transformMatrix);
}


Color Light::shadeIntersection(const Intersection & intersection, const Vector4 & lightDirection)
{
    Color diffuseColor = Color(this->lightColor);
    diffuseColor.multiply(intersection.material->getDiffuse(intersection));
    diffuseColor.multiply(intersection.normal.dotProduct(lightDirection));
    return diffuseColor;
}
