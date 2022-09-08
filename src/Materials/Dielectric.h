//
// Created by erdem on 7.09.2022.
//

#ifndef RAYTRACER_DIELECTRIC_H
#define RAYTRACER_DIELECTRIC_H


#include <Core/Material.h>

class Dielectric : public Material{

public:
    real RefractionFactor;

public:
    Dielectric();
    Dielectric(Vector3 color, real refractionFactor);

    virtual bool Scatter(const Ray &ray, const HitPoint &hitPoint, Vector3 &attenuation, Ray &scattered) const override;
private:
    static double Reflectance(double cosine, double refIdx);
};


#endif //RAYTRACER_DIELECTRIC_H
