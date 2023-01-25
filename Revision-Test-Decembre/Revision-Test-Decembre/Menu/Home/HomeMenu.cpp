#include "HomeMenu.h"
#include "../MarqueMenu/MarqueMenu.h"
#include "../Item/MenuItem.h"

#pragma region constructor
HomeMenu::HomeMenu() : Menu("Home", {
new MenuItem("Mark", "Mark of car", new MarqueMenu())
	})
{
}
#pragma endregion

