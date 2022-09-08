#include <iostream>
#include <Core/Camera.h>
#include <Core/Factory.h>
#include <Materials/MetalicMaterial.h>
#include <Materials/Lambertian.h>
#include <Materials/Dielectric.h>
#include <stdlib.h>
#include "Core/Scene.h"
#include "Core/Ray.h"
#include "Core/Vector.h"
#include "Core/Color.h"

const int RAY_DEPTH = 50;
Color RayColor(const Scene &scene, const Ray& ray, int depth = 0);

int main() {
    srand ((unsigned)time(0));
    //rendering
    int samplesPerPixel = 100;

    std::cerr<<"Starting\n";
    //Image
    const float aspectRatio =16.0/9.0;


    //Camera
    Vector3 cameraPosition(10, 10, -10);
    Vector3 lookAt(0,1,0);
    Vector3 up(0,1,0);
    Camera camera = Camera(cameraPosition, lookAt, up, aspectRatio , 60, 0, 1);
    const int imageWidth = 1200;
    const int imageHeight = static_cast<int>(imageWidth / aspectRatio);


    //Scene

    Scene scene;
    real cellSpace = 6.0f;

    //Create random Scene
    for(int i=-10;i<11;++i)
    {
        for(int j=-10;j<11; j++)
        {
            if(j == 0 && i == 0) continue;
            real radius = RayMath::Random(0.5, 2.5);

            Vector3 position(i*cellSpace, radius, j*cellSpace);
            Mesh* sphere = Factory::CreateSphereMesh(position, radius, new Lambertian(Vector3::Random(0,1)));
            scene.AddObject(sphere);
        }
    }
    Mesh* centerSphere = Factory::CreateSphereMesh(Vector3(0,0,0), 5, new MetalicMaterial(Vector3(1,1,1)));
//    Mesh centerSphere = Factory::CreateSphereMesh(Vector3(0.9,0.3,-2), 1, new Lambertian(Vector3::Random(0,1)));
//    Mesh rightSphere = Factory::CreateSphereMesh(Vector3(-1,1,-2), 1, new Dielectric(Vector3(1,1,1), 1.5));
//    Mesh leftSphere = Factory::CreateSphereMesh(Vector3(-0.5, 0.25,1), 0.5, new MetalicMaterial(Vector3(0.5,0.4,0.8)));
      Mesh* groundSphere = Factory::CreateSphereMesh(Vector3(0,-1000.5,-1), 1000, Vector3(0.5,0.8,0.9));

      scene.AddObject(centerSphere);
//    scene.AddObject(&leftSphere);
//    scene.AddObject(&rightSphere);
      scene.AddObject(groundSphere);

    std::cerr<<"Starting\n";
    std::cout << "P3\n" << imageWidth << " " << imageHeight << "\n255\n";
    for(int h = imageHeight - 1; h >= 0; --h)
    {
        std::cerr<<"\rScanlines Remaining:"<< h << ' '<<std::flush;

        for(int w = 0; w < imageWidth; ++w)
        {
            Color finalColor(0,0,0);
            for(int s = 0;s < samplesPerPixel; ++s)
            {
                auto u = (w + RayMath::Random()) / (imageWidth - 1);
                auto v = (h + RayMath::Random()) / (imageHeight - 1);
                Ray ray = camera.GetRay(u, v);

                Color sampleColor = RayColor(scene, ray, 0);
                finalColor = finalColor+sampleColor;
            }
            write_color(std::cout, finalColor, samplesPerPixel);
        }
    }

    std::cerr<<"\nDone\n";
}

Color RayColor(const Scene &scene, const Ray& ray, int depth)
{
    if(depth >= RAY_DEPTH) {
        return Vector3(0,0,0);
    }
    //Check Sphere
    HitPoint hitPoint;
    Vector2 rayLimits = Vector2(0.01, INT_MAX);
    if(scene.CastRay(ray,  rayLimits, hitPoint))
    {
        Ray scattered;
        Vector3 attenuation;
        if(hitPoint.mesh->Material->Scatter(ray, hitPoint, attenuation, scattered))
        {
            return attenuation * RayColor(scene, scattered, depth+1);
        }
        return Vector3(0,0,0);
    }

    Vector3 unitDirection = ray.Direction().normalized();
    real t = 0.5 * (unitDirection.y + 1.0f);
    return Vector3(1.0, 1.0, 1.0) * (1.0 - t) + Color(0.5, 0.7, 1.0) * t;
}