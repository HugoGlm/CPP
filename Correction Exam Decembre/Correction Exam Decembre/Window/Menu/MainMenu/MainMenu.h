#pragma once
#include "../BaseMenu.h"

class MainMenu : public BaseMenu
{
	DECLARE_CLASS_INFO(BaseMenu)
#pragma region constructor
public:
	MainMenu() = default;
	MainMenu(Window* _owner);
	MainMenu(const MainMenu& _copy) = default;
#pragma endregion
#pragma region methods
public:
	void OpenBookingMenu();
	void OpenBookingViewMenu();
#pragma endregion
#pragma region override
public:
	void Initialize();
#pragma endregion

};

