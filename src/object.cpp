//
//  object.cpp
//  RayTracer
//
//  Created by ZhaoYuhan on 5/8/15.
//  Copyright (c) 2015 ZhaoYuhan. All rights reserved.
//

#include "object.h"

Object::Object()
{
    this->scale.setAll(1.0);
    this->rotate.setAll(0.0);
    this->translate.setAll(0.0);
}

void Object::updateTransformMatrix(const Matrix4 & parentMatrix)
{
    this->transformMatrix = parentMatrix;
    
    this->transformMatrix.multiply(Matrix4::Translation(this->translate.x, this->translate.y, this->translate.z));
    this->transformMatrix.multiply(Matrix4::RotationZ(this->rotate.z));
    this->transformMatrix.multiply(Matrix4::RotationY(this->rotate.y));
    this->transformMatrix.multiply(Matrix4::RotationX(this->rotate.x));
    
    this->transformMatrix.multiply(Matrix4::Scaling(this->scale.x, this->scale.y, this->scale.z));
    
    if (this->geometry)
        this->geometry->updateGeometry(this->transformMatrix);
    
    for (auto it = this->subObjects.begin(); it != this->subObjects.end(); it++)
        (*it)->updateTransformMatrix(transformMatrix);
}

Intersection * Object::getIntersection(const Vector4 & source, const Vector4 & direction) const
{
    Intersection * intersection = NULL;
    
    if (this->geometry)
        intersection = this->geometry->getIntersection(source, direction);
    
    for (auto it = this->subObjects.begin(); it != this->subObjects.end(); it++) {
        Intersection *subIntersection = (*it)->getIntersection(source, direction);
        if (!subIntersection)
            continue;
        if (!intersection || subIntersection->distance < intersection->distance) {
            if (!intersection)
                intersection = new Intersection(*subIntersection);
            else
                *intersection = *subIntersection;
        }
        delete subIntersection;
    }
    
    if (intersection && this->material)
        intersection->material = this->material;
    
    return intersection;
}