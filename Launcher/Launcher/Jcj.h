#pragma once
#include "Menu.h"
#include "GameMorpion.h"

class Jcj : public Menu
{
#pragma region f/p
private:
	GameMorpion* gameMorpion = new GameMorpion();
#pragma endregion 
#pragma region constructor
public:
	Jcj();
#pragma endregion 
#pragma region methods
public:
	void Open() override;
#pragma endregion
};

