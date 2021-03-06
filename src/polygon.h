//
//  polygon.h
//  RayTracer
//
//  Created by ZhaoYuhan on 5/8/15.
//  Copyright (c) 2015 ZhaoYuhan. All rights reserved.
//

#ifndef __RayTracer__polygon__
#define __RayTracer__polygon__

#include <vector>
#include "geometry.h"
#include "triangle.h"

class PolygonGeometry : public Geometry
{
private:

public:
    std::vector<std::shared_ptr<TriangleGeometry>> triangles;

    std::shared_ptr<TriangleGeometry> addTriangle(Vector4 vertex1, Vector4 vertex2, Vector4 vertex3);
    std::shared_ptr<TriangleGeometry> addTriangle(Vector4 vertex1, Vector4 vertex2, Vector4 vertex3, Vector4 normal1, Vector4 normal2, Vector4 normal3);
    std::shared_ptr<TriangleGeometry> addTriangle(Vector4 vertex1, Vector4 vertex2, Vector4 vertex3,
                     Vector4 normal1, Vector4 normal2, Vector4 normal3,
                     Vector4 textureCoordinate1, Vector4 textureCoordinate2, Vector4 textureCoordinate3);
    
    virtual void updateGeometry(const Matrix4 & transformMatrix);
    virtual Intersection * getIntersection(const Vector4 & source, const Vector4 & direction);
};

#endif /* defined(__RayTracer__polygon__) */
