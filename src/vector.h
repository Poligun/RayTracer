//
//  vector.h
//  RayTracer
//
//  Created by ZhaoYuhan on 4/20/15.
//  Copyright (c) 2015 ZhaoYuhan. All rights reserved.
//

#ifndef __RayTracer__vector__
#define __RayTracer__vector__

#include "matrix.h"

class Vector4
{
public:
    double values[4] = {0.0};

    inline double x() const { return values[0]; };
    inline double y() const { return values[1]; };
    inline double z() const { return values[2]; };
    inline double w() const { return values[3]; };

    Vector4()
    {
        
    }

    Vector4(double x, double y, double z)
    {
        this->set(x, y, z, 1.0);
    }
    
    Vector4(double x, double y, double z, double w)
    {
        this->set(x, y, z, w);
    }
    
    void set(double x, double y, double z)
    {
        values[0] = x;
        values[1] = y;
        values[2] = z;
    }
    
    void set(double x, double y, double z, double w)
    {
        values[0] = x;
        values[1] = y;
        values[2] = z;
        values[3] = w;
    }

    Vector4 & normalize();
    Vector4 & add(const Vector4 & vector);
    Vector4 & subtract(const Vector4 & vector);
    Vector4 & multiply(double multiplier);
    Vector4 & multipliedBy(const Matrix4 & matrix);
    
    double length() const;
    double dotProduct(const Vector4 & vector) const;
    Vector4 crossProduct(const Vector4 & vector) const;
};

#endif /* defined(__RayTracer__vector__) */
