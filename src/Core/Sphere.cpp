#include "Core/Sphere.h"

Sphere::Sphere() {
    center = Vector3(0, 0, 0);
    radius = 1;
}

Sphere::Sphere(Vector3 origin, real radius)
{
    this->center(origin);
    this->radius = radius;
}

bool Sphere::hit(const Ray &ray, real tMin, real tMax, HitPoint &hitPoint) const
{
    Vector3 oc = ray.Origin() - this->center;
    real a = ray.Direction().dot(ray.Direction());
    real halfB = ray.Direction().dot(oc);
    real c = oc.dot(oc) - radius*radius;
    real discriminant = halfB*halfB - a*c;
    if(discriminant < 0)
    {
        return false;
    }
    real t = (-halfB - sqrt(discriminant))/a;
    if( t < tMin || t > tMax)
    {
        t = (-halfB + sqrt(discriminant))/a;
        if(t < tMin || tMax < t)
        {
            return false;
        }
    }
    Vector3 hitPosition = ray.GetPoint(t);
    Vector3 hitNormal = (hitPosition - center) / radius;
    hitPoint.point = hitPosition;
    hitPoint.normal = hitNormal;
    hitPoint.t = t;
    return true;
}

Vector3 Sphere::RandomInUnitSphere()
{
    while(true)
    {
        Vector3 p = Vector3::Random(-1,1);
        real mag = p.sqrMagnitude();
        if(mag < 1){
            return p;
        }
    }
}
