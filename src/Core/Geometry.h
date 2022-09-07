#ifndef RAYTRACER_GEOMETRY_H
#define RAYTRACER_GEOMETRY_H

#include "Core/Vector.h"
#include "Core/Ray.h"
#include "HitPoint.h"

class Mesh;

class Geometry
{
public:
    Mesh* mesh;
public:
    virtual bool hit(const Ray &ray, real tMin, real tMax, HitPoint &hitPoint) const = 0;
};
#endif //RAYTRACER_GEOMETRY_H
