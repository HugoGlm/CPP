#pragma once
#include "../../Object/Object.h"

class Menu;

class MenuItem : public Object
{
#pragma region f/p
private:
	std::string name = "";
	std::string description = "";
	Menu* nextMenu = nullptr;
#pragma endregion
#pragma region constructor
public:
	MenuItem() = default;
	MenuItem(const std::string& _name, const std::string& _description, Menu* _owner);
	MenuItem(const MenuItem& _copy);
	~MenuItem() override = default;
#pragma endregion
#pragma region methods
public:
	/// <summary>
	/// select menu
	/// </summary>
	/// <param name="_currentMenu">Menu</param>
	void OnClick(Menu* _currentMenu);
	/// <summary>
	/// return name
	/// </summary>
	/// <returns>string</returns>
	std::string Name() const;
	/// <summary>
	/// return description
	/// </summary>
	/// <returns>string</returns>
	std::string Description() const;
	/// <summary>
	/// return NextMenu
	/// </summary>
	/// <returns>Menu</returns>
	Menu* NextMenu() const;
#pragma endregion
#pragma region override
public:
	std::string ToString() const override;
#pragma endregion

};

