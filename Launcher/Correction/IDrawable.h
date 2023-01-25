#pragma once
#include "Object.h"

class IDrawable : public Object
{
#pragma region constructor
public:
	~IDrawable() override = default;
#pragma endregion
#pragma region methods
public:
	virtual void Draw() = 0;
	virtual void Erase() = 0;
	virtual void Update() = 0;
#pragma endregion
};