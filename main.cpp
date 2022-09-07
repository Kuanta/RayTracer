#include <iostream>
#include <Core/Camera.h>
#include <Core/Factory.h>
#include <Materials/MetalicMaterial.h>
#include <Materials/Lambertian.h>
#include "Core/Scene.h"
#include "Core/Sphere.h"
#include "Core/Ray.h"
#include "Core/Vector.h"
#include "Core/Color.h"

const int RAY_DEPTH = 50;
Color RayColor(const Scene &scene, const Ray& ray, int depth = 0);

int main() {

    //rendering
    int samplesPerPixel = 100;

    std::cerr<<"Starting\n";
    //Image
    const float aspectRatio = 16.0f / 9.0f;
    const int imageWidth = 400;
    const int imageHeight = static_cast<int>(imageWidth / aspectRatio);

    //Camera
    float viewPortHeight = 2.0f;
    float viewPortWidth = aspectRatio * viewPortHeight;
    float focalLength = 1.0f;
    Camera camera = Camera(viewPortHeight, viewPortWidth, focalLength);

    //Scene

    Scene scene;
    Mesh centerSphere = Factory::CreateSphereMesh(Vector3(0.7,0,-1), 0.5, new Lambertian(Vector3::Random()));
    Mesh leftSphere = Factory::CreateSphereMesh(Vector3(-0.8, 0.1,-1.2), 0.6, new MetalicMaterial(Vector3(0.5,0.4,0.8)));
    Mesh groundSphere = Factory::CreateSphereMesh(Vector3(0,-100.5,-1), 100, Vector3(0.5,0.8,0.9));

    scene.AddObject(&centerSphere);
    scene.AddObject(&leftSphere);
    scene.AddObject(&groundSphere);

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
    Vector2 rayLimits = Vector2(0.01, 100);
    if(scene.CastRay(ray,  rayLimits, hitPoint))
    {
        Ray scattered;
        Vector3 attenuation;
        if(hitPoint.mesh->Material->Scatter(ray, hitPoint, attenuation, scattered))
        {
            return attenuation * RayColor(scene, scattered, depth++);
        }
        return Vector3(0,0,0);
    }

    Vector3 unitDirection = ray.Direction().normalized();
    real t = 0.5 * (unitDirection.y + 1.0f);
    return Vector3(1.0, 1.0, 1.0) * (1.0 - t) + Color(0.5, 0.7, 1.0) * t;
}