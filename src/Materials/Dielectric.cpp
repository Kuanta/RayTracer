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
    Vector3 normalizedDirection = ray.Direction().normalized();
    real cosTheta = fmin((normalizedDirection * -1).dot(hitPoint.normal), 1.0);
    real sinTheta = sqrt(1.0 - cosTheta*cosTheta);

    Vector3 direction;
    if(sinTheta * refFac > 1.0 || Dielectric::Reflectance(cosTheta, refFac) > RayMath::Random())
    {
        //Reflect
        direction = HitPoint::Reflect(normalizedDirection, hitPoint.normal);
    }
    else{
        //Refract
        direction = HitPoint::Refract(ray, hitPoint.normal, refFac);
    }
    scattered = Ray(hitPoint.point, direction);
    return true;
}

double Dielectric::Reflectance(double cosine, double refIdx)
{
    real r0 = (1-refIdx) / (1+refIdx);
    r0 = r0*r0;
    return r0 + (1-r0)*pow((1-cosine), 5);
}