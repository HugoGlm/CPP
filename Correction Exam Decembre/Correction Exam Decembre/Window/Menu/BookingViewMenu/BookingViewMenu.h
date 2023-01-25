#pragma once
#include "../BaseMenu.h"

class Booking;

#define MAXCOLUMNNUMBER 3

class BookingViewMenu : public BaseMenu
{
	DECLARE_CLASS_INFO(BaseMenu)
#pragma region f/p
public:
	static Booking* CurrentBooking;
private:
	class LabelControl* textControl = nullptr;
#pragma endregion
#pragma region constructor
public:
	BookingViewMenu() = default;
	BookingViewMenu(Window* _owner);
	BookingViewMenu(const BookingViewMenu& _copy) = default;
#pragma endregion
#pragma region methods
private:
	void ReturnMainMenu();
	void LoadBookingData();
public:
	void SetCurrentBooking(Booking* _booking);
	void DisplayBookings(const std::vector<Booking*>& _bookings);
#pragma endregion
#pragma region override
public:
	void Initialize() override;
	void Open() override;
	void Close() override;
#pragma endregion

};

