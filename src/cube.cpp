//
//  cube.cpp
//  RayTracer
//
//  Created by ZhaoYuhan on 5/9/15.
//  Copyright (c) 2015 ZhaoYuhan. All rights reserved.
//

#include "cube.h"

CubeGeometry::CubeGeometry()
{
    double halfLength = this->length / 2.0;
    Vector4 vertices[] = {
        {},
        { -halfLength,  halfLength,  halfLength },
        {  halfLength,  halfLength,  halfLength },
        { -halfLength, -halfLength,  halfLength },
        {  halfLength, -halfLength,  halfLength },
        
        { -halfLength,  halfLength, -halfLength },
        {  halfLength,  halfLength, -halfLength },
        { -halfLength, -halfLength, -halfLength },
        {  halfLength, -halfLength, -halfLength }
    };
    
    PolygonGeometry::addTriangle(vertices[3], vertices[1], vertices[2]);
    PolygonGeometry::addTriangle(vertices[3], vertices[2], vertices[4]);
    
    PolygonGeometry::addTriangle(vertices[7], vertices[5], vertices[1]);
    PolygonGeometry::addTriangle(vertices[7], vertices[1], vertices[3]);
    
    PolygonGeometry::addTriangle(vertices[4], vertices[2], vertices[6]);
    PolygonGeometry::addTriangle(vertices[4], vertices[6], vertices[8]);
    
    PolygonGeometry::addTriangle(vertices[8], vertices[6], vertices[5]);
    PolygonGeometry::addTriangle(vertices[8], vertices[5], vertices[7]);
    
    PolygonGeometry::addTriangle(vertices[1], vertices[5], vertices[6]);
    PolygonGeometry::addTriangle(vertices[1], vertices[6], vertices[2]);
    
    PolygonGeometry::addTriangle(vertices[7], vertices[3], vertices[4]);
    PolygonGeometry::addTriangle(vertices[7], vertices[4], vertices[8]);
}
