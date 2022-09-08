//
// Created by erdem on 8.09.2022.
//

#include "AxisAlignedBoundingBox.h"

AxisAlignedBoundingBox::AxisAlignedBoundingBox() {
    MinPoint = Vector3(-1,-1,-1);
    MaxPoint = Vector3(1,1,1);
}

AxisAlignedBoundingBox::AxisAlignedBoundingBox(Vector3 min, Vector3 max) {
    MinPoint = min;
    MaxPoint = max;
}

bool AxisAlignedBoundingBox::hit(const Ray &ray, real rayMin, real rayMax) const{
    for(int i=0;i<3;++i)
    {
        real invD = 1.0f/ray.Direction().getDimension(i);
        real t0 = (MinPoint.getDimension(i) - ray.Direction().getDimension(i)) * invD;
        real t1 = (MaxPoint.getDimension(i) - ray.Direction().getDimension(i)) * invD;
        if(invD < 0.0f)
        {
            std::swap(t0, t1);
        }
        real tMin = fmax(t0, rayMin);
        real tMax = fmin(t1, rayMax);
        if(tMax <= tMin) return false;
    }
    return true;
}

AxisAlignedBoundingBox AxisAlignedBoundingBox::CreateSurroundingBox(AxisAlignedBoundingBox box1, AxisAlignedBoundingBox box2) {
    Vector3 newMin(fmin(box1.MinPoint.x, box2.MinPoint.x),
                   fmin(box1.MinPoint.y, box2.MinPoint.y),
                   fmin(box1.MinPoint.z, box2.MinPoint.z));
    Vector3 newMax(fmax(box1.MaxPoint.x, box2.MaxPoint.x),
                   fmax(box1.MaxPoint.y, box2.MaxPoint.y),
                   fmax(box1.MaxPoint.z, box2.MaxPoint.z));
    return AxisAlignedBoundingBox(newMin, newMax);
}


