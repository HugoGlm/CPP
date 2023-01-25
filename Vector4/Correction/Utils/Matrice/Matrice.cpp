#include "Matrice.h"
#include "../Macro/AssertMacro.h"
#include "../Quaternion/Quaternion.h"
#include "../Mathf/Mathf.h"

#pragma region constructor
Matrice::Matrice(float _m11, float _m12, float _m13, float _m14, float _m21, float _m22, float _m23, float _m24, float _m31, float _m32, float _m33, float _m34, float _m41, float _m42, float _m43, float _m44)
{
	m11 = _m11;
	m12 = _m12;
	m13 = _m13;
	m14 = _m14;
	m21 = _m21;
	m22 = _m22;
	m23 = _m23;
	m24 = _m24;
	m31 = _m31;
	m32 = _m32;
	m33 = _m33;
	m34 = _m34;
	m41 = _m41;
	m42 = _m42;
	m43 = _m43;
	m44 = _m44;
}
Matrice::Matrice(const Matrice& _copy)
{
	m11 = _copy.m11;
	m12 = _copy.m12;
	m13 = _copy.m13;
	m14 = _copy.m14;
	m21 = _copy.m21;
	m22 = _copy.m22;
	m23 = _copy.m23;
	m24 = _copy.m24;
	m31 = _copy.m31;
	m32 = _copy.m32;
	m33 = _copy.m33;
	m34 = _copy.m34;
	m41 = _copy.m41;
	m42 = _copy.m42;
	m43 = _copy.m43;
	m44 = _copy.m44;
}
#pragma endregion

#pragma region f/p
Matrice const Matrice::Identity = Matrice(
	1.0f, 0.0f, 0.0f, 0.0f,
	0.0f, 1.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 1.0f, 0.0f,
	0.0f, 0.0f, 0.0f, 1.0f
);
#pragma endregion

