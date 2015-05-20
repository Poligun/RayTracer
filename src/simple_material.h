//
//  simple_material.h
//  RayTracer
//
//  Created by ZhaoYuhan on 5/13/15.
//  Copyright (c) 2015 ZhaoYuhan. All rights reserved.
//

#ifndef __RayTracer__simple_material__
#define __RayTracer__simple_material__

#include "material.h"

class SimpleMaterial : public Material
{
private:
    Color ambientColor;
    Color diffuseColor;
    Color specularColor;
    
public:
    void setAmbient(double red, double green, double blue )  { ambientColor.set(red, green, blue); }
    void setDiffuse(double red, double green, double blue )  { diffuseColor.set(red, green, blue); }
    void setSpecular(double red, double green, double blue ) { specularColor.set(red, green, blue); }

    virtual Color getAmbient(const Intersection & intersection)  { return ambientColor; }
    virtual Color getDiffuse(const Intersection & intersection)  { return diffuseColor; }
    virtual Color getSpecular(const Intersection & intersection) { return specularColor; }
};

#endif /* defined(__RayTracer__simple_material__) */
