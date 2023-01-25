#pragma once
#include "Object.h"

class Menu;

class MenuItem : public Object
{
#pragma region f/p
public:
	std::string name = "";
	Menu* nextMenu = nullptr;
#pragma endregion
#pragma region constructor
public:
	MenuItem() = default;
	MenuItem(const std::string& _name, Menu* _owner);
	MenuItem(const MenuItem& _copy);
	~MenuItem() override = default;
#pragma endregion
#pragma region methods
public:
	void OnClick(Menu* _currentMenu);
	std::string Name();
	Menu* NextMenu() const;
#pragma endregion
#pragma region override
public:
	std::string ToString() const override;
#pragma endregion
};

