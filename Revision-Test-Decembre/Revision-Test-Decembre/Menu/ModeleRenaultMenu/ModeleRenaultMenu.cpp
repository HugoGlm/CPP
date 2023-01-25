#include "ModeleRenaultMenu.h"
#include "../../Utils/Utils.h"

ModeleRenaultMenu::ModeleRenaultMenu()
{
}
void ModeleRenaultMenu::Open()
{
	Utils::ClearConsole();
	Utils::LogTitle(title);
	std::cout << "Megane 4 RS" << std::endl;
	std::cout << "Clio 4 RS" << std::endl;
	Utils::Pause();
	OpenOldMenu();
}
