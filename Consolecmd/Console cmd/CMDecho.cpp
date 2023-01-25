#include "CMDecho.h"

#pragma region methods
std::string CMDecho::Name()
{
	return "echo";
}
std::string CMDecho::Description()
{
	return "Displays messages, or turns command echoing on or off.";
}
void CMDecho::Exec()
{
	/*std::string _str;
	_str += " ECHO [ON | OFF]\n";
	_str += " ECHO [messages]\n\n";
	_str += "Type ECHO without to display the current echo setting.";*/
	std::string _str;
	std::cin >> _str;
	std::cout << _str;
}
#pragma endregion
