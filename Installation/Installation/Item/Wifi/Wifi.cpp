#include "Wifi.h"
#include "../Time/Time.h"
#include <iostream>

void Wifi::Execute()
{
	std::string _input = "";
	std::cout << GetQuestion();
	std::cin >> _input;
	if (_input == "y")
		std::cout << "Wifi is On." << std::endl;
	else if (_input == "ok")
	{
		std::cout << "Turn ON|OFF Wifi" << std::endl;
		system("pause");
		Execute();
	}
	else if (_input == "r")
		return;
	else if (_input == "n")
		Time::Display();
	else
		Execute();
}
void Wifi::Display()
{
	std::cout << Name() << std::endl;
	Execute();
}
std::string Wifi::Name()
{
	return "Wifi";
}
std::string Wifi::GetQuestion()
{
	return "You want turn on your wifi ?\n";
}
