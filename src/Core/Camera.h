#ifndef RAYTRACER_CAMERA_H
#define RAYTRACER_CAMERA_H


#include "Ray.h"

class Camera {
public:
    Vector3 position;
    Vector3 direction;
    float verticalFov;
    float aspectRatio;
    float viewportHeight;
    float viewportWidth;
    float focalLength;

    Camera(Vector3 position, Vector3 lookAt, Vector3 up, float aspectRatio, float verticalFov, float aperture, float focusDist);
    Ray GetRay(real u, real v);

private:

    Vector3 horizontal;
    Vector3 vertical;
    Vector3 lowerLeftCorner;
    float lensRadius;
    Vector3 u;
    Vector3 w;
    Vector3 v;
};


#endif //RAYTRACER_CAMERA_H
