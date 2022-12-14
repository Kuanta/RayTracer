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

    Vector3 operator+(const Vector3& v) const;
    Vector3 operator-(const Vector3& v) const;
    Vector3 operator*(const Vector3& v) const;
    Vector3 operator/(const Vector3& v) const;
    Vector3 operator/(const real& v) const;
    void operator()(const Vector3& v);

    Vector3 projectOn(Vector3 v);
    Vector3 normalized();
    real getDimension(int index) const;
    real getDistance(const Vector3& v);
    real magnitude();
    real sqrMagnitude();
    real dot(const Vector3& other) const;
    Vector3 cross(const Vector3& other) const;
    std::string toString();
    void normalize();

    static Vector3 Random(real min, real max);
    static Vector3 Random();
    static bool NearZero(Vector3 vector);


};

inline Vector3 operator*(real t, const Vector3 &v) {
    return Vector3(t*v.x, t*v.y, t*v.z);
}

inline Vector3 operator*(const Vector3 &v, real t) {
    return Vector3(t*v.x, t*v.y, t*v.z);
}

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
