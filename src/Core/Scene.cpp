#include "Core/Scene.h"

Scene::Scene() {
    objects = std::vector<Mesh*>();
}
void Scene::AddObject(Mesh* mesh)
{
    objects.push_back(mesh);
}

void Scene::ClearObjectList()
{
    objects.clear();
}

bool Scene::CastRay(const Ray &ray, Vector2 rayLimits, HitPoint &hitPoint) const
{
    bool hit = false;
    float minT = rayLimits.y;
    for(int i=0; i<objects.size();++i)
    {
        if(objects.at(i)->hit(ray, rayLimits.x, minT, hitPoint))
        {
            hit = true;
            minT = hitPoint.t;
            hitPoint.mesh = objects.at(i);
        }
    }
    return hit;
}
