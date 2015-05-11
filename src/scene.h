//
//  scene.h
//  RayTracer
//
//  Created by ZhaoYuhan on 4/20/15.
//  Copyright (c) 2015 ZhaoYuhan. All rights reserved.
//

#ifndef __RayTracer__scene__
#define __RayTracer__scene__

#include <memory>
#include <vector>
#include "object.h"
#include "light.h"

class Scene
{
public:
    Object rootObject;
    std::vector<std::shared_ptr<Light>> lights;

    void prepareForRender();
};

#endif /* defined(__RayTracer__scene__) */
