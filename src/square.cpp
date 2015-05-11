//
//  square.cpp
//  RayTracer
//
//  Created by ZhaoYuhan on 5/9/15.
//  Copyright (c) 2015 ZhaoYuhan. All rights reserved.
//

#include "square.h"

SquareGeometry::SquareGeometry()
{
    double halfLength = this->length / 2.0;

    Vector4 vertices[] = {
        { -halfLength,  halfLength,  0.0 },
        {  halfLength,  halfLength,  0.0 },
        { -halfLength, -halfLength,  0.0 },
        {  halfLength, -halfLength,  0.0 }
    };
    
    PolygonGeometry::addTriangle(vertices[0], vertices[1], vertices[2]);
    PolygonGeometry::addTriangle(vertices[1], vertices[2], vertices[3]);
}
