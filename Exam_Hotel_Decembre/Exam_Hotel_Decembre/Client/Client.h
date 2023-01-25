#pragma once
#include <iostream>

class Client
{
#pragma region f/p
private: 
	std::string name = "";
	std::string lastName = "";
	int people = 0;
#pragma endregion
#pragma region constructor
public:
	Client() = default;
	Client(const std::string _name, const std::string _lastName, const int _people);
	Client(const Client& _copy);
	~Client() = default;
#pragma endregion
#pragma region methods
public:
	std::string Name();
	std::string LastName();
	int People();
#pragma endregion

};

