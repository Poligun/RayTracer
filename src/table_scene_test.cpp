//
//  table_scene_test.cpp
//  RayTracer
//
//  Created by ZhaoYuhan on 5/19/15.
//  Copyright (c) 2015 ZhaoYuhan. All rights reserved.
//

#include "table_scene_test.h"
#include "bitmap_reader.h"
#include "texture_material.h"
#include "blinn_light.h"
#include "square.h"

void TableSceneTest::run()
{
    auto tableClothTexture = SceneTest::loadTexture("/Users/zhaoyuhan/Documents/test1.bmp");
    
    auto tableMaterial = std::make_shared<TextureMaterial>();
    tableMaterial->setAmbientMap(*tableClothTexture, 0.7);
    tableMaterial->setDiffuseMap(*tableClothTexture, 0.4);
    
    auto table = SceneTest::addObject(new Object());
    table->geometry = std::make_shared<SquareGeometry>();
    table->material = tableMaterial;
    table->scale.setAll(3.0);
    table->scale.x *= 4080.0 / 3116.0;
    table->rotate.x = -90 * PI / 180;
    table->translate.z = -1.0;
    
    auto teapotMaterial = std::make_shared<SimpleMaterial>();
    teapotMaterial->setAmbient(0.7, 0.7, 0.7);
    teapotMaterial->setDiffuse(0.4, 0.4, 0.4);
    teapotMaterial->setSpecular(0.3, 0.3, 0.3);
    teapotMaterial->reflects = true;
    teapotMaterial->refractiveIndex = 1.14;
    
    auto teapot = SceneTest::addObjectFromFile("/Users/zhaoyuhan/Documents/teapot.obj");
    teapot->material = teapotMaterial;
    teapot->scale.setAll(0.1);
    teapot->translate.z = -1.5;
    
    auto light1 = SceneTest::addLight(new BlinnLight());
    light1->location.set(0.0, 8.0, 4.0);
    light1->lightColor.set(0.8, 0.8, 0.8);
    
    this->camera->location = {0.0, 1.0, 0.5};
    this->camera->focalLength = 2.0;
    this->camera->lookAt(Vector4(0.0, 0.0, -1.0));
    
    SceneTest::run();
}
