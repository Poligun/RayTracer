//
//  sphere.cpp
//  RayTracer
//
//  Created by ZhaoYuhan on 5/8/15.
//  Copyright (c) 2015 ZhaoYuhan. All rights reserved.
//

#include "sphere.h"
#include <cmath>

void SphereGeometry::updateGeometry(const Matrix4 & transformMatrix)
{
    Vector4 transformedPoint = {this->radius, 0.0, 0.0, 1.0};
    transformedPoint.multipliedBy(transformMatrix);
    this->transformedCenter = {0.0, 0.0, 0.0, 1.0};
    this->transformedCenter.multipliedBy(transformMatrix);
    transformedPoint.subtract(this->transformedCenter);
    this->transformedRadius = transformedPoint.length();
}

Intersection * SphereGeometry::getIntersection(const Vector4 & source, const Vector4 & direction)
{
    Vector4 u = Vector4(source).subtract(this->transformedCenter);
    Vector4 v = direction;
    
    float a = 1.0;
    float b = 2.0 * u.dotProduct(v);
    float c = u.dotProduct(u) - pow(this->transformedRadius, 2.0);
    float delta = b * b - 4.0 * a * c;
    
    if (delta < 0.0)
        return NULL;
    
    float root1 = (-b - sqrt(delta)) / (2.0 * a);
    float root2 = (-b + sqrt(delta)) / (2.0 * a);
    
    if (root2 < 0.0)
        return NULL;
    
    float root = (root1 > 0.0) ? root1 : root2;
    
    Intersection * intersection = new Intersection();

    intersection->distance = root;

    intersection->location = source;
    intersection->location.add(Vector4(direction).multiply(root));

    intersection->surfaceNormal = Vector4(intersection->location).subtract(this->transformedCenter);
    intersection->surfaceNormal.normalize();
    intersection->inversedRayDirection = Vector4(direction).multiply(-1);
    
    intersection->normal = intersection->surfaceNormal;
    if (intersection->inversedRayDirection.dotProduct(intersection->normal) < 0.0)
        intersection->normal.multiply(-1.0);

    return intersection;
}
