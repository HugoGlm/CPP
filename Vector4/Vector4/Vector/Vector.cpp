#include "Vector.h"
#include <math.h>
#include <format>
#include <iostream>

#pragma region constructor
Vector::Vector(const float _w, const float _x, const float _y, const float _z)
{
    w = _w;
    x = _x;
    y = _y;
    z = _z;
}
Vector::Vector(const Vector& _copy)
{
    w = _copy.w;
    x = _copy.x;
    y = _copy.y;
    z = _copy.z;
}
#pragma endregion
#pragma region methods
Vector Vector::Add(Vector _a, Vector _b) const
{
    float _newW = _a.w + _b.w;
    float _newX = _a.x + _b.x;
    float _newY = _a.y + _b.y;
    float _newZ = _a.z + _b.z;
    return Vector(_newW, _newX, _newY, _newZ);
}
Vector Vector::Clamp(const Vector& _val, const Vector& _min, const Vector& _max) const
{
    return Vector();
}
Vector Vector::Min() const
{
    return Vector();
}
Vector Vector::Max() const
{
    return Vector();
}
Vector Vector::Absolute() const
{
    float _resW = abs(w);
    float _resX = abs(x);
    float _resY = abs(y);
    float _resZ = abs(z);
    return Vector(_resW, _resX, _resY, _resZ);
}
Vector Vector::lerp(Vector _a, Vector _b, float _t) const
{
    if (_t <= 0)
        return _a;
    else if (_t >= 1)
        return _b;
   /* else
        return Vector((_b.x - _a.x), (_b.y - _a.y), (_b.w - _a.w), (_b.z - _a.z));*/
}
Vector Vector::lerpUnClamp(Vector _a, Vector _b, float _t) const
{
    return Vector();
}
float Vector::Distance(Vector _a, Vector _b) const
{
    return (_b.x - _a.x) + (_b.y - _a.y) + (_b.w - _a.w) + (_b.z - _a.z);
}
float Vector::Lenght() const
{
    return sqrt(w * w + x * x + y * y + z * z);
}
float Vector::LenghtSqr() const
{
    return x * x + y * y + w * w + z * z;
}
float Vector::Dot(Vector _a, Vector _b) const
{
    //float _cos = ((_a.x * _b.x) + (_a.y * _b.y) + (_a.z * _b.z)) / (sqrt(pow(_a.x, 2) + pow(_a.y, 2) + pow(_a.z, 2)) * (sqrt(pow(_b.x, 2) + pow(_b.y, 2) + pow(_b.z, 2))));
    return _a.Lenght() * _b.Lenght(); //* _cos;
}
float Vector::Magnitude() const
{
    return Lenght();
}
void Vector::Set(float _nexX, float _newY, float _nexZ, float _newW) const
{

}
void Vector::Display()
{
    std::cout << w << ", " << x << ", " << y << ", " << z << std::endl;
}
void Vector::Normalize()
{
}
#pragma endregion
#pragma region operator
Vector Vector::operator+(const Vector& _other)
{
    w + _other.w;
    x + _other.x;
    y + _other.y;
    z + _other.z;
    return *this;
}
Vector Vector::operator+=(const Vector& _other)
{
    w += _other.w;
    x += _other.x;
    y += _other.y;
    z += _other.z;
    return *this;
}
Vector Vector::operator-(const Vector& _other)
{
    w - _other.w;
    x - _other.x;
    y - _other.y;
    z - _other.z;
    return *this;
}
Vector Vector::operator-=(const Vector& _other)
{
    w -= _other.w;
    x -= _other.x;
    y -= _other.y;
    z -= _other.z;
    return *this;
}
Vector Vector::operator*(const Vector& _other)
{
    w * _other.w;
    x * _other.x;
    y * _other.y;
    z * _other.z;
    return *this;
}
Vector Vector::operator*=(const Vector& _other)
{
    w *= _other.w;
    x *= _other.x;
    y *= _other.y;
    z *= _other.z;
    return *this;
}
Vector Vector::operator/(const Vector& _other)
{
    w / _other.w;
    x / _other.x;
    y / _other.y;
    z / _other.z;
    return *this;
}
Vector Vector::operator/=(const Vector& _other)
{
    w /= _other.w;
    x /= _other.x;
    y /= _other.y;
    z /= _other.z;
    return *this;
}
bool Vector::operator==(const Vector& _other)
{
    return false;
}
bool Vector::operator<(const Vector& _other) const
{
    return false;
}
bool Vector::operator<=(const Vector& _other)
{
    return false;
}
bool Vector::operator>(const Vector& _other) const
{
    return false;
}
bool Vector::operator>=(const Vector& _other)
{
    return false;
}
#pragma endregion