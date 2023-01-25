#pragma once
#include "Object.h"
#include "EDayOfWeek.h"
#include <Windows.h>

namespace Core
{
	class O3DLIBRARY_API DateTime : public Object
	{
#pragma region f/p
	private:
		int day = 0;
		int month = 0;
		int year = 0;
		int hour = 0;
		int minute = 0;
		int second = 0;
		EDayOfWeek dayOfWeek = EDayOfWeek::Sunday;
#pragma endregion
#pragma region constructor
	public:
		DateTime(const SYSTEMTIME& _time);
		DateTime(const int _day, const int _month, const int _year, const int _hour, const int _minute, const int _second);
		DateTime(const int _day, const int _month, const int _year, const int _hour, const int _minute);
		DateTime(const int _day, const int _month, const int _year, const int _hour);
		DateTime(const int _day, const int _month, const int _year);
		DateTime(const DateTime& _copy);
#pragma endregion
#pragma region methods
	private:
		int CalculateDayOfWeek() const;
	public:
		EDayOfWeek DayOfWeek() const;
		static Core::DateTime Now();
		void AddDay(const int _value);
		void AddMonth(const int _value);
		void AddYear(const int _value);
		void AddHour(const int _value);
		void AddMinute(const int _value);
		void AddSecond(const int _value);
		PrimitiveType::FString ToStringFormat(const PrimitiveType::FString& _format) const;
		PrimitiveType::Boolean Equals(const DateTime& _obj) const;
#pragma endregion
#pragma region override
	public:
		PrimitiveType::FString ToString() const override;
		PrimitiveType::Boolean Equals(const Object* _obj) const override;
#pragma endregion

	};
}
