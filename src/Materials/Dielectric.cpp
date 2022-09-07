//
// Created by erdem on 7.09.2022.
//

#include "Dielectric.h"

Dielectric::Dielectric() {
    this->Color = Vector3(1,1,1);
}

Dielectric::Dielectric(Vector3 color, float refractionFactor) : Material(color) {
    this->Color = color;
    this->RefractionFactor = refractionFactor;
}

bool Dielectric::Scatter(const Ray &ray, const HitPoint &hitPoint, Vector3 &attenuation, Ray &scattered) const
{
    attenuation = Vector3(1,1,1);
    float refFac = hitPoint.isFrontFace ? (1.0 / RefractionFactor) : RefractionFactor;

    Vector3 refracted = HitPoint::Refract(ray, hitPoint.normal, refFac);
    scattered = Ray(hitPoint.point, refracted);
    return true;
}