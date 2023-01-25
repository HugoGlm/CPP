#include "HomeMenu.h"
#include "MenuItem.h"
#include "MorpionMenu.h"

#pragma region constructor
HomeMenu::HomeMenu() : Menu("Home", {
		new MenuItem("Morpion", new MorpionMenu())

	})
{
}
#pragma endregion constructor