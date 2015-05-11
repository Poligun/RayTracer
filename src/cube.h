//
//  cube.h
//  RayTracer
//
//  Created by ZhaoYuhan on 5/9/15.
//  Copyright (c) 2015 ZhaoYuhan. All rights reserved.
//

#ifndef __RayTracer__cube__
#define __RayTracer__cube__

#include "polygon.h"

class CubeGeometry : public PolygonGeometry
{
public:
    double length = 1.0;
    
    CubeGeometry();
};

#endif /* defined(__RayTracer__cube__) */
