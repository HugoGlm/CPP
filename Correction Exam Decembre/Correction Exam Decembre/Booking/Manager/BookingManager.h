#pragma once
#include "../../Utils/Singleton/Singleton.h"
#include <vector>

class Booking;

class BookingManager : public Singleton<BookingManager>
{
	DECLARE_CLASS_INFO(Singleton<BookingManager>)
#pragma region f/p
private:
	std::vector<Booking*> bookings = std::vector<Booking*>();
#pragma endregion
#pragma region mehods
public:
	void RegisterBooking(Booking* _booking);
	void DeleteBooking(Booking* _booking);
	std::vector<Booking*> Bookings() const;
#pragma endregion
#pragma region override
public:
	void OnDestroy() override;
#pragma endregion

};

