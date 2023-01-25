#pragma once
#include "ItemCMD.h"
#include <iostream>
#include <vector>

class ShowConsole
{
#pragma region f/p
private:
	std::vector<ItemCMD*> items = std::vector<ItemCMD*>();
#pragma endregion 
#pragma region constructor 
public:
	ShowConsole();
	~ShowConsole() = default;
#pragma endregion 
#pragma region overrride
public:
	void Show();
	std::string Version();
	int FindIndex(const std::string _cmd);
#pragma endregion 
};

