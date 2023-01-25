#pragma once
#include "../Menu.h"

class ModeleRenaultMenu : public Menu
{
#pragma region constructor
public:
	ModeleRenaultMenu();
#pragma endregion constructor
#pragma region override
public:
	/// <summary>
	/// execute menu
	/// </summary>
	void Open() override;
#pragma endregion override
};