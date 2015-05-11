//
//  main.cpp
//  RayTracer
//
//  Created by ZhaoYuhan on 4/20/15.
//  Copyright (c) 2015 ZhaoYuhan. All rights reserved.
//

#include <iostream>
#include <memory>
#include "triangle.h"
#include "sphere.h"
#include "square.h"
#include "cube.h"
#include "blinn_light.h"
#include "scene.h"
#include "camera.h"
#include "bitmap.h"
#include "bitmap_writer.h"
#include "object_loader.h"
#include "renderer.h"

int main(int argc, const char * argv[])
{
    double PI = 3.1415926535;
    
    auto material1 = std::make_shared<Material>();
    material1->ambientColor.set(0.4, 0.4, 0.4);
    material1->diffuseColor.set(0.5, 0.5, 0.5);
    material1->specularColor.set(0.3, 0.3, 0.3);
    //material->reflectivity = 0.6;
    //material->refractivity = 0.4;
    material1->refractiveIndex = 0.8;

    ObjectLoader loader;
    
    auto object1 = std::shared_ptr<Object>(loader.loadObjectFile("/Users/zhaoyuhan/Documents/teapot.obj"));
    object1->material = material1;
    object1->rotate.y = 40 * PI / 180;
    object1->scale.setAll(0.3);
    object1->translate.x = -0.2;
    object1->translate.z = -0.7;

    auto material2 = std::make_shared<Material>();
    material2->ambientColor.set(0.1, 0.1, 0.1);
    material2->reflectivity = 1.0;
    
    auto object2 = std::make_shared<Object>();
    object2->geometry = std::make_shared<SquareGeometry>();
    object2->material = material2;
    object2->scale.setAll(5.0);
    object2->rotate.x = 20 * PI / 180;
    object2->translate.z = -2.5;

    
    auto light = std::make_shared<BlinnLight>();
    light->location.set(0.0, 4.0, 1000.0);
    light->lightColor.set(0.6, 0.6, 0.5);
    
    auto light2 = std::make_shared<BlinnLight>();
    light2->location.set(1000.0, 1000.0, -1.0);
    light2->lightColor.set(0.5, 0.5, 0.0);
    
    auto scene = std::make_shared<Scene>();
    scene->rootObject.addObject(object1);
    scene->rootObject.addObject(object2);

    scene->rootObject.addObject(light);
    scene->rootObject.addObject(light2);
    
    scene->lights.push_back(light);
    scene->lights.push_back(light2);

    scene->prepareForRender();
    
    auto camera = std::make_shared<Camera>();
    camera->location = {0.0, 0.8, 2.0};
    camera->focalLength = 2.0;

    const char filePath[] = "/Users/zhaoyuhan/Documents/tmp.bmp";

    Renderer renderer;
    renderer.scene = scene;
    renderer.camera = camera;
    renderer.outputPath = filePath;
    renderer.numberOfThreads = 4;
    renderer.setResolution(1920 * 2, 1080 * 2);
    
    renderer.render();
    
    char command[512];
    sprintf(command, "open %s", filePath);
    system(command);

    return 0;
}
