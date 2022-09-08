//
// Created by erdem on 14.08.2022.
//

#ifndef RAYTRACER_SCENE_H
#define RAYTRACER_SCENE_H

#include <vector>
#include "Core/Mesh.h"
#include "BVHNode.h"

class Scene
{
public:
    void ConstructBVH();
    Vector3 lightDirection;
    std::vector<Mesh*> objects;
    Scene();
    void CalculateOverallBox();
    void AddObject(Mesh* mesh);
    void RemoveObject(Mesh* mesh);
    void ClearObjectList();
    bool CastRay(const Ray &ray, Vector2 rayLimits, HitPoint &hitPoint) const;

private:
    BVHNode* rootNode;
    AxisAlignedBoundingBox overallBox;
};
#endif //RAYTRACER_SCENE_H
