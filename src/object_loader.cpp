//
//  object_loader.cpp
//  RayTracer
//
//  Created by ZhaoYuhan on 5/8/15.
//  Copyright (c) 2015 ZhaoYuhan. All rights reserved.
//

#include "object_loader.h"
#include "triangle.h"
#include "polygon.h"
#include <stdlib.h>
#include <string>

Object * ObjectLoader::loadObjectFile(const char * filePath) const
{

    std::vector<Vector4> vertices;
    std::vector<Vector4> vertexNormals;
    auto geometry = std::make_shared<PolygonGeometry>();
    double x, y, z;
    int v1, t1, v2, t2, v3, t3, n1, n2, n3;
    long numberOfFaces = 0;
    
    printf("Loading OBJ file: %s\n", filePath);
    
    FILE * file = fopen(filePath, "r");
    size_t bufferSize = 1024;
    char * buffer = (char *) malloc(sizeof(char) * bufferSize);
    char peek;
    
    while (true) {
        int i = 0;

        while (true) {
            if ((peek = fgetc(file)) == EOF)
                break;
            if (peek == '\n')
                break;
            if (i + 2 == bufferSize) {
                bufferSize *= 2;
                buffer = (char *) realloc(buffer, sizeof(char) * bufferSize);
            }
            buffer[i++] = peek;
        }
        buffer[i] = '\0';
        
        std::string line(buffer);
        
        if (std::regex_match(line, this->vertexRegex)) {
            sscanf(buffer, "v %lf %lf %lf", &x, &y, &z);
            vertices.push_back(Vector4(x, y, z, 1.0));
        }
        else if (std::regex_match(line, this->vertexNormalRegex)) {
            sscanf(buffer, "vn %lf %lf %lf", &x, &y, &z);
            vertexNormals.push_back(Vector4(x, y, z, 0.0));
        }
        else if (std::regex_match(line, this->faceRegex)) {
            sscanf(buffer, "f %d %d %d", &v1, &v2, &v3);
            geometry->addTriangle(vertices[v1 - 1], vertices[v2 - 1], vertices[v3 - 1]);
            auto last = geometry->triangles[geometry->triangles.size() - 1];
            numberOfFaces++;
        }
        else if (std::regex_match(line, this->faceWithTextureRegex)) {
            sscanf(buffer, "f %d/%d %d/%d %d/%d", &v1, &t1, &v2, &t2, &v3, &t3);
            geometry->addTriangle(vertices[v1 - 1], vertices[v2 - 1], vertices[v3 - 1]);
            numberOfFaces++;
        }
        else if (std::regex_match(line, this->faceWithNormalRegex)) {
            sscanf(buffer, "f %d//%d %d//%d %d//%d", &v1, &n1, &v2, &n2, &v3, &n3);
            geometry->addTriangle(vertices[v1 - 1], vertices[v2 - 1], vertices[v3 - 1],
                                  vertexNormals[n1 - 1], vertexNormals[n2 - 1], vertexNormals[n3 - 1]);
        }
        else if (std::regex_match(line, this->faceWithTextureAndNormalRegex)) {
            sscanf(buffer, "f %d/%d/%d %d/%d/%d %d/%d/%d", &v1, &t1, &n1, &v2, &t2, &n2, &v3, &t3, &n3);
            geometry->addTriangle(vertices[v1 - 1], vertices[v2 - 1], vertices[v3 - 1],
                                  vertexNormals[n1 - 1], vertexNormals[n2 - 1], vertexNormals[n3 - 1]);
            numberOfFaces++;
        }

        if (peek == EOF)
            break;
    }

    fclose(file);
    
    printf("Done\n");
    printf("Number of vertices: %ld\n", vertices.size());
    printf("Number of faces: %ld\n", numberOfFaces);
    
    
    Object * object = new Object();
    object->geometry = geometry;
    return object;
}
