#pragma once
#include "IDrawable.h"

#define PIPE "***"

class FlappyPipe : IDrawable
{
#pragma region f/p
private:
	int gapPosition = 0;
	int position = 0;
	bool canDraw = false;
#pragma endregion
#pragma region constructor
public:
	FlappyPipe() = default;
	~FlappyPipe() override = default;
#pragma endregion
#pragma region methods
public:
	void SetGapPosition(const int _gap);
	void SetPosition(const int _gap);
	void SetCanDraw(const bool _status);
	int GapPosition() const;
	int Position() const;
	bool CanDraw() const;
#pragma endregion
#pragma region override
public:
	virtual void Draw() override;
	virtual void Erase() override;
	virtual void Update() override;
#pragma endregion
};

