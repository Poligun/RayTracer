//
//  main.cpp
//  RayTracer
//
//  Created by ZhaoYuhan on 4/20/15.
//  Copyright (c) 2015 ZhaoYuhan. All rights reserved.
//

#include <cstdio>
#include <memory>

#include "portal_gun_test.h"
#include "sphere_reflection_test.h"
#include "texture_material_test.h"
#include "table_scene_test.h"

int main(int argc, const char * argv[])
{
    auto test = std::make_shared<PortalGunTest>();
    
    test->outputPath = "/Users/zhaoyuhan/Documents/tmp.bmp";
    
    test->outputWidth = 1920;
    test->outputHeight = 1080;
    
    test->run();

    return 0;
}
