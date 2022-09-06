#include <iostream>
#include <Core/Camera.h>
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
    Sphere* centerSphere = new Sphere(Vector3(0,0,-1), 0.5);
    centerSphere->color = Vector3(0.5f, 0.2f, 0.9f);

    Sphere* leftSphere = new Sphere(Vector3(-0.9, 0.2, -1.5), 0.6);
    leftSphere->color = Vector3(0.8f,0.4f,0.5f);

    Sphere* groundSphere = new Sphere(Vector3(0,-100.5,-1), 100);
    groundSphere->color = Vector3(0.2f, 0.9f, 0.4f);

    scene.AddObject(centerSphere);
    //scene.AddObject(leftSphere);
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
    Vector3 lightDirection = Vector3(0.5f, -0.8f, -1.0f);
    //Check Sphere
    HitPoint hitPoint;
    Vector2 rayLimits = Vector2(0, 100);
    if(scene.CastRay(ray,  rayLimits, hitPoint))
    {
        Vector3 target = hitPoint.point + hitPoint.normal + Sphere::RandomInUnitSphere();
        Ray bouncingRay = Ray(hitPoint.point, target - hitPoint.point);
        return RayColor(scene, bouncingRay, depth + 1) * 0.5;
//        surfaceNormal.normalize();
//        real dotProd = (lightDirection * -1).dot(surfaceNormal);
//        dotProd = std::max<real>(dotProd, 0);
//        return hitPoint.color * dotProd;
    }
    Vector3 unitDirection = ray.Direction().normalized();
    real t = 0.5 * (unitDirection.y + 1.0f);
    return Vector3(1.0, 1.0, 1.0) * (1.0 - t) + Color(0.5, 0.7, 1.0) * t;
}