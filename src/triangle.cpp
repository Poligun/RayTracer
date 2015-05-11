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
        this->transformedPoints[i] = this->points[i];
        this->transformedPoints[i].multipliedBy(transformMatrix);
    }
    
    this->transformedEdges[0] = this->transformedPoints[1];
    this->transformedEdges[0].subtract(this->transformedPoints[0]);
    this->transformedEdges[1] = this->transformedPoints[2];
    this->transformedEdges[1].subtract(this->transformedPoints[0]);
    
    this->transformedNormal = this->transformedEdges[0].crossProduct(this->transformedEdges[1]);
    this->transformedNormal.normalize(); 
}

//Intersection * TriangleGeometry::getIntersection(const Vector4 & source, const Vector4 & direction)
//{
//    double denominator = this->transformedNormal.dotProduct(direction);
//    if (fabs(denominator) < 0.0001)
//        return NULL;
//    
//    double numerator = this->transformedNormal.dotProduct(this->transformedPoints[0]) - this->transformedNormal.dotProduct(source);
//    double dist = numerator / denominator;
//    if (dist < 0.0)
//        return NULL;
//    
//    Vector4 location = source;
//    location.add(Vector4(direction).multiply(dist));
//    
//    Vector4 u = this->transformedEdges[0];
//    Vector4 v = this->transformedEdges[1];
//    Vector4 w = Vector4(location).subtract(this->transformedPoints[0]);
//    
//    double dotUV = u.dotProduct(v);
//    double dotWU = w.dotProduct(u);
//    double dotWV = w.dotProduct(v);
//    double dotVV = v.dotProduct(v);
//    double dotUU = u.dotProduct(u);
//    
//    double d = 1.0 / (dotUV * dotUV - dotUU * dotVV);
//    double s = (dotUV * dotWV - dotVV * dotWU) * d;
//    double t = (dotUV * dotWU - dotUU * dotWV) * d;
//    
//    if (s < 0.0 || s > 1.0)
//        return NULL;
//    
//    if (t < 0.0 || t > 1.0)
//        return NULL;
//    
//    if (s + t > 1.0)
//        return NULL;
//    
//    Intersection * intersection = new Intersection();
//    
//    intersection->distance = dist;
//    intersection->location = location;
//    
//    intersection->inversedRayDirection = Vector4(direction).multiply(-1.0);
//    intersection->normal = this->transformedNormal;
//    if (intersection->inversedRayDirection.dotProduct(intersection->normal) < 0.0)
//        intersection->normal.multiply(-1.0);
//    
//    return intersection;
//}

Intersection * TriangleGeometry::getIntersection(const Vector4 & source, const Vector4 & direction)
{
    //Ray intersection with Triangle from DirectX SDK Demo
    Vector4 E1 = this->transformedEdges[0];
    Vector4 E2 = this->transformedEdges[1];
    Vector4 P  = direction.crossProduct(E2);
    double det = E1.dotProduct(P);
    
    Vector4 T;
    if (det > 0) {
        T = Vector4(source).subtract(this->transformedPoints[0]);
    }
    else {
        T = Vector4(this->transformedPoints[0]).subtract(source);
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
    
    Vector4 location = this->transformedPoints[0];
    location.add(Vector4(this->transformedEdges[0]).multiply(u));
    location.add(Vector4(this->transformedEdges[1]).multiply(v));
    
    intersection->inversedRayDirection = Vector4(direction).multiply(-1.0);
    intersection->normal = this->transformedNormal;
    if (intersection->inversedRayDirection.dotProduct(intersection->normal) < 0.0)
        intersection->normal.multiply(-1.0);
    
    return intersection;
}
