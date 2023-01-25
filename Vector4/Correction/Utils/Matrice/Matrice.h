#pragma once
#include "../Quaternion/Quaternion.h"
#include <iostream>

#define Epsilon 0.00001f

class Matrice
{
#pragma region f/p
private:
	float m11 = 0.0f;
	float m12 = 0.0f;
	float m13 = 0.0f;
	float m14 = 0.0f;
	float m21 = 0.0f;
	float m22 = 0.0f;
	float m23 = 0.0f;
	float m24 = 0.0f;
	float m31 = 0.0f;
	float m32 = 0.0f;
	float m33 = 0.0f;
	float m34 = 0.0f;
	float m41 = 0.0f;
	float m42 = 0.0f;
	float m43 = 0.0f;
	float m44 = 0.0f;
public:
	static const Matrice Identity;
#pragma endregion
#pragma region constructor
public:
	Matrice() = default;
	Matrice(float _m11, float _m12, float _m13, float _m14, float _m21,
		float _m22, float _m23, float _m24, float _m31, float _m32,
		float _m33, float _m34, float _m41, float _m42, float _m43, float _m44);
	Matrice(const Matrice& _copy);
#pragma endregion
#pragma region methods
public:
	std::string ToString();
	/// <summary>
	/// Creates a translation matrix from the specified X, Y, and Z components.
	/// </summary>
	/// <param name="_x">float</param>
	/// <param name="_y">float</param>
	/// <param name="_z">float</param>
	/// <returns>matrice</returns>
	static Matrice CreateTranslation(const float _x, const float _y, const float _z);
	/// <summary>
	/// Create a scaling matrix from the specified X, Y, and Z components.
	/// </summary>
	/// <param name="_x">float</param>
	/// <param name="_y">float</param>
	/// <param name="_z">float</param>
	/// <returns>matrice</returns>
	static Matrice CreateScale(const float _x, const float _y, const float _z);
	/// <summary>
	/// Creates a matrix to rotate points around the X axis.
	/// </summary>
	/// <param name="_rads">float</param>
	/// <returns>matrice</returns>
	static Matrice CreateRotationX(const float _rads);
	/// <summary>
	/// Creates a matrix to rotate points around the Y axis.
	/// </summary>
	/// <param name="_rads">float</param>
	/// <returns>matrice</returns>
	static Matrice CreateRotationY(const float _rads);
	/// <summary>
	/// Creates a matrix to rotate points around the Z axis.
	/// </summary>
	/// <param name="_rads">float</param>
	/// <returns>matrice</returns>
	static Matrice CreateRotationZ(const float _rads);
	/// <summary>
	/// Creates an orthographic perspective matrix from the dimensions of the specified view volume.
	/// </summary>
	/// <param name="_width">float</param>
	/// <param name="_height">float</param>
	/// <param name="_zNearPlane">float</param>
	/// <param name="_zFarPlane">float</param>
	/// <returns>matrice</returns>
	static Matrice CreateOrthographic(const float _width, const float _height, const float _zNearPlane, const float _zFarPlane);
	/// <summary>
	/// Creates a rotation matrix from the rotation value of the specified quaternion.
	/// </summary>
	/// <param name="_quaternion">quaternion</param>
	/// <returns>matrice</returns>
	static Matrice CreateFromQuaternion(const Quaternion _quaternion);
	/// <summary>
	/// Performs a linear interpolation from one matrix to a second matrix by a value that specifies the weight of the second matrix.
	/// </summary>
	/// <param name="_matrice1">matrice</param>
	/// <param name="_matrice2">matrice</param>
	/// <param name="_amount">float</param>
	/// <returns>matrice</returns>
	static Matrice Lerp(const Matrice& _a, const Matrice& _b, float _t);
	/// <summary>
	/// Computes the determinant of the current 4 x 4 matrix.
	/// </summary>
	/// <returns></returns>
	float GetDeterminant() const;
	static bool IsIdentity(const Matrice& _matrix);
	static Matrice CreateFromYawPitchRoll(const float _yaw, const float _pitch, const float _roll);
#pragma endregion
#pragma region operator
public:
	Matrice operator-() const;
	Matrice operator+(const Matrice& _other) const;
	Matrice operator-(const Matrice& _other) const;
	Matrice operator*(const Matrice& _other) const;
	bool operator==(const Matrice& _other) const;
	bool operator!=(const Matrice& _other) const;
#pragma endregion

};

