#include "MenuItem.h"
#include "Menu.h"

#pragma region constructor
MenuItem::MenuItem(const std::string& _name, Menu* _owner)
{
    name = _name;
    nextMenu = _owner;
}
MenuItem::MenuItem(const MenuItem& _copy)
{
    name = _copy.name;
    nextMenu = _copy.nextMenu;
}
#pragma endregion
#pragma region methods
void MenuItem::OnClick(Menu* _currentMenu)
{
    if (nextMenu == nullptr)
        throw std::exception("[MenuItem] => next menu is null !");
    if (!nextMenu->Equals(_currentMenu))
        nextMenu->SetOldMenu(_currentMenu);
    _currentMenu->Close();
    nextMenu->Open();
}
std::string MenuItem::Name()
{
    return name;
}
Menu* MenuItem::NextMenu() const
{
    return nextMenu;
}
#pragma endregion
#pragma region override
std::string MenuItem::ToString() const
{
    return name;
}
#pragma endregion