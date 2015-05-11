//
//  square.h
//  RayTracer
//
//  Created by ZhaoYuhan on 5/9/15.
//  Copyright (c) 2015 ZhaoYuhan. All rights reserved.
//

#ifndef __RayTracer__square__
#define __RayTracer__square__

#include "polygon.h"

class SquareGeometry : public PolygonGeometry
{
public:
    double length = 1.0;
    
    SquareGeometry();
};

#endif /* defined(__RayTracer__square__) */
