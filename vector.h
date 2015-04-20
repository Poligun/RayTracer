//
//  vector.h
//  RayTracer
//
//  Created by ZhaoYuhan on 4/20/15.
//  Copyright (c) 2015 ZhaoYuhan. All rights reserved.
//

#ifndef __RayTracer__vector__
#define __RayTracer__vector__

class Vector4
{
private:
    double values[4] = {0.0, 0.0, 0.0, 0.0};
    
public:
    inline double & x() { return values[0]; };
    inline double & y() { return values[1]; };
    inline double & z() { return values[2]; };
    inline double & w() { return values[3]; };

};

#endif /* defined(__RayTracer__vector__) */
