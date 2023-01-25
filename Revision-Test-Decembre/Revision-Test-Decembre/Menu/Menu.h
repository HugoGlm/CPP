#pragma once
#include "../Object/Object.h"
#include <vector>

class MenuItem;

class Menu : public Object
{
#pragma region f/p
protected:
	std::string title = "";
	Menu* oldMenu = nullptr;
	bool isOpen = false;
	std::vector<MenuItem*> items = std::vector< MenuItem*>();
#pragma endregion
#pragma region constructor
public:
	Menu() = default;
	Menu(const std::string& _title, std::initializer_list<MenuItem*> _items);
	Menu(const Menu& _copy);
	~Menu() override;
#pragma endregion
#pragma region methods
public:
	/// <summary>
	/// Open menu
	/// </summary>
	virtual void Open();
	/// <summary>
	/// close menu
	/// </summary>
	virtual void Close();
	/// <summary>
	/// update menu
	/// </summary>
	virtual void Update();
	/// <summary>
	/// open old menu  
	/// </summary>
	void OpenOldMenu();
	/// <summary>
	/// display item menu
	/// </summary>
	void Displayitems();
	/// <summary>
	/// list item menu
	/// </summary>
	/// <returns>vector</returns>
	std::vector<MenuItem*> Items() const;
	/// <summary>
	/// choose menu 
	/// </summary>
	/// <param name="_index">int</param>
	void Choose(const int _index);
	/// <summary>
	/// return old menu
	/// </summary>
	/// <returns>Menu</returns>
	Menu* OldMenu() const;
	/// <summary>
	/// set old menu
	/// </summary>
	/// <param name="_old">Menu</param>
	void SetOldMenu(Menu* _old);
	/// <summary>
	/// check if equals
	/// </summary>
	/// <param name="_other">Menu</param>
	/// <returns>bool</returns>
	bool Equals(const Menu* _other);
#pragma endregion

};

