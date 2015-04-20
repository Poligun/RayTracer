//
//  renderer.h
//  RayTracer
//
//  Created by ZhaoYuhan on 4/20/15.
//  Copyright (c) 2015 ZhaoYuhan. All rights reserved.
//

#ifndef __RayTracer__renderer__
#define __RayTracer__renderer__

#include <memory>
#include "scene.h"
#include "camera.h"

class Renderer
{
public:
    std::shared_ptr<Scene> scene;
    std::shared_ptr<Camera> camera;
    
    void render();
};

#endif /* defined(__RayTracer__renderer__) */