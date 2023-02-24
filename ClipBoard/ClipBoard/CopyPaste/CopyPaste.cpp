#include "CopyPaste.h"

#pragma region constructor
CopyPaste::CopyPaste(const std::string& _input)
{
	input = _input;
}
CopyPaste::CopyPaste(const CopyPaste& _copy)
{
	input = _copy.input;
}
#pragma endregion

#pragma region methods
std::string CopyPaste::RegisterInput()
{
	std::cin >> input;
	return input;
}
void CopyPaste::Paste()
{
	std::cout << input << std::endl;
}
#pragma endregion

