#pragma once
#include <string>
class Wifi
{
#pragma region constructor
public:
	Wifi() = default;
	~Wifi() = default;
#pragma endregion
#pragma region methods
public:
	static void Execute();
	static void Display();
	static std::string Name();
	static std::string GetQuestion();
#pragma endregion

};

