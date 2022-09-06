#ifndef RAYTRACER_GEOMETRY_H
#define RAYTRACER_GEOMETRY_H

#include "Core/Vector.h"
#include "Core/Ray.h"

struct HitPoint
{
    Vector3 point;
    Vector3 normal;
    Vector3 color;
    real t;
};

class Geometry
{
public:
    Vector3 color;
    virtual bool hit(const Ray &ray, real tMin, real tMax, HitPoint &hitPoint) const = 0;
};
#endif //RAYTRACER_GEOMETRY_H
