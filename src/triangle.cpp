//
//  triangle.cpp
//  RayTracer
//
//  Created by ZhaoYuhan on 5/5/15.
//  Copyright (c) 2015 ZhaoYuhan. All rights reserved.
//

#include "triangle.h"
#include <cmath>
#define EPSILON 0.00001

void TriangleGeometry::updateGeometry(const Matrix4 & transformMatrix)
{
    for (int i = 0; i < 3; i++) {
        this->transformedVertices[i] = this->vertices[i];
        this->transformedVertices[i].multipliedBy(transformMatrix);
        if (this->hasVertexNormals) {
            this->transformedVertexNormals[i] = this->vertexNormals[i];
            this->transformedVertexNormals[i].multipliedBy(transformMatrix);
        }
    }
    
    this->transformedEdges[0] = this->transformedVertices[1];
    this->transformedEdges[0].subtract(this->transformedVertices[0]);
    this->transformedEdges[1] = this->transformedVertices[2];
    this->transformedEdges[1].subtract(this->transformedVertices[0]);
    
    this->transformedNormal = this->transformedEdges[0].crossProduct(this->transformedEdges[1]);
    this->transformedNormal.normalize(); 
}

Intersection * TriangleGeometry::getIntersection(const Vector4 & source, const Vector4 & direction)
{
    //Ray intersection with Triangle from DirectX SDK Demo
    Vector4 E1 = this->transformedEdges[0];
    Vector4 E2 = this->transformedEdges[1];
    Vector4 P  = direction.crossProduct(E2);
    double det = E1.dotProduct(P);
    
    Vector4 T;
    if (det > 0) {
        T = Vector4(source).subtract(this->transformedVertices[0]);
    }
    else {
        T = Vector4(this->transformedVertices[0]).subtract(source);
        det = -det;
    }
    
    if (det < 0.0001)
        return NULL;
    
    double t, u, v;
    
    u = T.dotProduct(P);
    if (u < 0.0 || u > det)
        return NULL;
    
    Vector4 Q = T.crossProduct(E1);
    v = direction.dotProduct(Q);
    if (v < 0.0 || u + v > det)
        return NULL;
    
    t = E2.dotProduct(Q);
    if (t < 0.0001)
        return NULL;
    
    double inversedDet = 1.0 / det;
    t *= inversedDet;
    u *= inversedDet;
    v *= inversedDet;
    
    Intersection * intersection = new Intersection();
    
    intersection->distance = t;
    intersection->location = source;
    intersection->location.add(Vector4(direction).multiply(t));
    
    intersection->u = u;
    intersection->v = v;
    
    if (this->hasVertexNormals) {
        intersection->computedNormal = Vector4(this->transformedVertexNormals[0]).multiply(1 - u - v);
        intersection->computedNormal.add(Vector4(this->transformedVertexNormals[1]).multiply(u));
        intersection->computedNormal.add(Vector4(this->transformedVertexNormals[2]).multiply(v));
        intersection->computedNormal.normalize();
        intersection->normal = intersection->computedNormal;
    }
    else {
        intersection->normal = this->transformedNormal;
    }
    
    Vector4 location = this->transformedVertices[0];
    location.add(Vector4(this->transformedEdges[0]).multiply(u));
    location.add(Vector4(this->transformedEdges[1]).multiply(v));
    
    intersection->inversedRayDirection = Vector4(direction).multiply(-1.0);
    if (intersection->inversedRayDirection.dotProduct(intersection->normal) < 0.0)
        intersection->normal.multiply(-1.0);
    
    return intersection;
}
