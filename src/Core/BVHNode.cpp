//
// Created by erdem on 8.09.2022.
//

#include "BVHNode.h"

bool BVHNode::hit(const Ray &ray, real tMin, real tMax, HitPoint &hitPoint) const {
    if(left == nullptr || right == nullptr) return false;
    if(!this->box.hit(ray, tMin, tMax)) return false;
    bool hitLeft = left->hit(ray, tMin, tMax, hitPoint);
    bool hitRight = right->hit(ray, tMin, hitLeft ? hitPoint.t : tMax, hitPoint);

    return hitLeft || hitRight;
}

bool BVHNode::boundingBox(AxisAlignedBoundingBox &bondingBox) const {
    bondingBox = this->box;
    return true;
}


BVHNode::BVHNode(vector<Mesh *> sourceObjects) : BVHNode(sourceObjects, 0, sourceObjects.size())
{

}

BVHNode::BVHNode(vector<Mesh *> sourceObjects, size_t start, size_t end) {

    vector<Mesh*> objects = sourceObjects;
    int axis = RayMath::RandomInt(0, 2);
    auto comparator = (axis == 0) ? boxXCompare :
                      (axis == 1) ? boxYCompare :
                      boxZCompare;

    size_t objectSpan = end - start;

    if (objectSpan == 1) {
        left = right = objects[start];
    } else if (objectSpan == 2) {
        if (comparator(objects[start], objects[start+1])) {
            left = objects[start];
            right = objects[start+1];
        } else {
            left = objects[start+1];
            right = objects[start];
        }
    } else {
        std::sort(objects.begin() + start, objects.begin() + end, comparator);

        auto mid = start + objectSpan / 2;
        left = new BVHNode(objects, start ,mid);
        right = new BVHNode(objects, mid ,end);
    }

    AxisAlignedBoundingBox boxLeft, boxRight;

    if (  !left->boundingBox(boxLeft)
          || !right->boundingBox(boxRight)
            )
        std::cerr << "No bounding box in bvh_node constructor.\n";

    box = AxisAlignedBoundingBox::CreateSurroundingBox(boxLeft, boxRight);
}


inline bool boxCompare(Mesh* a, Mesh* b, int axis)
{
    AxisAlignedBoundingBox aBox;
    AxisAlignedBoundingBox bBox;

    if(!a->boundingBox(aBox) || !b->boundingBox(bBox))
    {
        std::cerr<<"No bounding box in BVH constructor"<<std::endl;
    }
    return aBox.MinPoint.getDimension(axis) < bBox.MinPoint.getDimension(axis);
}

bool boxXCompare(Mesh* a, Mesh* b)
{
    return boxCompare(a, b, 0);
}

bool boxYCompare(Mesh* a, Mesh* b)
{
    return boxCompare(a, b, 1);
}

bool boxZCompare(Mesh* a, Mesh* b)
{
    return boxCompare(a, b, 2);
}
