//
// Created by erdem on 7.09.2022.
//

#include "Mesh.h"

Mesh::Mesh() {
    Geometry = nullptr;
    Material = nullptr;
}

Mesh::Mesh(class Geometry* geometry, class Material* material)
{
    this->Geometry = geometry;
    geometry->mesh = this;
    this->Material = material;
}

bool Mesh::hit(const Ray &ray, real tMin, real tMax, HitPoint &hitPoint) const {
    if(Geometry == nullptr)
    {
        return false;
    }
    bool result = Geometry->hit(ray, tMin, tMax, hitPoint);
    if(result) hitPoint.mesh = this;
    return result;
}

bool Mesh::boundingBox(AxisAlignedBoundingBox &bondingBox) const{
    if(Geometry == nullptr) return false;
    return Geometry->boundingBox(bondingBox);
}
