//
// Created by erdem on 14.08.2022.
//

#ifndef RAYTRACER_SPHERE_H
#define RAYTRACER_SPHERE_H

#include "Core/Geometry.h"

class Sphere : public Geometry
{
public:
    real radius;

    Sphere();
    Sphere(real radius);
    virtual bool hit(const Ray &ray, real tMin, real tMax, HitPoint &hitPoint) const override;
    static Vector3 RandomInUnitSphere();
    static Vector3 RandomInHemisphere(Vector3 surfaceNormal);
};
#endif //RAYTRACER_SPHERE_H
