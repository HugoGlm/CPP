#pragma once
#include <string>

class Object
{
#pragma region constructor
public:
	Object() = default;
	virtual ~Object() = default;
#pragma endregion
#pragma region methods
public:
	virtual std::string ToString() const;
};
#pragma endregion
