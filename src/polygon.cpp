//
//  polygon.cpp
//  RayTracer
//
//  Created by ZhaoYuhan on 5/8/15.
//  Copyright (c) 2015 ZhaoYuhan. All rights reserved.
//

#include "polygon.h"

void PolygonGeometry::addTriangle(Vector4 vertex1, Vector4 vertex2, Vector4 vertex3)
{
    auto triangle = std::make_shared<TriangleGeometry>();
    triangle->points[0] = vertex1;
    triangle->points[1] = vertex2;
    triangle->points[2] = vertex3;
    this->triangles.push_back(triangle);
}

void PolygonGeometry::updateGeometry(const Matrix4 & transformMatrix)
{
    for (auto it = this->triangles.begin(); it != this->triangles.end(); it++)
        (*it)->updateGeometry(transformMatrix);
}

Intersection * PolygonGeometry::getIntersection(const Vector4 & source, const Vector4 & direction)
{
    Intersection * intersection = NULL;
    
    for (auto it = this->triangles.begin(); it != this->triangles.end(); it++) {
        Intersection * subIntersection = (*it)->getIntersection(source, direction);
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
    
    return intersection;
}
