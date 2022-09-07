//
// Created by erdem on 7.09.2022.
//

#ifndef RAYTRACER_LAMBERTIAN_H
#define RAYTRACER_LAMBERTIAN_H


#include <Core/Material.h>
#include <Core/Ray.h>
#include <Core/HitPoint.h>

class Lambertian : public Material {
public:
    Lambertian(Vector3 color);

    virtual bool Scatter(const Ray &ray, const HitPoint &hitPoint, Vector3 &attenuation, Ray &scattered) const override;

};


#endif //RAYTRACER_LAMBERTIAN_H
