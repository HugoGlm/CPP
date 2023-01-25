#include "Client.h"

#pragma region constructor
Client::Client(const std::string& _firstName, const std::string& _lastName)
{
	firstName = _firstName;
	lastName = _lastName;
}
Client::Client(const Client& _copy)
{
	firstName = _copy.firstName;
	lastName = _copy.lastName;
}
#pragma endregion

#pragma region methods
std::string Client::FirstName() const
{
	return firstName;
}
std::string Client::LastName() const
{
	return lastName;
}
#pragma endregion