#pragma region methods
std::string Matrice::ToString()
{
	return std::format("(m11: {} m12: {} m13: {} m14: {}) (m21: {} m22: {} m23: {} m24: {}) (m31: {} m32: {} m33: {} m34: {}) (m41: {} m42: {} m43: {} m44: {})", m11, m12, m13, m14, m21, m22, m23, m24, m31, m32, m33, m34, m41, m42, m43, m44);
}
Matrice Matrice::CreateTranslation(const float _x, const float _y, const float _z)
{
	Matrice _res = Identity;
	_res.m41 = _x;
	_res.m42 = _y;
	_res.m43 = _z;
	return _res;
}
Matrice Matrice::CreateScale(const float _x, const float _y, const float _z)
{
	Matrice _res = Identity;
	_res.m11 = _x;
	_res.m22 = _y;
	_res.m33 = _z;
	return _res;
}
Matrice Matrice::CreateRotationX(const float _rads)
{
	Matrice _res = Identity;
	const float _cos = Mathf::Cos(_rads);
	const float _sin = Mathf::Sin(_rads);
	_res.m22 = _cos;
	_res.m23 = _sin;
	_res.m32 = -_sin;
	_res.m33 = _cos;
	return _res;
}
Matrice Matrice::CreateRotationY(const float _rads)
{
	Matrice _res = Identity;
	const float _cos = Mathf::Cos(_rads);
	const float _sin = Mathf::Sin(_rads);
	_res.m11 = _cos;
	_res.m13 = -_sin;
	_res.m31 = _sin;
	_res.m33 = _cos;
	return _res;
}
Matrice Matrice::CreateRotationZ(const float _rads)
{
	Matrice _res = Identity;
	const float _cos = Mathf::Cos(_rads);
	const float _sin = Mathf::Sin(_rads);
	_res.m11 = _cos;
	_res.m12 = _sin;
	_res.m21 = -_sin;
	_res.m22 = _cos;
	return _res;
}
Matrice Matrice::CreateOrthographic(const float _width, const float _height, const float _zNearPlane, const float _zFarPlane)
{
	Matrice _res = Identity;
	_res.m11 = 2 / _width;
	_res.m22 = 2 / _height;
	_res.m33 = 1 / (_zNearPlane - _zFarPlane);
	_res.m43 = _zNearPlane / (_zNearPlane + _zFarPlane);
	return _res;
}
Matrice Matrice::CreateFromQuaternion(const Quaternion _quaternion)
{
	Matrice _res = Identity;
	float _x = _quaternion.x;
	float _y = _quaternion.y;
	float _z = _quaternion.z;
	float _w = _quaternion.w;

	_res.m11 = 1.0f - 2 * (_y * _y) - 2 * (_z * _z);
	_res.m12 = (2 * _x * _y) + (2 * _z * _w);
	_res.m13 = (2 * _x * _z) - (2 * _y * _w);

	_res.m21 = (2 * _x * _y) - (2 * _z * _w);
	_res.m22 = 1.0f - 2 * (_x * _x) - 2 * (_z * _z);
	_res.m23 = (2 * _y * _z) + (2 * _x * _w);

	_res.m31 = (2 * _x * _z) + (2 * _y * _w);
	_res.m32 = (2 * _y * _z) - (2 * _x * _w);
	_res.m33 = 1.0f - 2 * (_y * _y) - 2 * (_y * _y);

	return _res;
}
Matrice Matrice::Lerp(const Matrice& _a, const Matrice& _b, float _t)
{
	Matrice _result = Matrice();

	_result.m11 = _a.m11 + (_b.m11 - _a.m11) * _t;
	_result.m12 = _a.m12 + (_b.m12 - _a.m12) * _t;
	_result.m13 = _a.m13 + (_b.m13 - _a.m13) * _t;
	_result.m14 = _a.m14 + (_b.m14 - _a.m14) * _t;

	_result.m21 = _a.m21 + (_b.m21 - _a.m21) * _t;
	_result.m22 = _a.m22 + (_b.m22 - _a.m22) * _t;
	_result.m23 = _a.m23 + (_b.m23 - _a.m23) * _t;
	_result.m24 = _a.m24 + (_b.m24 - _a.m24) * _t;

	_result.m31 = _a.m31 + (_b.m31 - _a.m31) * _t;
	_result.m32 = _a.m32 + (_b.m32 - _a.m32) * _t;
	_result.m33 = _a.m33 + (_b.m33 - _a.m33) * _t;
	_result.m34 = _a.m34 + (_b.m34 - _a.m34) * _t;

	_result.m41 = _a.m41 + (_b.m41 - _a.m41) * _t;
	_result.m42 = _a.m42 + (_b.m42 - _a.m42) * _t;
	_result.m43 = _a.m43 + (_b.m43 - _a.m43) * _t;
	_result.m44 = _a.m44 + (_b.m44 - _a.m44) * _t;

	return _result;
}
float Matrice::GetDeterminant() const
{
	const float _a = m11, _b = m12, _c = m13, _d = m14,
		_e = m11, _f = m12, _g = m13, _h = m14,
		_i = m11, _j = m12, _k = m13, _l = m14,
		_m = m11, _n = m12, _o = m13, _p = m14,

		const float _kplo = _k * _p - _l * _o;
	const float _jpln = _j * _p - _l * _n;
	const float _jokn = _j * _o - _k * _n;
	const float _iplm = _i * _p - _l * _m;
	const float _iokm = _i * _o - _k * _m;
	const float _injm = _i * _n - _j * _m;

	return _a * (_f * _kplo - _g * _jpln + _h * _jokn) -
		_b * (_e * _kplo - _h * _iplm + _h * _iokm) +
		_c * (_e * _jpln - _f * _iplm + _h * _jokn) -
		_d * (_e * _jokn - _f * _iokm + _g * _injm);

}
Matrice Matrice::CreateFromYawPitchRoll(const float _yaw, const float _pitch, const float _roll)
{
	return CreateFromQuaternion(Quaternion::CreateFromYamPitchRoll(_yaw, _pitch, _roll));
}
bool Matrice::IsIdentity(const Matrice& _matrix)
{
	return _matrix == Matrice::Identity;
}
#pragma endregion

