#include "Quaternion.h"
#include "../Mathf/Mathf.h"
#include "../Macro/AssertMacro.h"
#include <format>
#include <iostream>

#pragma region constructor
Quaternion::Quaternion(const float _x, const float _y, const float _z, const float _w)
{
    x = _x;
    y = _y;
    z = _z;
    w = _w;
}
Quaternion::Quaternion(const float _value)
{
    x = y = z = w = _value;
}
Quaternion::Quaternion(const Quaternion& _copy)
{
    x = _copy.x;
    y = _copy.y;
    z = _copy.z;
    w = _copy.w;
}
#pragma endregion
#pragma region methods
std::string Quaternion::ToString()
{
    return std::format("x: {}, y: {}, z: {}, w: {}", x, y, z, w);
}
Quaternion Quaternion::Identity()
{
    return Quaternion(0, 0, 0, 1);
}
Quaternion Quaternion::Normalize(Quaternion _value)
{
    float _l = _value.Length();
    return Quaternion(
        _value.x / _l,
        _value.y / _l,
        _value.z / _l,
        _value.w / _l
    );
}
Quaternion Quaternion::Conjugate(Quaternion _value)
{
    return Quaternion(
    -_value.x,
    -_value.y,
    -_value.z,
    _value.w
    );
}
Quaternion Quaternion::Inverse(Quaternion _value)
{
    float _l = pow(_value.LengthSquared(), 1 / 2) * _value.LengthSquared();
    return Quaternion(-_value.x / _l,
                     -_value.y / _l,
                     -_value.z / _l,
                     _value.w / _l
                     );
}
Quaternion Quaternion::Negate(Quaternion _value)
{
    return Quaternion(-_value.x, -_value.y, -_value.z, -_value.w);
}
Quaternion Quaternion::Lerp(Quaternion _a, Quaternion _b, float _t)
{
    return Normalize(Quaternion(
        _a.x + (_b.x - _a.x) * _t,
        _a.y + (_b.y - _a.y) * _t,
        _a.z + (_b.z - _a.z) * _t,
        _a.w + (_b.w - _a.w) * _t
    ));
}
float Quaternion::Dot(Quaternion _a, Quaternion _b)
{
    return _a.x * _b.x + _a.y * _b.y + _a.z * _b.z + _a.w * _b.w;
}
Quaternion Quaternion::CreateFromYawPitchRoll(float _yaw, float _pitch, float _roll)
{
    return Quaternion(0);
}
float Quaternion::Angle(Quaternion _a, Quaternion _b)
{
    return 0;
}
float Quaternion::Length() const
{
    return Mathf::Sqrt(Dot(*this, *this));
}
float Quaternion::LengthSquared() const
{
    return Dot(*this, *this);
}
#pragma endregion
#pragma region operator
float& Quaternion::operator[](const int _index)
{
    check(_index > 0 || _index < 4);
    switch (_index)
    {
    case 0:
        return x;
    case 1:
        return y;
    case 2:
        return z;
    case 3:
        return w;
    };
}
Quaternion Quaternion::operator+(const Quaternion& _other) const
{
    return Quaternion(x + _other.x, y + _other.y, z + _other.z, w + _other.w);
}
Quaternion Quaternion::operator-(const Quaternion& _other) const
{
    return Quaternion(x - _other.x, y - _other.y, z - _other.z, w - _other.w);
}
Quaternion Quaternion::operator*(const Quaternion& _other) const
{
    return Quaternion(x * _other.x, y * _other.y, z * _other.z, w * _other.w);
}
Quaternion Quaternion::operator/(const Quaternion& _other) const
{
    return Quaternion(x / _other.x, y / _other.y, z / _other.z, w / _other.w);
}
Quaternion Quaternion::operator=(const Quaternion& _other)
{
    x = _other.x;
    y = _other.y;
    z = _other.z;
    w = _other.w;
    return *this;
}
bool Quaternion::operator==(const Quaternion& _other) const
{
    return x == _other.x && y == _other.y && z == _other.z && w == _other.w;
}
bool Quaternion::operator!=(const Quaternion& _other) const
{
    return x != _other.x && y != _other.y && z != _other.z && w != _other.w;
}
#pragma endregion
