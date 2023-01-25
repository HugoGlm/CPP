#include "Time.h"
#include "../Wifi/Wifi.h"
#include <iostream>
#include <Time.h>

#pragma warning(disable: 4996)

void Time::Execute()
{
	std::string _input = "";
	std::cout << GetQuestion();
	std::cin >> _input;
	if (_input == "y")
		ShowTime();
	else if (_input == "ok")
	{
		std::cout << "Show Time" << std::endl;
		system("pause");
		Execute();
	}
	else if (_input == "r")
		Wifi::Display();
	else if (_input == "n")
		std::cout << "comming soon..." << std::endl;
	else
		Execute();
}
void Time::Display()
{
	std::cout << Name() << std::endl;
	Execute(); 
	std::cout << std::endl;
}
void Time::ShowTime()
{
	time_t _now = time(nullptr);
	tm _timeStruct = *localtime(&_now);
	char _buffer[80];
	strftime(_buffer, sizeof(_buffer), "%X", &_timeStruct);
	std::cout << "The current time is: " << _buffer << std::endl;
}
std::string Time::Name()
{
	return "Time";
}
std::string Time::GetQuestion()
{
	return "You want see the time ?";
}
