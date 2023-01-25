#pragma once
#include "FString.h"

namespace Core 
{
	enum class EDayOfWeek : unsigned int
	{
		Sunday,
		Monday,
		Thuesday,
		Wednesday,
		Thursday,
		Friday,
		Saturday
	};
	inline PrimitiveType::FString operator*(EDayOfWeek day)
	{
		switch (day)
		{
		case Core::EDayOfWeek::Sunday: return "Sunday";
		case Core::EDayOfWeek::Monday: return "Monday";
		case Core::EDayOfWeek::Thuesday: return "Thuesday";
		case Core::EDayOfWeek::Wednesday: return "Wednesday";
		case Core::EDayOfWeek::Thursday: return "Thursday";
		case Core::EDayOfWeek::Friday: return "Friday";
		case Core::EDayOfWeek::Saturday: return "Saturday";
		default: return "";
		}
	}
}