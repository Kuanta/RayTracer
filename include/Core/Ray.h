//
// Created by erdem on 23.05.2022.
//

#ifndef RAYTRACER_RAY_H
#define RAYTRACER_RAY_H

#include "Vector.h"

class Ray {
public:
    Vector3 origin;
    Vector3 direction;

    Ray(void);
    Ray(const Vector3 &origin, const Vector3 &direction); //Constructor
    Ray(const Ray &ray); //Copy constructor
    ~Ray(void);

    Vector3 Origin() const {
        return origin;
    };

    Vector3 Direction() const{
        return direction;
    };
    Vector3 GetPoint(real t) const;
};


#endif //RAYTRACER_RAY_H
