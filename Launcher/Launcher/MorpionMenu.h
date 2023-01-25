#pragma once
#include "Menu.h"

class MorpionMenu : public Menu
{
#pragma region constructor
public:
	MorpionMenu();
#pragma endregion 
#pragma region methods
public:
	void Open() override;
#pragma endregion
};

