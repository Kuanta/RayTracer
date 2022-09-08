#include "Core/Scene.h"

Scene::Scene() {
    objects = std::vector<Mesh*>();
    rootNode = nullptr;
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
    if(rootNode == nullptr)
    {
        for(int i=0; i<objects.size();++i)
        {
            if(objects.at(i)->hit(ray, rayLimits.x, minT, hitPoint))
            {
                hit = true;
                minT = hitPoint.t;
            }
        }
        return hit;
    }

    return rootNode->hit(ray,rayLimits.x, rayLimits.y, hitPoint);
}

void Scene::CalculateOverallBox() {
    bool firstBox = true;
    AxisAlignedBoundingBox tempBox;
    if(objects.empty()) return;

    for(const Mesh* object : objects)
    {
        if(!object->boundingBox(tempBox)) continue;
        overallBox = firstBox ? tempBox : AxisAlignedBoundingBox::CreateSurroundingBox(overallBox, tempBox);
        firstBox = false;
    }
}

void Scene::ConstructBVH() {
    rootNode = new BVHNode(objects);
}
