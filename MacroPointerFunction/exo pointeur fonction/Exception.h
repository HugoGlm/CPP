#pragma once
#include "Object.h"
#include <source_location>

class Exception : public Object
{
#pragma region f/p
public:
	std::string error = "";
#pragma endregion
#pragma region constructor
public:
	Exception(const std::source_location& _location = std::source_location::current());
	Exception(const std::string& _error, const std::source_location& _location = std::source_location::current());
#pragma endregion
#pragma region override
public:
	std::string ToString() const override;
#pragma endregion
};

