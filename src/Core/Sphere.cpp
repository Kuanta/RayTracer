#include "Core/Sphere.h"
#include "Core/Mesh.h"

Sphere::Sphere() {
    radius = 1;
}

Sphere::Sphere(real radius)
{
    this->radius = radius;
}

bool Sphere::hit(const Ray &ray, real tMin, real tMax, HitPoint &hitPoint) const
{
    Vector3 center = mesh->position;
    Vector3 oc = ray.Origin() - center;
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
    hitPoint.normal = hitNormal.normalized();
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

Vector3 Sphere::RandomInHemisphere(Vector3 surfaceNormal)
{
    Vector3 inSphere = Sphere::RandomInUnitSphere();
    inSphere.normalize();
    if(inSphere.dot(surfaceNormal) >= 0)
    {
        return inSphere;
    }else{
        return inSphere * -1;
    }
}
