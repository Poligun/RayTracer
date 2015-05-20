
//
//  sphere_reflection_test.cpp
//  RayTracer
//
//  Created by ZhaoYuhan on 5/13/15.
//  Copyright (c) 2015 ZhaoYuhan. All rights reserved.
//

#include "sphere_reflection_test.h"

#include "square.h"
#include "sphere.h"
#include "simple_material.h"
#include "blinn_light.h"

void SphereReflectionTest::run()
{
    auto box = SceneTest::addObject(new Object());
    box->scale.setAll(4.0);
    box->scale.z = 6.0;
    box->translate.z = -0.0;

    auto material1 = std::make_shared<SimpleMaterial>();
    material1->setAmbient(0.0, 0.0, 0.4);
    material1->setDiffuse(0.0, 0.0, 0.4);
    //material1->reflectivity = 0.3;

    auto square1 = std::make_shared<Object>();
    box->addObject(square1);
    square1->geometry = std::make_shared<SquareGeometry>();
    square1->material = material1;
    square1->rotate.y = 90 * PI / 180;
    square1->translate.x = -0.5;
    
    auto material2 = std::make_shared<SimpleMaterial>();
    material2->setAmbient(0.4, 0.0, 0.0);
    material2->setDiffuse(0.4, 0.4, 0.4);
    //material2->reflectivity = 0.3;
    
    auto square2 = std::make_shared<Object>();
    box->addObject(square2);
    square2->geometry = std::make_shared<SquareGeometry>();
    square2->material = material2;
    square2->rotate.y = -90 * PI / 180;
    square2->translate.x = 0.5;
    
    auto material6 = std::make_shared<SimpleMaterial>();
    material6->setAmbient(0.0, 0.4, 0.0);
    material6->setDiffuse(0.4, 0.4, 0.4);
    
    auto material7 = std::make_shared<SimpleMaterial>();
    material7->setAmbient(0.4, 0.4, 0.4);
    material7->setDiffuse(0.4, 0.4, 0.4);
    
    auto material3 = std::make_shared<SimpleMaterial>();
    material3->setAmbient(0.3, 0.3, 0.3);
    material3->setDiffuse(0.4, 0.4, 0.4);
    material3->setSpecular(0.2, 0.2, 0.0);
    //material3->reflects = true;
    //material3->reflectivity = 0.4;
    
    auto square3 = std::make_shared<Object>();
    box->addObject(square3);
    square3->geometry = std::make_shared<SquareGeometry>();
    square3->material = material3;
    square3->translate.z = -0.5;
    
    auto square4 = std::make_shared<Object>();
    box->addObject(square4);
    square4->geometry = std::make_shared<SquareGeometry>();
    square4->material = material7;
    square4->rotate.x = 90 * PI / 180;
    square4->translate.y = 0.5;
    
    auto square5 = std::make_shared<Object>();
    box->addObject(square5);
    square5->geometry = std::make_shared<SquareGeometry>();
    square5->material = material6;
    square5->rotate.x = -90 * PI / 180;
    square5->translate.y = -0.5;
    
    /*
    auto square6 = std::make_shared<Object>();
    box->addObject(square6);
    square6->geometry = std::make_shared<SquareGeometry>();
    square6->material = material3;
    square6->translate.z = 0.5;
    */
    
    
    auto material4 = std::make_shared<SimpleMaterial>();
    //material4->setDiffuse(0.3, 0.3, 0.3);
    //material4->setSpecular(0.2, 0.2, 0.2);
    //material4->reflectivity = 0.35;
    //material4->refractivity = 0.6;
    material4->reflects = true;
    material4->refractiveIndex = 1.75;
    
//    auto sphere1 = SceneTest::addObject(new Object());
//    sphere1->geometry = std::make_shared<SphereGeometry>();
//    sphere1->material = material4;
//    sphere1->scale.setAll(0.33);
//    sphere1->translate.y = -1.5;
    
    auto teapot = SceneTest::addObjectFromFile("/Users/zhaoyuhan/Documents/smooth_teapot.obj");
    teapot->material = material4;
    //teapot->scale.setAll(0.20);
    teapot->translate.y = -1.5;
    teapot->translate.z = -1.0;

    auto material5 = std::make_shared<SimpleMaterial>();
    material5->reflects = true;
    material5->refractiveIndex = 1.75;
    //material5->reflectivity = 0.35;
    
    auto sphere2 = SceneTest::addObject(new Object());
    sphere2->geometry = std::make_shared<SphereGeometry>();
    sphere2->material = material5;
    sphere2->scale.setAll(0.15);
    sphere2->translate.x = 0.5;
    sphere2->translate.y = -1.0;

//    auto teapot = SceneTest::addObjectFromFile("/Users/zhaoyuhan/Documents/smooth_teapot.obj");
//    teapot->material = material4;
//    teapot->scale.setAll(0.2);
//    teapot->translate.x = 0.8;
//    teapot->translate.y = -1.0;

    //auto sphere1 = SceneTest::addObjectFromFile("/Users/zhaoyuhan/Documents/sphere.obj");
    //sphere1->material = material4;
    

    
    auto light1 = SceneTest::addLight(new BlinnLight());
    light1->location.set(0.0, 0.0, 4.0);
    light1->lightColor.set(0.8, 0.8, 0.8);
    
    auto light2 = std::make_shared<BlinnLight>();
    light2->lightColor.set(0.5, 0.5, 0.0);
    square4->addObject(light2);
    this->scene->lights.push_back(light2);
    
    this->camera->location = {0.0, -1.0, 2.0};
    this->camera->focalLength = 2.0;
    
    SceneTest::run();
}
