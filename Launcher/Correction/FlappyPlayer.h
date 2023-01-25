#pragma once
#include "IDrawable.h"

class FlappyPipe;

class FlappyPlayer : public IDrawable
{
#pragma region f/p
private:
	char bird[2][6] = { '/','-','-','o','\\',' ', '|','_','_','_',' ','>' };
	int position = 6;
	bool isDead = false;
#pragma endregion
#pragma region constructor
public:
	FlappyPlayer() = default;
	~FlappyPlayer() override = default;
#pragma endregion
#pragma region methods
public:
	int Position() const;
	bool IsDead() const;
	void SetPosition(const int _position);
	void SetDead(const bool _status);
	void Jump();
	bool IsCollide(const FlappyPipe* _pipe);
#pragma endregion 
#pragma region override
public:
	virtual void Draw() override;
	virtual void Erase() override;
	virtual void Update() override;
#pragma endregion

};

