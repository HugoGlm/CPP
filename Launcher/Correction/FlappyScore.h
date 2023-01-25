#pragma once
#include "IDrawable.h"

class FlappyScore : IDrawable
{
#pragma region f/p
private:
	int score = 0;
#pragma endregion 
#pragma region constructor
public:
	FlappyScore() = default;
	~FlappyScore() override = default;
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
	FlappyScore& operator=(const int _value);
	FlappyScore& operator+=(const int _value);
#pragma endregion

};

