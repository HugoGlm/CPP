#pragma once
#include "O3DLibrary.h"

struct O3DLIBRARY_API Parameterinfo
{
#pragma region f/p
private:
	const char* name = "";
	const char* typeName = "";
	int position = 0;
#pragma endregion
#pragma region constructor
public:
	Parameterinfo(const char* _name, const char* _typeName, int _position)
	{
		name = _name;
		typeName = _typeName;
		position = _position;
	}
#pragma endregion
#pragma region methods
public:
	const char* TypeName() const
	{
		return typeName;
	}
	int Position() const
	{
		return position;
	}
#pragma endregion
};