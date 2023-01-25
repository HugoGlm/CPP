#pragma once
#include "../Menu.h"

class ModelePeugeotMenu : public Menu
{
#pragma region constructor
public:
	ModelePeugeotMenu();
#pragma endregion constructor
#pragma region override
public:
	/// <summary>
	/// execute menu
	/// </summary>
	void Open() override;
#pragma endregion override
};