#include "DateTime.h"
#include <ATLComTime.h>
#include <format>

#pragma region methods
void DateTime::ShowDateTime()
{
	int year = COleDateTime::GetCurrentTime().GetYear();
	int month = COleDateTime::GetCurrentTime().GetDay();
	int day = COleDateTime::GetCurrentTime().GetDay();

	int hour = COleDateTime::GetCurrentTime().GetHour();
	int minute = COleDateTime::GetCurrentTime().GetMinute();
	int second = COleDateTime::GetCurrentTime().GetSecond();

	std::cout << std::format("{}/{}/{} {}:{}:{}", day, month, year, hour, minute, second);
}
#pragma endregion
