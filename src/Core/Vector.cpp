#include "Vector.h"

//Vector3
Vector3::Vector3()
{
    this->x = 0.0f;
    this->y = 0.0f;
    this->z = 0.0f;
}
Vector3::Vector3(real x, real y, real z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector3 Vector3::operator+(const Vector3& v) const
{
    return Vector3(this->x+v.x,this->y+v.y,this->z+v.z);
}


Vector3 Vector3::operator-(const Vector3& v) const
{
    return Vector3(this->x-v.x,this->y-v.y,this->z-v.z);
}
Vector3 Vector3::operator*(const Vector3& v) const
{
    return Vector3(this->x*v.x,this->y*v.y,this->z*v.z);
}

Vector3 Vector3::operator/(const Vector3& v) const
{
    return Vector3(this->x/v.x, this->y/v.y, this->z/v.z);
}
Vector3 Vector3::operator/(const real& v) const
{
    return Vector3(this->x/v, this->y/v, this->z/v);
}
void Vector3::operator()(const Vector3& v)
{
    this->x = v.x;
    this->y = v.y;
    this->z = v.z;
}
Vector3 Vector3::normalized()
{
    real mag = this->magnitude();
    return Vector3(this->x / mag, this->y / mag, this->z / mag);
}
real Vector3::getDimension(int index) const{
    switch (index) {
        case 0:
            return x;
        case 1:
            return y;
        case 2:
            return z;
        default:
            return x;
    }
}
Vector3 Vector3::projectOn(Vector3 v)
{
    Vector3 normV = v.normalized();
    real mag = v.magnitude();
    return normV*(normV.dot(*this)*mag);
}
real Vector3::getDistance(const Vector3& v)
{
    Vector3 diff = *this - v;
    return sqrt(diff.magnitude());
}
real Vector3::magnitude()
{
    return sqrt(x*x + y*y + z*z);
}
real Vector3::sqrMagnitude()
{
    return this->x*this->x + this->y*this->y + this->z*this->z;
}
real Vector3::dot(const Vector3& other) const
{
    return (x*other.x + y*other.y + z*other.z);
}

Vector3 Vector3::cross(const Vector3& other) const
{
    return Vector3(y * other.z - z * other.y,
                z * other.x - x * other.z,
                x * other.y - y * other.x);
}


std::string Vector3::toString()
{
    char str[30];
    sprintf(str, "X:%f Y:%f Z:%f", x, y, z);
    return std::string(str);
}
void Vector3::normalize()
{
    real mag = this->magnitude();
    this->x = this->x / mag;
    this->y = this->y / mag;
    this->z = this->z / mag;
}

Vector3 Vector3::Random()
{
    return Vector3(RayMath::Random(), RayMath::Random(), RayMath::Random());
}

Vector3 Vector3::Random(real min, real max)
{
    return Vector3(RayMath::Random(min, max), RayMath::Random(min, max), RayMath::Random(min, max));
}

bool Vector3::NearZero(Vector3 vector)
{
    const real epsilon = 1e-8;
    return (fabs(vector.x) < epsilon) && (fabs(vector.y) < epsilon) && (fabs(vector.z) < epsilon);
}

//Vector2
Vector2::Vector2()
{
    this->x = 0.0f;
    this->y = 0.0f;
}
Vector2::Vector2(real x, real y)
{
    this->x = x;
    this->y = y;
}

Vector2 Vector2::operator+(const Vector2& v)
{
    return Vector2(this->x+v.x,this->y+v.y);
}


Vector2 Vector2::operator-(const Vector2& v)
{
    return Vector2(this->x-v.x,this->y-v.y);
}
Vector2 Vector2::operator*(const Vector2& v)
{
    return Vector2(this->x*v.x,this->y*v.y);
}
Vector2 Vector2::operator*(const real& scalar)
{
    return Vector2(this->x*scalar,this->y*scalar);
}
Vector2 Vector2::operator/(const Vector2& v)
{
    return Vector2(this->x/v.x, this->y/v.y);
}
Vector2 Vector2::operator/(const real& v)
{
    return Vector2(this->x/v, this->y/v);
}
Vector2 Vector2::normalized()
{
    real mag = this->magnitude();
    return Vector2(this->x / mag, this->y / mag);
}
Vector2 Vector2::projectOn(Vector2 v)
{
    Vector2 normV = v.normalized();
    real mag = v.magnitude();
    return normV*(normV.dot(*this)*mag);
}
real Vector2::getDistance(const Vector2& v)
{
    Vector2 diff = *this - v;
    return sqrt(diff.magnitude());
}
real Vector2::magnitude()
{
    return sqrt(this->x*this->x + this->y*this->y);
}
real Vector2::dot(Vector2 other)
{
    return (x*other.x + y*other.y);
}
std::string Vector2::toString()
{
    char str[30];
    sprintf(str, "X:%f Y:%f", x, y);
    return std::string(str);
}
void Vector2::normalize()
{
    real mag = this->magnitude();
    this->x = this->x / mag;
    this->y = this->y / mag;
}
void Vector2::rotate(real angle)
{
    float x = cos(angle)*this->x - sin(angle)*this->y;
    float y = sin(angle)*this->x + cos(angle)*this->y;
    this->x = x;
    this->y = y;
}