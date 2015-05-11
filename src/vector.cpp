//
//  vector.cpp
//  RayTracer
//
//  Created by ZhaoYuhan on 4/20/15.
//  Copyright (c) 2015 ZhaoYuhan. All rights reserved.
//

#include "vector.h"
#include <cmath>

Vector4 & Vector4::normalize()
{
    double length = this->length();
    for (int i = 0; i < 3; i++)
        this->values[i] /= length;
    return *this;
}

Vector4 & Vector4::add(const Vector4 & vector)
{
    for (int i = 0; i < 4; i++)
        this->values[i] += vector.values[i];
    return *this;
}

Vector4 & Vector4::subtract(const Vector4 & vector)
{
    for (int i = 0; i < 4; i++)
        this->values[i] -= vector.values[i];
    return *this;
}

Vector4 & Vector4::multiply(double multiplier)
{
    for (int i = 0; i < 4; i++)
        this->values[i] *= multiplier;
    return *this;
}

Vector4 & Vector4::multipliedBy(const Matrix4 & matrix)
{
    double values[4] = {0.0};
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++)
            values[i] += matrix.values[i * 4 + j] * this->values[j];
    }
    for (int i = 0; i < 4; i++)
        this->values[i] = values[i];
    return *this;
}

double Vector4::length() const
{
    double sum = 0.0;
    for (int i = 0; i < 4; i++)
        sum += this->values[i] * this->values[i];
    return sqrt(sum);
}

double Vector4::dotProduct(const Vector4 & vector) const
{
    double product = 0.0;
    for (int i = 0; i < 4; i++)
        product += this->values[i] * vector.values[i];
    return product;
}

Vector4 Vector4::crossProduct(const Vector4 & vector) const
{
    Vector4 product;
    
    product.values[0] = this->values[1] * vector.values[2] - this->values[2] * vector.values[1];
    product.values[1] = this->values[2] * vector.values[0] - this->values[0] * vector.values[2];
    product.values[2] = this->values[0] * vector.values[1] - this->values[1] * vector.values[0];
    product.values[3] = 0.0;
    
    return product;
}