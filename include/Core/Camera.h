#ifndef RAYTRACER_CAMERA_H
#define RAYTRACER_CAMERA_H


#include "Ray.h"

class Camera {
public:
    float aspectRatio;
    float viewportHeight;
    float viewportWidth;
    float focalLength;

    Camera(float viewportHeight, float viewportWidth, float focalLength);
    Ray GetRay(real u, real v);

private:
    Vector3 position;
    Vector3 horizontal;
    Vector3 vertical;
    Vector3 lowerLeftCorner;
};


#endif //RAYTRACER_CAMERA_H
