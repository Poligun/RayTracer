//
//  mesh.h
//  RayTracer
//
//  Created by ZhaoYuhan on 4/20/15.
//  Copyright (c) 2015 ZhaoYuhan. All rights reserved.
//

#ifndef __RayTracer__mesh__
#define __RayTracer__mesh__

#include <memory>
#include <vector>
#include "geometry.h"
#include "material.h"
#include "matrix.h"

class Mesh
{
private:
    Matrix4 translation;
    Matrix4 scale;
    Matrix4 rotation;
    
    std::vector<std::shared_ptr<Mesh>> meshes;
    
public:
    std::shared_ptr<Geometry> geometry;
    std::shared_ptr<Material> material;
};

#endif /* defined(__RayTracer__mesh__) */
