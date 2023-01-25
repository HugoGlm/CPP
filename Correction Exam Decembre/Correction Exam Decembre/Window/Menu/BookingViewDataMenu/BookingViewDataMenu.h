#pragma once
#include "../BaseMenu.h"

class BookingViewDataMenu : public BaseMenu
{
	DECLARE_CLASS_INFO(BaseMenu)
#pragma region f/p
private:
	LabelControl* firstName = nullptr;
	LabelControl* lastName = nullptr;
	LabelControl* numberOfPeople = nullptr;
	CalendarControl* calendar = nullptr;
#pragma endregion
#pragma region constructor
public:
	BookingViewDataMenu() = default;
	BookingViewDataMenu(Window* _owner);
	BookingViewDataMenu(const BookingViewDataMenu& _copy) = default;
#pragma endregion
#pragma region methods
public:
	void Delete();
	void ReturnToBookingView();
#pragma endregion
#pragma region override
public:
	void Initialize() override;
	void Open() override;
#pragma endregion

};

