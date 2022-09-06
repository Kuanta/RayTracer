//
// Created by erdem on 23.05.2022.
//

#include "Ray.h"

Ray::Ray(void)
{

}
Ray::Ray(const Vector3 &origin, const Vector3 &direction)
{
    this->origin = origin;
    this->direction = direction;
}
Ray::Ray(const Ray &ray)
{
    this->direction(ray.direction);
    this->origin(ray.origin);
}

Ray::~Ray(void)
{
    
}

Vector3 Ray::GetPoint(real t) const
{
    return Origin() + Direction().normalized()*t;
}
