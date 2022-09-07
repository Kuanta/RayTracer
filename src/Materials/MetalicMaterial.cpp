//
// Created by erdem on 7.09.2022.
//

#include "MetalicMaterial.h"
#include "Core/HitPoint.h"

bool MetalicMaterial::Scatter(const Ray &ray, const HitPoint &hitPoint, Vector3 &attenuation, Ray &scattered) const {
    Vector3 reflected = HitPoint::Reflect(ray.direction, hitPoint.normal);
    reflected = reflected + (Vector3::Random(-1, 1)).normalized()*fuzzyConstant;
    scattered = Ray(hitPoint.point, reflected);
    attenuation = this->Color;
    return scattered.direction.dot(hitPoint.normal) > 0;
}

MetalicMaterial::MetalicMaterial(Vector3 color) : Material(color) {

}
