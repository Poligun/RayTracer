//
//  object_loader.h
//  RayTracer
//
//  Created by ZhaoYuhan on 5/8/15.
//  Copyright (c) 2015 ZhaoYuhan. All rights reserved.
//

#ifndef __RayTracer__object_loader__
#define __RayTracer__object_loader__

#include <cstdio>
#include <regex>
#include "object.h"

class ObjectLoader
{
private:
    std::regex vertexRegex = std::regex("^v [-+]?[0-9]*\\.?[0-9]+ [-+]?[0-9]*\\.?[0-9]+ [-+]?[0-9]*\\.?[0-9]+$");
    std::regex faceRegex = std::regex("^f [0-9]+ [0-9]+ [0-9]+$");
    std::regex faceWithTextureRegex = std::regex("^f [0-9]+/[0-9]+ [0-9]+/[0-9]+ [0-9]+/[0-9]+$");
    std::regex faceWithTextureAndNormalRegex = std::regex("^f [0-9]+/[0-9]+/[0-9]+ [0-9]+/[0-9]+/[0-9]+ [0-9]+/[0-9]+/[0-9]+$");

public:
    Object * loadObjectFile(const char * filePath) const;
};

#endif /* defined(__RayTracer__object_loader__) */
