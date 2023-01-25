#include "Client.h"

#pragma region constructor
Client::Client(const std::string _name, const std::string _lastName, const int _people)
{
    name = _name;
    lastName = _lastName;
    people = _people;
}
Client::Client(const Client& _copy)
{
    name = _copy.name;
    lastName = _copy.lastName;
    people = _copy.people;
}
#pragma endregion

#pragma region methods
std::string Client::Name()
{
    return name;
}
std::string Client::LastName()
{
    return lastName;
}
int Client::People()
{
    return people;
}
#pragma endregion

