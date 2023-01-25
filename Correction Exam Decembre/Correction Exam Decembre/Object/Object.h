#pragma once
#include <string>

#define DECLARE_CLASS_INFO(parent) \
	public: \
		typedef parent super;

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
#pragma endregion

};

