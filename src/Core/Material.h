//
// Created by erdem on 7.09.2022.
//

#ifndef RAYTRACER_MATERIAL_H
#define RAYTRACER_MATERIAL_H

#include "Vector.h"
#include <Core/Ray.h>
#include <Core/HitPoint.h>

class Material
{
public:
    Vector3 Color;

public:
    Material(){}
    Material(Vector3 color)
    {
        this->Color = color;
    }
    virtual bool Scatter(const Ray &ray, const HitPoint &hitPoint, Vector3 &attenuation, Ray &scattered) const = 0;
};

#endif //RAYTRACER_MATERIAL_H
