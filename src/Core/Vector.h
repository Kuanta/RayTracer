#ifndef RAYTRACER_VECTOR_H
#define RAYTRACER_VECTOR_H

#include <cmath>
#include <iostream>
#include <string>
#include "./configs.h"
#include "utils.h"

using std::sqrt;

class Vector3
{
public:
    Vector3();
    Vector3(real x, real y, real z);
    real x;
    real y;
    real z;

    Vector3 operator+(const Vector3& v);
    Vector3 operator-(const Vector3& v);
    Vector3 operator*(const Vector3& v);
    Vector3 operator*(const real& scalar);
    Vector3 operator/(const Vector3& v);
    Vector3 operator/(const real& v);
    void operator()(const Vector3& v);
    Vector3 projectOn(Vector3 v);
    Vector3 normalized();
    real getDistance(const Vector3& v);
    real magnitude();
    real sqrMagnitude();
    real dot(Vector3 other);
    std::string toString();
    void normalize();

    static Vector3 Random(real min, real max);
    static Vector3 Random();
};

class Vector2
{
public:
    Vector2();
    Vector2(real x, real y);
    real x;
    real y;

    Vector2 operator+(const Vector2& v);
    Vector2 operator-(const Vector2& v);
    Vector2 operator*(const Vector2& v);
    Vector2 operator*(const real& scalar);
    Vector2 operator/(const Vector2& v);
    Vector2 operator/(const real& v);
    Vector2 projectOn(Vector2 v);
    Vector2 normalized();
    real getDistance(const Vector2& v);
    real magnitude();
    real dot(Vector2 other);
    std::string toString();
    void normalize();
    void rotate(real angle);
};

using Color = Vector3;    // RGB color

#endif //RAYTRACER_VECTOR_H
