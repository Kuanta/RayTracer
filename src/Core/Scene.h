//
// Created by erdem on 14.08.2022.
//

#ifndef RAYTRACER_SCENE_H
#define RAYTRACER_SCENE_H

#include <vector>
#include "Core/Geometry.h"

class Scene
{
public:
    Vector3 lightDirection;
    std::vector<Geometry*> objects;
    Scene();
    void AddObject(Geometry* mesh);
    void RemoveMesh(Geometry* mesh);
    void ClearObjectList();
    bool CastRay(const Ray &ray, Vector2 rayLimits, HitPoint &hitPoint) const;

};
#endif //RAYTRACER_SCENE_H
