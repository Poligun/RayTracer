//
//  renderer.cpp
//  RayTracer
//
//  Created by ZhaoYuhan on 4/20/15.
//  Copyright (c) 2015 ZhaoYuhan. All rights reserved.
//

#include "renderer.h"
#include <pthread.h>
#include <chrono>
#include "bitmap.h"
#include "bitmap_writer.h"

struct job
{
    int startingY;
    int endingY;
    
    double halfWidth;
    double halfHeight;
    
    int numberOfRecursions;
    
    std::shared_ptr<Scene> scene;
    std::shared_ptr<Camera> camera;
    std::shared_ptr<Bitmap> bitmap;
};

void * RenderScene(void * message);

void Renderer::render()
{
    if (!this->scene || !this->camera) {
        printf("Error: Scene or camera not given.\n");
        return;
    }
    
    if (!this->outputPath) {
        printf("Error: Output path not given.\n");
        return;
    }
    
    auto startTime = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count();

    printf("Preparing for rendering.\n");

    std::shared_ptr<Bitmap> bitmap = std::make_shared<Bitmap>(this->width, this->height);
    double halfWidth  = this->width  / 2.0;
    double halfHeight = this->height / 2.0;
    this->camera->xyRatio = halfWidth / halfHeight;
    
    struct job * jobs = new struct job[this->numberOfThreads];
    
    int numberOfLines = this->height / this->numberOfThreads;
    int endingY = 0;
    for (int i = 0; i < this->numberOfThreads; i++) {
        jobs[i].startingY = endingY;
        jobs[i].endingY = jobs[i].startingY + numberOfLines;
        jobs[i].halfWidth = halfWidth;
        jobs[i].halfHeight = halfHeight;
        jobs[i].numberOfRecursions = this->numberOfRecursions;
        jobs[i].scene = this->scene;
        jobs[i].camera = this->camera;
        jobs[i].bitmap = bitmap;
        endingY = jobs[i].endingY;
    }
    jobs[this->numberOfThreads - 1].endingY = this->height;
    
    pthread_t * threads = new pthread_t[this->numberOfThreads];
    
    printf("Creating %d thread(s) for rendering.\n", this->numberOfThreads);
    for (int i = 0; i < this->numberOfThreads; i++) {
        int retCode = pthread_create(&threads[i], NULL, RenderScene, (void *) &jobs[i]);
        if (retCode) {
            printf("Error: failed to create thread with error code %d\n", retCode);
            delete[] jobs;
            delete[] threads;
            return;
        }
    }
    
    for (int i = 0; i < this->numberOfThreads; i++)
        pthread_join(threads[i], NULL);
    
    delete[] jobs;
    
    BitmapWriter writer;
    writer.writeBitmap(*bitmap, this->outputPath);
    
    auto endTime = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    double timeCost = (endTime - startTime) / 1000000.0;
    
    printf("Render process completed in %.4lf seconds.\n", timeCost);
}

void * RenderScene(void * message)
{
    struct job * job = (struct job *) message;
    
    for (int i = job->startingY; i < job->endingY; i++) {
        printf("Scanning: %d/%d\n", i, job->endingY);
        for (int j = 0; j < job->bitmap->width; j++) {
            double x = job->camera->xyRatio * (j - job->halfWidth) / job->halfWidth;
            double y = (i - job->halfHeight) / job->halfHeight;
            
            Vector4 direction(job->camera->location);
            direction.add(Vector4(job->camera->xAxis).multiply(x));
            direction.add(Vector4(job->camera->yAxis).multiply(y));
            direction.add(Vector4(job->camera->zAxis).multiply(- job->camera->focalLength));
            direction.subtract(job->camera->location);
            direction.normalize();

            Color color = job->camera->rayObject(job->scene->rootObject, job->camera->location, direction, job->scene->lights, job->numberOfRecursions);
            
            auto pixel = job->bitmap->get(j, i);
            pixel.red   = color.r();
            pixel.green = color.g();
            pixel.blue  = color.b();
        }
    }

    return NULL;
}
