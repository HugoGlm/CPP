#include "MarqueMenu.h"
#include "../Item/MenuItem.h"
#include "../ModelePeugeotMenu/ModelePeugeotMenu.h"
#include "../ModeleRenaultMenu/ModeleRenaultMenu.h"

#pragma region constructor
MarqueMenu::MarqueMenu() : Menu("Mark",{
	new MenuItem("Peugeot", "Show car of Mark Peugeot", new ModelePeugeotMenu()),
	new MenuItem("Renault", "Show car of Mark Renault", new ModeleRenaultMenu())
	})
{
}
#pragma endregion

#pragma region override
void MarqueMenu::Open()
{
	Menu::Open();
	Update();
}
#pragma endregion

