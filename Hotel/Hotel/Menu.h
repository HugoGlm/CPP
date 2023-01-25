#pragma once
#include <iostream>

class Menu
{
#pragma region f/p
private:
	std::string name = "";
	std::string lastName = "";
	int age = 0;
	std::string arrivalDate = "";
	std::string departureDate = "";
	int count = 0;
#pragma endregion 
#pragma region constructor
public:
	Menu() = default;
	Menu(const std::string& _name, const std::string& _lastName, const int& _age, const std::string& ArrivalDate, const std::string DepartureDate, const int& _count);
	Menu(const Menu& _copy);
#pragma endregion
#pragma region methods
public:
	void Hotel();
	void Reservation();
	void Add();
	void Remove();
	void Display();
	int Count();
#pragma endregion
};

