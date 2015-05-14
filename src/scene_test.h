//
//  scene_test.h
//  RayTracer
//
//  Created by ZhaoYuhan on 5/13/15.
//  Copyright (c) 2015 ZhaoYuhan. All rights reserved.
//

#ifndef __RayTracer__scene_test__
#define __RayTracer__scene_test__

#include <vector>
#include <memory>
#include "test.h"

#include "scene.h"
#include "camera.h"
#include "renderer.h"

#include "object.h"
#include "object_loader.h"
#include "light.h"

class SceneTest : public Test
{
private:
    ObjectLoader objectLoader;

protected:
    double PI = 3.1415926535;

    std::shared_ptr<Scene> scene = std::make_shared<Scene>();
    std::shared_ptr<Camera> camera = std::make_shared<Camera>();
    std::shared_ptr<Renderer> renderer = std::make_shared<Renderer>();
    
    std::vector<std::shared_ptr<Object>> objects;
    
    std::shared_ptr<Object> addObject(Object * object);
    std::shared_ptr<Object> addObjectFromFile(const char * filePath);
    std::shared_ptr<Light> addLight(Light * light);
    
public:
    int outputWidth = 640;
    int outputHeight = 480;
    const char * outputPath = NULL;
    
    bool openOnFinish = true;

    virtual void run();
};

#endif /* defined(__RayTracer__scene_test__) */
