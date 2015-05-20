//
//  texture_material.h
//  RayTracer
//
//  Created by ZhaoYuhan on 5/13/15.
//  Copyright (c) 2015 ZhaoYuhan. All rights reserved.
//

#ifndef __RayTracer__texture_material__
#define __RayTracer__texture_material__

#include <memory>
#include "simple_material.h"
#include "color.h"
#include "intersection.h"
#include "texture_map.h"


class TextureMaterial : public SimpleMaterial
{
private:
    std::shared_ptr<TextureMap> ambientMap;
    std::shared_ptr<TextureMap> diffuseMap;
    std::shared_ptr<TextureMap> specularMap;
    
public:
    void setAmbientMap(Bitmap & bitmap) { ambientMap = std::make_shared<TextureMap>(bitmap, 1.0); }
    void setDiffuseMap(Bitmap & bitmap) { diffuseMap = std::make_shared<TextureMap>(bitmap, 1.0); }
    void setSpecularMap(Bitmap & bitmap) { specularMap = std::make_shared<TextureMap>(bitmap, 1.0); }

    void setAmbientMap(Bitmap & bitmap, double weight) { ambientMap = std::make_shared<TextureMap>(bitmap, weight); }
    void setDiffuseMap(Bitmap & bitmap, double weight) { diffuseMap = std::make_shared<TextureMap>(bitmap, weight); }
    void setSpecularMap(Bitmap & bitmap, double weight) { specularMap = std::make_shared<TextureMap>(bitmap, weight); }
    
    void setDiffuseMapFromAmbient() { diffuseMap = ambientMap; }
    
    virtual Color getAmbient(const Intersection & intersection)
    {
        if (ambientMap)
            return ambientMap->getColor(intersection.textureCoordinate.x(), intersection.textureCoordinate.y());
        else
            return SimpleMaterial::getAmbient(intersection);
    }

    virtual Color getDiffuse(const Intersection & intersection)
    {
        if (diffuseMap)
            return diffuseMap->getColor(intersection.textureCoordinate.x(), intersection.textureCoordinate.y());
        else
            return SimpleMaterial::getDiffuse(intersection);
    }

    virtual Color getSpecular(const Intersection & intersection)
    {
        if (specularMap)
            return specularMap->getColor(intersection.textureCoordinate.x(), intersection.textureCoordinate.y());
        else
            return SimpleMaterial::getSpecular(intersection);
    }
};

#endif /* defined(__RayTracer__texture_material__) */
