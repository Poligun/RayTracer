//
//  scene.cpp
//  RayTracer
//
//  Created by ZhaoYuhan on 4/20/15.
//  Copyright (c) 2015 ZhaoYuhan. All rights reserved.
//

#include "scene.h"

void Scene::prepareForRender()
{
    this->rootObject.updateTransformMatrix(Matrix4::Identity());
}
