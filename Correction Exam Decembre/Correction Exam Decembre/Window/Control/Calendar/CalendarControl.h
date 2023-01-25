#pragma once
#include "../../../Utils/DateTime/DateTime.h"
#include "../WindowControl.h"
#include <CommCtrl.h>
#include <map>

class CalendarControl : public WindowControl
{
	DECLARE_CLASS_INFO(WindowControl)
#pragma region f/p
public:
	static inline std::map<int, CalendarControl*> calendars = std::map<int, CalendarControl*>();
private:
	DateTime arrivedDate = DateTime();
	DateTime departureDate = DateTime();
#pragma endregion
#pragma region constructor
public:
	CalendarControl() = default;
	CalendarControl(int _controlID, HWND _owner, const Rect& _rect);
	CalendarControl(const CalendarControl& _copy);
#pragma endregion
#pragma region methods
public:
	void SetMaxSelected(UINT _value);
	void SetValue(const DateTime& _a, const DateTime& _b);
	void OnChoice(LPNMSELCHANGE _value);
	DateTime ArrivedDate() const;
	DateTime DepartureDate() const;
#pragma region override
public:
	HWND Create() override;
#pragma endregion

};

