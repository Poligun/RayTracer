//
//  portal_gun_test.cpp
//  RayTracer
//
//  Created by ZhaoYuhan on 5/13/15.
//  Copyright (c) 2015 ZhaoYuhan. All rights reserved.
//

#include "portal_gun_test.h"
#include "object_loader.h"

#include "simple_material.h"
#include "blinn_light.h"
#include "square.h"

void PortalGunTest::run()
{
    auto material1 = std::make_shared<SimpleMaterial>();
    material1->setAmbient(0.3, 0.3, 0.3);
    material1->setDiffuse(0.15, 0.15, 0.15);
    material1->setSpecular(0.15, 0.15, 0.15);
    material1->reflects = true;
    material1->refractiveIndex = 1.22;
    
    auto material2 = std::make_shared<SimpleMaterial>();
    material2->setAmbient(0.1, 0.1, 0.1);
    material1->reflects = true;
    
    auto object1 = SceneTest::addObjectFromFile("/Users/zhaoyuhan/Documents/smooth_portal.obj");
    object1->material = material1;
    object1->rotate.y = 40 * PI / 180;
    object1->scale.setAll(1.0);
    object1->translate.x = -0.2;
    object1->translate.z = -0.7;
    
    auto object2 = SceneTest::addObject(new Object());
    object2->geometry = std::make_shared<SquareGeometry>();
    object2->material = material2;
    object2->scale.setAll(5.0);
    object2->scale.y = 30.0;
    object2->rotate.x = 2 * PI / 180;
    object2->translate.z = -2.5;
    
    auto object3 = SceneTest::addObject(new Object());
    object3->geometry = std::make_shared<SquareGeometry>();
    object3->material = material2;
    object3->scale.setAll(5.0);
    object3->scale.y = 30.0;
    object3->rotate.x = -2 * PI / 180;
    object3->translate.z = 4.0;
    
    auto light1 = SceneTest::addLight(new BlinnLight());
    light1->location.set(0.0, 4.0, 1000.0);
    light1->lightColor.set(0.5, 0.5, 0.5);
    
    auto light2 = SceneTest::addLight(new BlinnLight());
    light2->location.set(1000.0, 1000.0, -1.0);
    light2->lightColor.set(0.5, 0.5, 0.3);
    
    this->camera->location = {0.0, 0.0, 2.0};
    this->camera->focalLength = 2.0;
    
    SceneTest::run();
}
