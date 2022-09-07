//
// Created by erdem on 7.09.2022.
//

#ifndef RAYTRACER_HITPOINT_H
#define RAYTRACER_HITPOINT_H

#include "Vector.h"

class Mesh;

struct HitPoint
{
    Mesh* mesh;
    Vector3 normal;
    Vector3 point;
    real t;
};

#endif //RAYTRACER_HITPOINT_H
