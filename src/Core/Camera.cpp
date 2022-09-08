#include "Core/Camera.h"
#include "Sphere.h"

Camera::Camera(Vector3 position, Vector3 lookAt, Vector3 up, float aspectRatio, float verticalFov, float aperture, float focusDist)
{
    float theta = RayMath::DegToRad(verticalFov);
    float h = tan(theta/2);
    this->verticalFov = verticalFov;
    this->aspectRatio = aspectRatio;
    this->viewportHeight = h * 2.0;
    this->viewportWidth =  aspectRatio * viewportHeight;
    this->aspectRatio = aspectRatio;
    this->focalLength = 1;

    w = (position - lookAt).normalized();
    u =  (up.cross(w)).normalized();
    v = w.cross(u);

    this->position = position;
    this->horizontal = focusDist * viewportWidth * u;
    this->vertical = focusDist * viewportHeight * v;
    this->lowerLeftCorner = position - horizontal/2.0f - vertical/2.0f - focusDist * w;
    lensRadius = aperture / 2;
}

Ray Camera::GetRay(real u, real v)
{
    Vector3 random = lensRadius * Sphere::RandomInUnitSphere();
    Vector3 offset = this->u * random.x + this->v*random.y;
    return Ray(position + offset, lowerLeftCorner + horizontal*u + vertical*v - position - offset);
}