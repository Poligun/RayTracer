//
//  texture_material_test.cpp
//  RayTracer
//
//  Created by ZhaoYuhan on 5/18/15.
//  Copyright (c) 2015 ZhaoYuhan. All rights reserved.
//

#include "texture_material_test.h"
#include "texture_material.h"
#include "square.h"
#include "sphere.h"
#include "blinn_light.h"
#include "phong_light.h"

void TextureMaterialTest::run()
{
    auto texture = SceneTest::loadTexture("/Users/zhaoyuhan/Documents/tifa.bmp");

    auto material1 = std::make_shared<TextureMaterial>();
    material1->setAmbient(1.0, 0.0, 0.0);
    material1->setAmbientMap(*texture, 0.6);
    material1->setDiffuseMap(*texture, 0.5);
    material1->setDiffuse(0.4, 0.4, 0.4);
    
    double ratio = 1920.0 / 1080.0;
    
    auto material2 = std::make_shared<SimpleMaterial>();
    material2->setSpecular(0.5, 0.5, 0.5);
    material2->reflects = true;
    material2->refractiveIndex = 1.15;
    
    auto material3 = std::make_shared<SimpleMaterial>();
    material3->setAmbient(0.2, 0.2, 0.2);
    material3->setSpecular(0.2, 0.2, 0.2);
    material3->reflects = true;
    
    auto square1 = SceneTest::addObject(new Object());
    square1->geometry = std::make_shared<SquareGeometry>();
    square1->material = material3;
    square1->scale.setAll(3.0);
    square1->scale.x *= ratio;
    square1->rotate.x = -90 * PI / 180;
    square1->translate.y = -0.5;
    square1->translate.z = -1.1;
    
    auto sphere1 = SceneTest::addObject(new Object());
    sphere1->geometry = std::make_shared<SphereGeometry>();
    sphere1->material = material2;
    sphere1->scale.setAll(0.6);
    sphere1->translate.x = 0.75;
    sphere1->translate.y = 0.1;
    sphere1->translate.z = -1.5;
    
    auto square2 = SceneTest::addObject(new Object());
    square2->geometry = std::make_shared<SquareGeometry>();
    square2->material = material1;
    square2->scale.setAll(3.0);
    square2->scale.x *= ratio;
    square2->translate.y = 0.5;
    square2->translate.z = -2.1;

    auto light1 = SceneTest::addLight(new BlinnLight());
    light1->location.set(0.0, 0.0, 4.0);
    light1->lightColor.set(0.8, 0.8, 0.8);
    
    this->camera->location = {0.0, 0.3, 2.0};
    this->camera->focalLength = 2.0;
    
    SceneTest::run();
}
