//
// Created by erdem on 8.09.2022.
//

#include "RayTracer.h"

RayTracer::RayTracer(const class Scene* scene, const class Camera* camera, int imageWidth, int imageHeight)
{
    Result = Gray::Image(imageWidth, imageHeight);
    Width = imageWidth;
    Height = imageHeight;
    Scene = scene;
    Camera = camera;
}

void RayTracer::RayTrace()
{
    RayTrace(0, Height);
}

void RayTracer::RayTrace(int startHeight, int endHeight)
{
    std::cerr<<"Starting\n";

    for(int h = endHeight - 1; h >= startHeight; --h)
    {
        std::cerr<<"\rScanlines Remaining:"<< h << ' '<<std::flush;

        for(int w = 0; w < Width; ++w)
        {
            Color finalColor(0,0,0);
            for(int s = 0;s < SamplesPerPixel; ++s)
            {
                auto u = (w + RayMath::Random()) / (Width - 1);
                auto v = (h + RayMath::Random()) / (Width - 1);
                Ray ray = Camera->GetRay(u, v);
                Color sampleColor = RayColor(ray, 0);
                finalColor = finalColor+sampleColor;
            }
            Result.SetPixelValue(h, w, finalColor);
        }
    }

    std::cerr<<"\nDone\n";
}

void RayTracer::OutputResult(std::ostream &out)
{
    std::cout << "P3\n" << Width << " " << Height << "\n255\n";
    int pixelColor[3];
    for(int h = Height - 1; h >= 0; --h)
    {
        for(int w = 0; w < Width; ++w)
        {
            Result.GetPixelValue(h, w, pixelColor);
            WritePixel(std::cout, Vector3(pixelColor[0], pixelColor[1], pixelColor[2]), SamplesPerPixel);
        }
    }
}

Color RayTracer::RayColor(const Ray &ray, int depth)
{
    if(depth >=RayDepth) {
        return Vector3(0,0,0);
    }
    HitPoint hitPoint;
    Vector2 rayLimits = Vector2(0.01, INT_MAX);
    if(Scene->CastRay(ray,  rayLimits, hitPoint))
    {
        Ray scattered;
        Vector3 attenuation;
        if(hitPoint.mesh->Material != nullptr && hitPoint.mesh->Material->Scatter(ray, hitPoint, attenuation, scattered))
        {
            return attenuation * RayColor(scattered, depth+1);
        }
        return Vector3(0,0,0);
    }

    Vector3 unitDirection = ray.Direction().normalized();
    real t = 0.5 * (unitDirection.y + 1.0f);
    return Vector3(1.0, 1.0, 1.0) * (1.0 - t) + Color(0.5, 0.7, 1.0) * t;
}

void RayTracer::WritePixel(std::ostream &out, Color pixel_color, int samplesPerPixel)
{
    real red = pixel_color.x;
    real green = pixel_color.y;
    real blue = pixel_color.z;

    //Gamma correction
    real scale = 1.0 / samplesPerPixel;

    red = sqrt(scale * red);
    green = sqrt(scale*green);
    blue = sqrt(scale * blue);

    // Write the translated [0,255] value of each color component.
    out << static_cast<int>(256 * RayMath::Clamp(red, 0.0, 0.999)) << ' '
        << static_cast<int>(256 * RayMath::Clamp(green, 0.0, 0.999)) << ' '
        << static_cast<int>(256 * RayMath::Clamp(blue, 0.0, 0.999)) << '\n';
}