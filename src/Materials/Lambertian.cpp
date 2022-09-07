//
// Created by erdem on 7.09.2022.
//

#include "Lambertian.h"

bool Lambertian::Scatter(const Ray &ray, const HitPoint &hitPoint, Vector3 &attenuation, Ray &scattered) const {
    Vector3 scatterDirection = Vector3::Random() + hitPoint.normal;
    if(Vector3::NearZero(scatterDirection))
    {
        scatterDirection = hitPoint.normal;
    }
    scattered = Ray(hitPoint.point, scatterDirection);
    attenuation = this->Color;
    return true;
}

Lambertian::Lambertian(Vector3 color) : Material(color) {

}
