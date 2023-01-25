#pragma once
class Quaternion
{
#pragma region f/p
private:
	const float epsilon = 0.000001f;
	float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;
	float w = 0.0f;
#pragma endregion
#pragma region constrution
public:
	Quaternion(const float _x, const float _y, const float _z, const float _w);
	Quaternion(const Quaternion& _copy);
#pragma endregion

};

