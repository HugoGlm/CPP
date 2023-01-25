#pragma once
#include "../Client/Client.h"

class Client;

class Booking
{
#pragma region f/p
private:
	Client* client = nullptr;
#pragma endregion
#pragma region constructor
public:
	Booking() = default;
	Booking(Client* _client);
	Booking(const Booking& _copy);
	~Booking() = default;
#pragma endregion
#pragma region methods
public:
	Client* GetClient() const;
#pragma endregion

};

