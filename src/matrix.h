//
//  matrix.h
//  RayTracer
//
//  Created by ZhaoYuhan on 4/20/15.
//  Copyright (c) 2015 ZhaoYuhan. All rights reserved.
//

#ifndef __RayTracer__matrix__
#define __RayTracer__matrix__

class Matrix4
{
public:
    double values[16] = {0.0};
    
    void add(const Matrix4 & matrix);
    void multiply(const Matrix4 & matrix);
    
    static Matrix4 Identity();
    static Matrix4 Translation(double x, double y, double z);
    static Matrix4 Scaling(double x, double y, double z);
    static Matrix4 RotationX(double angle);
    static Matrix4 RotationY(double angle);
    static Matrix4 RotationZ(double angle);
};

#endif /* defined(__RayTracer__matrix__) */
