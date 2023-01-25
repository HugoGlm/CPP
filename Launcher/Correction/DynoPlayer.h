#pragma once
#include "IDrawable.h"
#include "DynoGame.h"

class DynoPlayer : public IDrawable
{
private:
	char Dyno[5][7] = {' ',' ',' ',' ','_','_',' ',
					   ' ',' ',' ','|','_','_','|',
					   ' ',' ','_','|','_','|','_',
					   '|','_','|','_','_','|',' ',
					   ' ',' ',' ','|',' ','|',' '};
	int position = SCREEN_HEIGHT - 5;
	bool isDead = false;
#pragma endregion
#pragma region constructor
public:
	DynoPlayer() = default;
	~DynoPlayer() override = default;
#pragma endregion
#pragma region methods
public:
	int Position() const;
	bool IsDead() const;
	void SetPosition(const int _position);
	void SetDead(const bool _status);
	void Jump();
	bool IsCollide(const DynoPipe* _pipe);
#pragma endregion 
#pragma region override
public:
	virtual void Draw() override;
	virtual void Erase() override;
	virtual void Update() override;
#pragma endregion
};

