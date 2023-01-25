#pragma once

class Mathf
{
#pragma region methods
public:
	template<typename T>
	static T Clamp(const T& _current, const T& _min, const T& _max);
	static float Sqrt(const float _value);
	static float Abs(const float _value);
	static float Clamp01(const float _value);
#pragma endregion

};

template<typename T>
inline T Mathf::Clamp(const T& _current, const T& _min, const T& _max)
{
	if (_current < _min)
		return _min;
	if (_current > _max)
		return _max;
	return _current;
}
