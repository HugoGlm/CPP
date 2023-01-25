#include "MorpionMenu.h"
#include "MenuItem.h"
#include "Utils.h"
#include "Jcj.h"
#include "Jce.h"

#pragma region constructor
MorpionMenu::MorpionMenu() : Menu("Morpion Game", {
		new MenuItem("Player vs Player", new Jcj()),
		new MenuItem("Player vs AI", new Jce())})
{
}
#pragma endregion 
#pragma endregion methods
void MorpionMenu::Open()
{
	Menu::Open();
	Update();
}
#pragma endregion