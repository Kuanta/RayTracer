//
// Created by erdem on 14.08.2022.
//

#ifndef RAYTRACER_SPHERE_H
#define RAYTRACER_SPHERE_H

#include "Core/Geometry.h"

class Sphere : public Geometry
{
public:
    Vector3 center;
    real radius;

    Sphere();
    Sphere(Vector3 origin, real radius);
    virtual bool hit(const Ray &ray, real tMin, real tMax, HitPoint &hitPoint) const override;
    static Vector3 RandomInUnitSphere();
};
#endif //RAYTRACER_SPHERE_H
