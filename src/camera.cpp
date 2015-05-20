//
//  camera.cpp
//  RayTracer
//
//  Created by ZhaoYuhan on 4/20/15.
//  Copyright (c) 2015 ZhaoYuhan. All rights reserved.
//

#include "camera.h"
#include <cmath>

void Camera::lookAt(Vector4 vertex)
{
    this->zAxis = Vector4(this->location).subtract(vertex).normalize();
    this->xAxis = Vector4(this->yAxis).crossProduct(this->zAxis).normalize();
    this->yAxis = Vector4(this->zAxis).crossProduct(this->xAxis).normalize();
}

Color Camera::rayObject(const Object & object, const std::vector<std::shared_ptr<Light>> & lights, Vector4 source, Vector4 direction, double n1, int depth)
{
    Color color;
    
    auto intersection = object.getIntersection(source, direction);
    
    if (intersection && intersection->material) {
        color = intersection->material->getAmbient(*intersection);
        
        double n2 = intersection->material->refractiveIndex;
        if (intersection->inversedRayDirection.dotProduct(intersection->surfaceNormal) < 0.0)
            n2 = 1.0;
        double reflectivity = 1.0;
        double refractivity = 0.0;

        double cosThetaI = intersection->inversedRayDirection.dotProduct(intersection->normal);
        double thetaI = acos(cosThetaI);
        double sinThetaT = sin(thetaI) * n1 / n2;
        
        if (sinThetaT <= 1.0) {
            double cosThetaT = sqrt(1 - sinThetaT * sinThetaT);
            double Rs = pow((n1 * cosThetaI - n2 * cosThetaT) / (n1 * cosThetaI + n2 * cosThetaT), 2.0);
            double Rp = pow((n1 * cosThetaT - n2 * cosThetaI) / (n1 * cosThetaT + n2 * cosThetaI), 2.0);
            reflectivity = (Rs + Rp) / 2.0;
            refractivity = 1.0 - reflectivity;
        }
    
        Vector4 reflectionLocation = intersection->location;
        reflectionLocation.add(Vector4(intersection->normal).multiply(0.001));
        
        for (auto it = lights.begin(); it != lights.end(); it++) {
            auto light = *it;
            
            Vector4 lightDirection = light->transformedLocation;
            lightDirection.subtract(intersection->location).normalize();
            
            if (intersection->normal.dotProduct(lightDirection) < 0.0)
                continue;
    
            auto lightIntersection = object.getIntersection(reflectionLocation, lightDirection);
            
            if (!lightIntersection) {
                Color lightColor = light->shadeIntersection(*intersection, lightDirection);
                lightColor.multiply(reflectivity);
                color.add(lightColor);
            }
            else {
                delete lightIntersection;
            }
        }
        
        if (depth > 0 && intersection->material->reflects) {
            Vector4 reflectionDirection = intersection->normal;
            reflectionDirection.multiply(2.0 * intersection->normal.dotProduct(intersection->inversedRayDirection));
            reflectionDirection.subtract(intersection->inversedRayDirection);
            reflectionDirection.normalize();
            
            Color reflectionColor = rayObject(object, lights, reflectionLocation, reflectionDirection, n1, depth - 1);
            reflectionColor.multiply(reflectivity);
            color.add(reflectionColor);
            
            if (refractivity > 0.0) {
                Vector4 refractionDirection = intersection->normal;
                refractionDirection.multiply(cosThetaI * n1 / n2 - sqrt(1 - sinThetaT * sinThetaT));
                refractionDirection.subtract(Vector4(intersection->inversedRayDirection).multiply(n1 / n2));
                refractionDirection.normalize();
        
                Vector4 refractionLocation = intersection->location;
                refractionLocation.subtract(Vector4(intersection->normal).multiply(0.001));
                
                Color refractionColor = rayObject(object, lights, refractionLocation, refractionDirection, n2, depth - 1);
                refractionColor.multiply(refractivity);
                color.add(refractionColor);
            }
        }

        delete intersection;
    }

    return color;
}

