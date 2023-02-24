#pragma once
#include <iostream>

class CopyPaste
{
#pragma region f/p
private:
	static inline std::string input = "";
#pragma endregion
#pragma region constructor
public:
	CopyPaste() = default;
	CopyPaste(const std::string& _input);
	CopyPaste(const CopyPaste& _copy);
#pragma endregion
#pragma region methods
public:
	static std::string RegisterInput();
	static void Paste();
#pragma endregion

};

