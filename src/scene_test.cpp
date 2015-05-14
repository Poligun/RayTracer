//
//  scene_test.cpp
//  RayTracer
//
//  Created by ZhaoYuhan on 5/13/15.
//  Copyright (c) 2015 ZhaoYuhan. All rights reserved.
//

#include "scene_test.h"
#include <cstdlib>

std::shared_ptr<Object> SceneTest::addObject(Object * objectPointer)
{
    auto object = std::shared_ptr<Object>(objectPointer);
    scene->rootObject.addObject(object);
    return object;
}

std::shared_ptr<Object> SceneTest::addObjectFromFile(const char * filePath)
{
    return addObject(objectLoader.loadObjectFile(filePath));
}

std::shared_ptr<Light> SceneTest::addLight(Light * lightObject)
{
    auto light = std::shared_ptr<Light>(lightObject);
    scene->rootObject.addObject(light);
    scene->lights.push_back(light);
    return light;
}

void SceneTest::run()
{
    scene->prepareForRender();
    
    if (!outputPath) {
        printf("Error: output path not specified.\n");
        return;
    }

    renderer->scene = scene;
    renderer->camera = camera;
    renderer->outputPath = outputPath;
    renderer->numberOfThreads = 5;
    renderer->setResolution(outputWidth, outputHeight);
    renderer->render();
    
    if (openOnFinish) {
        char command[512];
        sprintf(command, "open %s", outputPath);
        system(command);
    }
}
