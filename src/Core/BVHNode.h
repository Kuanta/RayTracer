//
// Created by erdem on 8.09.2022.
//

#ifndef RAYTRACER_BVHNODE_H
#define RAYTRACER_BVHNODE_H

#include <vector>
#include <algorithm>
#include "Mesh.h"

using namespace std;

class BVHNode : Mesh{

public:
    BVHNode(vector<Mesh*> sourceObjects);
    BVHNode(vector<Mesh*> sourceObjects, size_t start, size_t end);
    bool hit(const Ray &ray, real tMin, real tMax, HitPoint &hitPoint) const override;
    bool boundingBox(AxisAlignedBoundingBox& bondingBox) const override;

private:
    Mesh* left;
    Mesh* right;
    AxisAlignedBoundingBox box;
};

inline bool boxCompare(Mesh* a, Mesh* b, int axis);

bool boxXCompare(Mesh* a, Mesh* b);

bool boxYCompare(Mesh* a, Mesh* b);

bool boxZCompare(Mesh* a, Mesh* b);

#endif //RAYTRACER_BVHNODE_H
