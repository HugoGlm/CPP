#include <iostream>
#include "MorpionMenu.h"
#include "Utils.h"
#include "MenuItem.h"
#include "Jce.h"

#pragma region constructor
Jce::Jce() : Menu("Player vs Player",{})
{
}
void Jce::Open()
{
	Utils::ClearConsole();
	Utils::LogTitle(title);
	std::cout << "Comming soon..." << std::endl;
	system("pause");
}
#pragma endregion constructor