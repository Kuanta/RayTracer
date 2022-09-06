#include "Core/Camera.h"

Camera::Camera(float viewportHeight, float viewportWidth, float focalLength)
{
    this->viewportHeight = viewportHeight;
    this->viewportWidth =  viewportWidth;
    this->aspectRatio = viewportWidth / viewportHeight;
    this->focalLength = focalLength;

    this->position = Vector3(0,0,0);
    this->horizontal = Vector3(viewportWidth, 0,0);
    this->vertical = Vector3(0,viewportHeight,0);
    this->lowerLeftCorner = position - horizontal/2.0f - vertical/2.0f - Vector3(0,0,focalLength);
}

Ray Camera::GetRay(real u, real v)
{
    return Ray(position, lowerLeftCorner + horizontal*u + vertical*v - position);
}