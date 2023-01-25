#include "ModelePeugeotMenu.h"
#include "../../Utils/Utils.h"

ModelePeugeotMenu::ModelePeugeotMenu()
{
}
void ModelePeugeotMenu::Open()
{
	Utils::ClearConsole();
	Utils::LogTitle(title);
	std::cout << "207 RC" << std::endl;
	std::cout << "RCZ" << std::endl;
	Utils::Pause();
	OpenOldMenu();
}
