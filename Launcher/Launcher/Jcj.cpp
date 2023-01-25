#include <iostream>
#include "MorpionMenu.h"
#include "GameMorpion.h"
#include "MenuItem.h"
#include "Utils.h"
#include "Jcj.h"

#pragma region constructor
Jcj::Jcj() : Menu("Player vs Player", {})
{
}
void Jcj::Open()
{
	Utils::ClearConsole();
	Utils::LogTitle(title);
	gameMorpion->Start();
	//std::cout << "Player vs Player" << std::endl;
	system("pause");
}
#pragma endregion constructor