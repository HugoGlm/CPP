#include "Booking.h"

#pragma region constructor
Booking::Booking(Client* _client)
{
	client = _client;
}
Booking::Booking(const Booking& _copy)
{
	client = _copy.client;
}
#pragma endregion

#pragma region methods
Client* Booking::GetClient() const
{
	return client;
}
#pragma endregion
