#pragma once
#include "MapDataBase.h"

class Vector2;

class Case
{
#pragma region f/p
private:
	char caseValue = ' ';
	Vector2* position = nullptr;
#pragma endregion
#pragma region constructor
public:
	Case() = default;
	Case(const char _value, Vector2* _position);
	Case(const Case& _copy);
	virtual ~Case();
#pragma endregion
#pragma region methods
public:
	bool IsWall() const;
	bool HasMob() const;
	bool IsEnter() const;
	bool IsExit() const;
	char CaseValue() const;
	Vector2* Position() const;
#pragma endregion 
};

