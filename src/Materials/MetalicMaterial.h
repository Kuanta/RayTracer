//
// Created by erdem on 7.09.2022.
//

#ifndef RAYTRACER_METALICMATERIAL_H
#define RAYTRACER_METALICMATERIAL_H

#include "Core/Material.h"

class MetalicMaterial : public Material{
public:
    real fuzzyConstant = 0.1;

public:
    MetalicMaterial(Vector3 color);
    virtual bool Scatter(const Ray &ray, const HitPoint &hitPoint, Vector3 &attenuation, Ray &scattered) const override;


};


#endif //RAYTRACER_METALICMATERIAL_H
