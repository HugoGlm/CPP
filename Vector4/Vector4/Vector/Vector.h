#pragma once

class Vector
{
#pragma region f/p
private:
	float w = 0.0f, x = 0.0f, y = 0.0f, z = 0.0f;
#pragma endregion
#pragma region constructor
public:
	Vector() = default;
	Vector(const float _w, const float _x, const float _y, const float _z);
	Vector(const Vector& _copy);
#pragma endregion
#pragma region methods
public:
	Vector Add(Vector _a, Vector _b) const;
	Vector Clamp(const Vector& _val, const Vector& _min, const Vector& _max) const;
	Vector Min() const;
	Vector Max() const;
	Vector Absolute() const;
	Vector lerp(Vector _a, Vector _b, float _t) const;
	Vector lerpUnClamp(Vector _a, Vector _b, float _t) const;
	float Dot(Vector _a, Vector _b) const;
	float Magnitude() const;
	float Distance(Vector _a, Vector _b) const;
	float Lenght() const;
	float LenghtSqr() const;
	void Set(float _nexX, float _newY, float _nexZ, float _newW) const;
	void Display();
	void Normalize();
#pragma endregion
#pragma region operator
public:
	Vector operator+(const Vector& _other);
	Vector operator+=(const Vector& _other);
	Vector operator-(const Vector& _other);
	Vector operator-=(const Vector& _other);
	Vector operator*(const Vector& _other);
	Vector operator*=(const Vector& _other);
	Vector operator/(const Vector& _other);
	Vector operator/=(const Vector& _other);
	bool operator==(const Vector& _other);
	bool operator<(const Vector& _other) const;
	bool operator<=(const Vector& _other);
	bool operator>(const Vector& _other) const;
	bool operator>=(const Vector& _other);
#pragma endregion

};

