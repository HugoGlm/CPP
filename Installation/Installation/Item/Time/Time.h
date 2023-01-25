#pragma once
#include <string>
class Time
{
#pragma region constructor
public:
	Time() = default;
	~Time() = default;
#pragma endregion
#pragma region methods
public:
	static void Execute();
	static void Display();
	static void ShowTime();
	static std::string Name();
	static std::string GetQuestion();
#pragma endregion
};
