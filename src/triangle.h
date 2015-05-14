//
//  triangle.h
//  RayTracer
//
//  Created by ZhaoYuhan on 5/5/15.
//  Copyright (c) 2015 ZhaoYuhan. All rights reserved.
//

#ifndef __RayTracer__triangle__
#define __RayTracer__triangle__

#include "geometry.h"

class TriangleGeometry : public Geometry
{
private:

public:
    Vector4 transformedVertices[3];
    Vector4 transformedVertexNormals[3];
    Vector4 transformedEdges[2];
    Vector4 transformedNormal;

    Vector4 vertices[3];
    Vector4 vertexNormals[3];
    bool hasVertexNormals = false;

    virtual void updateGeometry(const Matrix4 & transformMatrix);
    virtual Intersection * getIntersection(const Vector4 & source, const Vector4 & direction);
};

#endif /* defined(__RayTracer__triangle__) */
