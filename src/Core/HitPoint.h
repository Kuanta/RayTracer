//
// Created by erdem on 7.09.2022.
//

#ifndef RAYTRACER_HITPOINT_H
#define RAYTRACER_HITPOINT_H

#include "Vector.h"

class Mesh;

struct HitPoint
{
    const Mesh* mesh;
    Vector3 normal;
    Vector3 point;
    bool isFrontFace;
    real t;

    //Static methods
    static Vector3 Reflect(const Vector3& vector, const Vector3& normal)
    {
        real dot = vector.dot(normal);
        return vector - normal * (2 * dot);
    }

    static Vector3 Refract(const Ray& incoming, const Vector3& normal, real refractionFactor)
    {
        Vector3 normalizedDirection = incoming.Direction().normalized();
        real cosTheta = fmin((normalizedDirection * -1).dot(normal), 1.0);
        Vector3 perpRay = (normalizedDirection + normal*cosTheta) * refractionFactor;
        real sqrMag = perpRay.sqrMagnitude();
        Vector3 parallelRay = normal * (-1 * sqrt(fabs(1-sqrMag)));
        return perpRay + parallelRay;
    }
};

#endif //RAYTRACER_HITPOINT_H
