//
// Created by erdem on 8.09.2022.
//

#ifndef RAYTRACER_AXISALIGNEDBOUNDINGBOX_H
#define RAYTRACER_AXISALIGNEDBOUNDINGBOX_H

#include "Vector.h"
#include "Ray.h"

class AxisAlignedBoundingBox {
public:
    Vector3 MinPoint;
    Vector3 MaxPoint;

public:
    AxisAlignedBoundingBox();
    AxisAlignedBoundingBox(Vector3 min, Vector3 max);
    bool hit(const Ray& ray, real rayMin, real rayMax) const;
    static AxisAlignedBoundingBox CreateSurroundingBox(AxisAlignedBoundingBox box1, AxisAlignedBoundingBox box2);

};


#endif //RAYTRACER_AXISALIGNEDBOUNDINGBOX_H
