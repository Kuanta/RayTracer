//
// Created by erdem on 7.09.2022.
//

#ifndef RAYTRACER_MESH_H
#define RAYTRACER_MESH_H


#include "Geometry.h"
#include "Material.h"
#include "HitPoint.h"

class Mesh {

public:
    Geometry* Geometry;
    Material* Material;
    Vector3 position;
    //todo: implement rotation

public:
    Mesh();
    Mesh(class Geometry* geometry, class Material* material);
    virtual bool hit(const Ray &ray, real tMin, real tMax, HitPoint &hitPoint) const;
    virtual bool boundingBox(AxisAlignedBoundingBox& bondingBox) const;
};


#endif //RAYTRACER_MESH_H