#pragma region operator
Matrice Matrice::operator-() const
{
	Matrice _result = Matrice();
	_result.m11 = -m11;
	_result.m12 = -m12;
	_result.m13 = -m13;
	_result.m14 = -m14;
	_result.m21 = -m21;
	_result.m22 = -m22;
	_result.m23 = -m23;
	_result.m24 = -m24;
	_result.m31 = -m31;
	_result.m32 = -m32;
	_result.m33 = -m33;
	_result.m34 = -m34;
	_result.m41 = -m41;
	_result.m42 = -m42;
	_result.m43 = -m43;
	_result.m44 = -m44;
	return _result;
}
Matrice Matrice::operator+(const Matrice& _other) const
{
	Matrice _result = Matrice();
	_result.m11 = m11 + _other.m11;
	_result.m12 = m12 + _other.m12;
	_result.m13 = m13 + _other.m13;
	_result.m14 = m14 + _other.m14;
	_result.m21 = m21 + _other.m21;
	_result.m22 = m22 + _other.m22;
	_result.m23 = m23 + _other.m23;
	_result.m24 = m24 + _other.m24;
	_result.m31 = m31 + _other.m31;
	_result.m32 = m32 + _other.m32;
	_result.m33 = m33 + _other.m33;
	_result.m34 = m34 + _other.m34;
	_result.m41 = m41 + _other.m41;
	_result.m42 = m42 + _other.m42;
	_result.m43 = m43 + _other.m43;
	_result.m44 = m44 + _other.m44;
	return _result;
}
Matrice Matrice::operator-(const Matrice& _other) const
{
	Matrice _result = Matrice();
	_result.m11 = m11 - _other.m11;
	_result.m12 = m12 - _other.m12;
	_result.m13 = m13 - _other.m13;
	_result.m14 = m14 - _other.m14;
	_result.m21 = m21 - _other.m21;
	_result.m22 = m22 - _other.m22;
	_result.m23 = m23 - _other.m23;
	_result.m24 = m24 - _other.m24;
	_result.m31 = m31 - _other.m31;
	_result.m32 = m32 - _other.m32;
	_result.m33 = m33 - _other.m33;
	_result.m34 = m34 - _other.m34;
	_result.m41 = m41 - _other.m41;
	_result.m42 = m42 - _other.m42;
	_result.m43 = m43 - _other.m43;
	_result.m44 = m44 - _other.m44;
	return _result;
}
Matrice Matrice::operator*(const Matrice& _other) const
{
	Matrice _result = Matrice();
	_result.m11 = m11 * _other.m11 + m12 * _other.m21 + m13 * _other.m31 + m14 * _other.m41;
	_result.m12 = m11 * _other.m12 + m12 * _other.m22 + m13 * _other.m32 + m14 * _other.m42;
	_result.m13 = m11 * _other.m13 + m12 * _other.m23 + m13 * _other.m33 + m14 * _other.m43;
	_result.m14 = m11 * _other.m14 + m12 * _other.m24 + m13 * _other.m34 + m14 * _other.m44;

	_result.m21 = m21 * _other.m11 + m22 * _other.m21 + m23 * _other.m31 + m24 * _other.m41;
	_result.m22 = m21 * _other.m12 + m22 * _other.m22 + m23 * _other.m32 + m24 * _other.m42;
	_result.m23 = m21 * _other.m13 + m22 * _other.m23 + m23 * _other.m33 + m24 * _other.m43;
	_result.m24 = m21 * _other.m14 + m22 * _other.m24 + m23 * _other.m34 + m24 * _other.m44;

	_result.m31 = m31 * _other.m11 + m32 * _other.m21 + m33 * _other.m31 + m34 * _other.m41;
	_result.m32 = m31 * _other.m12 + m32 * _other.m22 + m33 * _other.m32 + m34 * _other.m42;
	_result.m33 = m31 * _other.m13 + m32 * _other.m23 + m33 * _other.m33 + m34 * _other.m43;
	_result.m34 = m31 * _other.m14 + m32 * _other.m24 + m33 * _other.m34 + m34 * _other.m44;

	_result.m41 = m41 * _other.m11 + m42 * _other.m21 + m43 * _other.m31 + m44 * _other.m41;
	_result.m42 = m41 * _other.m12 + m42 * _other.m22 + m43 * _other.m32 + m44 * _other.m42;
	_result.m43 = m41 * _other.m13 + m42 * _other.m23 + m43 * _other.m33 + m44 * _other.m43;
	_result.m44 = m41 * _other.m14 + m42 * _other.m24 + m43 * _other.m34 + m44 * _other.m44;

	return _result;
}
bool Matrice::operator==(const Matrice& _other) const
{
	return m11 == _other.m11 &&
		m12 == _other.m12 &&
		m13 == _other.m13 &&
		m14 == _other.m14 &&
		m21 == _other.m21 &&
		m22 == _other.m22 &&
		m23 == _other.m23 &&
		m24 == _other.m24 &&
		m31 == _other.m31 &&
		m32 == _other.m32 &&
		m33 == _other.m33 &&
		m34 == _other.m34 &&
		m41 == _other.m41 &&
		m42 == _other.m42 &&
		m43 == _other.m43 &&
		m44 == _other.m44;
}
bool Matrice::operator!=(const Matrice& _other) const
{
	return !(*this == _other);
}
#pragma endregion
