#include <iostream>
#include <Core/Camera.h>
#include <Core/Factory.h>
#include <Materials/MetalicMaterial.h>
#include <Materials/Lambertian.h>
#include <stdlib.h>
#include <Core/RayTracer.h>
#include "Core/Scene.h"
#include "Core/Vector.h"


int main(int argc, char *argv[]) {

    int RAY_DEPTH = 50;
    int SAMPLES_PER_PIXEL = 100;

    srand ((unsigned)time(0));
    //rendering

    std::cerr<<"Starting\n";
    //Image
    const float aspectRatio = 16.0/9.0;

    //Camera
    Vector3 cameraPosition(10, 12, -15);
    Vector3 lookAt(0,1,0);
    Vector3 up(0,1,0);
    Camera camera = Camera(cameraPosition, lookAt, up, aspectRatio , 60, 0, 1);
    const int imageWidth = 1920;
    const int imageHeight = static_cast<int>(imageWidth / aspectRatio);


    //Scene
    Scene scene;
    real cellSpace = 6.0f;

    //Create random Scene
    for(int i=-5;i<5;++i)
    {
        for(int j=-5;j<5; j++)
        {
            if(fabs(j) < 1 && fabs(i) < 1) continue;
            real radius = RayMath::Random(0.5, 2.5);

            Vector3 position(i*cellSpace, radius, j*cellSpace);
            Mesh* sphere = Factory::CreateSphereMesh(position, radius, new Lambertian(Vector3::Random(0,1)));
            scene.AddObject(sphere);
        }
    }
    Mesh* centerSphere = Factory::CreateSphereMesh(Vector3(0,5,0), 5, new MetalicMaterial(Vector3(1,1,1)));
    Mesh* groundSphere = Factory::CreateSphereMesh(Vector3(0,-1000.5,-1), 1000, Vector3(0.5,0.8,0.9));

    scene.AddObject(centerSphere);
    scene.AddObject(groundSphere);
    scene.ConstructBVH();

    //Ray Tracer
    RayTracer rayTracer(&scene, &camera, imageWidth, imageHeight);
    rayTracer.SamplesPerPixel = SAMPLES_PER_PIXEL;
    rayTracer.RayDepth = RAY_DEPTH;
    rayTracer.RayTrace();
    rayTracer.OutputResult(std::cout);

}

