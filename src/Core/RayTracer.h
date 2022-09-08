//
// Created by erdem on 8.09.2022.
//

#ifndef RAYTRACER_RAYTRACER_H
#define RAYTRACER_RAYTRACER_H


#include "Scene.h"
#include "Camera.h"
#include "Image.h"

class RayTracer {
public:
    Gray::Image Result;
public:
    int RayDepth = 50;
    int SamplesPerPixel = 100;
    int Width;
    int Height;

public:
    RayTracer(const Scene* scene, const Camera* camera, int imageWidth, int imageHeight);
    void RayTrace();
    void RayTrace(int startHeight, int endHeight);
    void OutputResult(std::ostream &out);

private:
    const Scene* Scene;
    const Camera* Camera;
private:
    Color RayColor(const Ray& ray, int depth);
    void WritePixel(std::ostream &out, Color pixel_color, int samplesPerPixel);

};


#endif //RAYTRACER_RAYTRACER_H
