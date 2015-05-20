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
    
    auto triangle1 = PolygonGeometry::addTriangle(vertices[1], vertices[0], vertices[2]);
    auto triangle2 = PolygonGeometry::addTriangle(vertices[1], vertices[2], vertices[3]);
    
    triangle1->textureCoordinates[0].set(1.0, 0.0, 0.0);
    triangle1->textureCoordinates[1].set(0.0, 0.0, 0.0);
    triangle1->textureCoordinates[2].set(0.0, 1.0, 0.0);
    triangle1->hasTextureCoordinates = true;
    
    triangle2->textureCoordinates[0].set(1.0, 0.0, 0.0);
    triangle2->textureCoordinates[1].set(0.0, 1.0, 0.0);
    triangle2->textureCoordinates[2].set(1.0, 1.0, 0.0);
    triangle2->hasTextureCoordinates = true;
}
