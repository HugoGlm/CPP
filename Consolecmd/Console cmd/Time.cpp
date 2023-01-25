#include "Time.h"
#include <iostream>
#include <format>
#include <ctime>
#pragma warning(disable: 4996)

std::string Time::Name()
{
	return "time";
}
std::string Time::Description()
{
	return "Displays or sets the system time.";
}
void Time::Exec()
{
	const time_t _now = time(nullptr);
	const std::tm _tm = *localtime(&_now);
	std::cout << std::format("{:02}:{:02}:{:02}", _tm.tm_hour, _tm.tm_min, _tm.tm_sec) << std::endl;
}
