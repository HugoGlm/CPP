#include "CMDcls.h"

std::string CMDcls::Name()
{
	return "cls";
}
std::string CMDcls::Description()
{
	return "Clears the screen.";
}
void CMDcls::Exec()
{
	Utils::ClearConsole();
}
