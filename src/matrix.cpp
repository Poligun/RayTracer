//
//  matrix.cpp
//  RayTracer
//
//  Created by ZhaoYuhan on 4/20/15.
//  Copyright (c) 2015 ZhaoYuhan. All rights reserved.
//

#include "matrix.h"
#include <cmath>

void Matrix4::add(const Matrix4 & matrix)
{
    for (int i = 0; i < 16; i++)
        this->values[i] += matrix.values[i];
}

void Matrix4::multiply(const Matrix4 & matrix)
{
    double values[16] = {0.0};
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++)
                values[i * 4 + k] += this->values[i * 4 + j] * matrix.values[j * 4 + k];
        }
    }
    for (int i = 0; i < 16; i++)
        this->values[i] = values[i];
}

Matrix4 Matrix4::Identity()
{
    Matrix4 matrix;
    matrix.values[0] = matrix.values[5] = matrix.values[10] = matrix.values[15] = 1.0;
    return matrix;
}

Matrix4 Matrix4::Translation(double x, double y, double z)
{
    Matrix4 matrix = Matrix4::Identity();
    matrix.values[3]  = x;
    matrix.values[7]  = y;
    matrix.values[11] = z;
    return matrix;
}

Matrix4 Matrix4::Scaling(double x, double y, double z)
{
    Matrix4 matrix = Matrix4::Identity();
    matrix.values[0]  = x;
    matrix.values[5]  = y;
    matrix.values[10] = z;
    return matrix;
}

Matrix4 Matrix4::RotationX(double angle)
{
    Matrix4 matrix = Matrix4::Identity();
    matrix.values[5] = cos(angle);
    matrix.values[6] = -sin(angle);
    matrix.values[9] = sin(angle);
    matrix.values[10] = cos(angle);
    return matrix;
}

Matrix4 Matrix4::RotationY(double angle)
{
    Matrix4 matrix = Matrix4::Identity();
    matrix.values[0] = cos(angle);
    matrix.values[8] = -sin(angle);
    matrix.values[2] = sin(angle);
    matrix.values[10] = cos(angle);
    return matrix;
}

Matrix4 Matrix4::RotationZ(double angle)
{
    Matrix4 matrix = Matrix4::Identity();
    matrix.values[0] = cos(angle);
    matrix.values[1] = -sin(angle);
    matrix.values[4] = sin(angle);
    matrix.values[5] = cos(angle);
    return matrix;
}
