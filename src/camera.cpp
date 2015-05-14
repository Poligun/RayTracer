//
//  camera.cpp
//  RayTracer
//
//  Created by ZhaoYuhan on 4/20/15.
//  Copyright (c) 2015 ZhaoYuhan. All rights reserved.
//

#include "camera.h"
#include <chrono>

Color Camera::rayObject(const Object & object, Vector4 source, Vector4 direction, const std::vector<std::shared_ptr<Light>> & lights, int depth)
{
    Color color;
    
    auto intersection = object.getIntersection(source, direction);
    
    if (intersection && intersection->material) {
        color = intersection->material->ambientColor;
        
        for (auto it = lights.begin(); it != lights.end(); it++) {
            auto light = *it;

            Vector4 lightDirection = light->transformedLocation;
            lightDirection.subtract(intersection->location).normalize();

            if (intersection->normal.dotProduct(lightDirection) < 0.0)
                continue;

            Vector4 traceLocation = intersection->location;
            traceLocation.add(Vector4(intersection->normal).multiply(0.001));
            auto lightIntersection = object.getIntersection(traceLocation, lightDirection);
            
            if (!lightIntersection)
                color.add(light->shadeIntersection(*intersection, lightDirection));
            else
                delete lightIntersection;
        }
        
        if (depth > 0) {
            if (intersection->material->reflectivity > 0.0) {
                Vector4 *reflectionDirection = intersection->getReflectionDirection();
                Vector4 reflectionLocation = intersection->location;
                reflectionLocation.add(Vector4(intersection->normal).multiply(0.001));
                Color reflectionColor = rayObject(object, reflectionLocation, *reflectionDirection, lights, depth - 1);
                reflectionColor.multiply(intersection->material->reflectivity);
                color.add(reflectionColor);
                delete reflectionDirection;
            }
            
            if (intersection->material->refractivity > 0.0) {
                Vector4 *refractionDirection = intersection->getRefractionDirection();
                if (refractionDirection) {
                    Vector4 refractionLocation = intersection->location;
                    refractionLocation.subtract(Vector4(intersection->normal).multiply(0.001));
                    Color refractionColor = rayObject(object, refractionLocation, *refractionDirection, lights, depth - 1);
                    refractionColor.multiply(intersection->material->refractivity);
                    color.add(refractionColor);
                    delete refractionDirection;
                }
            }
        }

        delete intersection;
    }

    return color;
}

void Camera::rayScene(const Scene & scene, Bitmap & bitmap)
{
    double halfWidth = bitmap.width / 2.0;
    double halfHeight = bitmap.height / 2.0;
    
    auto startTime = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count();

    for (int i = 0; i < bitmap.height; i++) {
        printf("Scanning: %d/%d\n", i, bitmap.height);
        for (int j = 0; j < bitmap.width; j++) {
            double x = this->xyRatio * (j - halfWidth) / halfWidth;
            double y = (i - halfHeight) / halfHeight;

            Vector4 direction(this->location);
            direction.add(Vector4(this->xAxis).multiply(x));
            direction.add(Vector4(this->yAxis).multiply(y));
            direction.add(Vector4(this->zAxis).multiply(-this->focalLength));
            direction.subtract(this->location);
            direction.normalize();

            Color color = rayObject(scene.rootObject, this->location, direction, scene.lights, 3);
            //color.scale();

            auto pixel = bitmap.get(j, i);
            pixel.red   = color.r();
            pixel.green = color.g();
            pixel.blue  = color.b();
        }
    }

    auto endTime = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    double timeCost = (endTime - startTime) / 1000.0;
    
    printf("Time Cost: %lf\n", timeCost);
}
