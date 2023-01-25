#pragma once
#include <string>

class Quaternion
{
#pragma region f/p
private:
	float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;
	float w = 0.0f;
#pragma endregion
#pragma region constructor
public:
	Quaternion(const float _x, const float _y, const float _z, const float _w);
	Quaternion(const float _value);
	Quaternion(const Quaternion& _copy);
#pragma endregion
#pragma region methods
public:
	std::string ToString();
	/// <summary>
	/// The identity rotation
	/// </summary>
	/// <returns>quaternion</returns>
	static Quaternion Identity();
	/// <summary>
	/// Converts this quaternion to one with the same orientation but with a magnitude of 1.
	/// </summary>
	/// <param name="_q">quarternion</param>
	/// <returns>quaternion</returns>
	static Quaternion Normalize(Quaternion _value);
	/// <summary>
	/// returns the conjugate of a quaternion specifier
	/// </summary>
	/// <param name="_value">quaternion</param>
	/// <returns>quaternion</returns>
	static Quaternion Conjugate(Quaternion _value);
	/// <summary>
	/// Return the inverse of rotation
	/// </summary>
	/// <param name="_rotation">quaternion</param>
	/// <returns>quaternion</returns>
	static Quaternion Inverse(Quaternion _value);
	/// <summary>
	/// Reverses the sign of each component of the quaternion.
	/// </summary>
	/// <param name="_value">quaternion</param>
	/// <returns>quaternion</returns>
	static Quaternion Negate(Quaternion _value);
	/// <summary>
	/// Interpolates between a and b by t and normalizes the result afterwards.
	/// </summary>
	/// <param name="_a">quaternion</param>
	/// <param name="_b">quaternion</param>
	/// <param name="_t">float</param>
	/// <returns>quaternion</returns>
	static Quaternion Lerp(Quaternion _a, Quaternion _b, float _t);
	/// <summary>
	/// The dot product between two rotations.
	/// </summary>
	/// <param name="_a">quaternion</param>
	/// <param name="_b">quaternion</param>
	/// <returns>float</returns>
	static float Dot(Quaternion _a, Quaternion _b);
	/// <summary>
	/// Creates a quaternion from the given yaw, pitch, and roll.
	/// </summary>
	/// <param name="_yaw">float</param>
	/// <param name="_pitch">float</param>
	/// <param name="_roll">float</param>
	/// <returns>quaternion</returns>
	static Quaternion CreateFromYawPitchRoll(float _yaw, float _pitch, float _roll);
	/// <summary>
	/// Returns the angle in degrees between two rotations a and b
	/// </summary>
	/// <param name="_a">quaternion</param>
	/// <param name="_b">quaternion</param>
	/// <returns>quaternion</returns>
	static float Angle(Quaternion _a, Quaternion _b);
	/// <summary>
	/// Calculated length of the quaternion.
	/// </summary>
	/// <returns>float</returns>
	float Length() const;
	/// <summary>
	/// Calculate the square of the length of the quaternion.
	/// </summary>
	/// <returns>float</returns>
	float LengthSquared() const;
#pragma endregion
#pragma region operator
	float& operator[](const int _index);
	Quaternion operator+(const Quaternion& _other) const;
	Quaternion operator-(const Quaternion& _other) const;
	Quaternion operator*(const Quaternion& _other) const;
	Quaternion operator/(const Quaternion& _other) const;
	bool operator==(const Quaternion& _other) const;
	bool operator!=(const Quaternion& _other) const;
	Quaternion operator=(const Quaternion& _other);
#pragma endregion
};

