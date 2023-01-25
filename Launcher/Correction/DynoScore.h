#pragma once
#include "IDrawable.h"

class DynoScore : IDrawable
{
#pragma region f/p
private:
	int score = 0;
#pragma endregion 
#pragma region constructor
public:
	DynoScore() = default;
	~DynoScore() override = default;
#pragma endregion 
#pragma region override
public:
	virtual void Draw() override;
	virtual void Erase() override;
	virtual void Update() override;
#pragma endregion
#pragma region operator
public:
	operator int() const;
	DynoScore& operator=(const int _value);
	DynoScore& operator+=(const int _value);
#pragma endregion

};

