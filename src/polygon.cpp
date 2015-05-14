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
    triangle->vertices[0] = vertex1;
    triangle->vertices[1] = vertex2;
    triangle->vertices[2] = vertex3;
    this->triangles.push_back(triangle);
}

void PolygonGeometry::addTriangle(Vector4 vertex1, Vector4 vertex2, Vector4 vertex3, Vector4 normal1, Vector4 normal2, Vector4 normal3)
{
    auto triangle = std::make_shared<TriangleGeometry>();
    triangle->vertices[0] = vertex1;
    triangle->vertices[1] = vertex2;
    triangle->vertices[2] = vertex3;
    triangle->vertexNormals[0] = normal1;
    triangle->vertexNormals[1] = normal2;
    triangle->vertexNormals[2] = normal3;
    triangle->hasVertexNormals = true;
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
