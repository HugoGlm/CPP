#pragma once
#include "../Menu.h"

class MarqueMenu : public Menu
{
#pragma region constructor
public:
	MarqueMenu();
#pragma endregion constructor
#pragma region override
public:
	void Open() override;
#pragma endregion override
};

