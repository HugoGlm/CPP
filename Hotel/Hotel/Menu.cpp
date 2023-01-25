#include "Menu.h"
#include "Menu.h"
#include "Menu.h"
#include <iostream>

#pragma region constructor
Menu::Menu(const std::string& _name, const std::string& _lastName, const int& _age, const std::string& _arrivalDate, const std::string _departureDate, const int& _count)
{
	name = _name;
	lastName = _lastName;
	age = _age;
	arrivalDate = _arrivalDate;
	departureDate = _departureDate;
	count = _count;
}
Menu::Menu(const std::string& _title)
{
}
Menu::Menu(const Menu& _copy)
{
	name = _copy.name;
	lastName = _copy.lastName;
	age = _copy.age;
	arrivalDate = _copy.arrivalDate;
	departureDate = _copy.departureDate;
	count = _copy.count;
}
Menu::~Menu()
{
}
#pragma endregion
#pragma region methods
void Menu::Hotel()
{
	#pragma region affichage
	std::cout << "               Hotel\n               -----" << std::endl;
	std::cout << "1: Reservation" << std::endl;
	std::cout << "        -> Reservation Gestion" << std::endl;
	std::cout << "2: Return" << std::endl;
	#pragma endregion
	int _input;
	std::cin >> _input;
	if (_input == 1)
	{
		system("cls");
		Reservation();
	}
	else if (_input == 2)
		return;
	else
		Hotel();
}
void Menu::Reservation()
{
	#pragma region affichage
	std::cout << "               Reservation\n               -----------" << std::endl;
	std::cout << "1: Add" << std::endl;
	std::cout << "        -> Add new reservation" << std::endl;
	std::cout << "2: Remove" << std::endl;
	std::cout << "        -> Add new reservation" << std::endl;
	std::cout << "3: Display Booking" << std::endl;
	std::cout << "        -> Display all Booking" << std::endl;
	std::cout << "4: Return" << std::endl;
	#pragma endregion
	int _input;
	std::cin >> _input;
	switch (_input)
	{
	case 1:
		system("cls");
		Add();
		break;
	case 2:
		system("cls");
		Remove();
		break;
	case 3:
		system("cls");
		Display();
		break;
	case 4:
		system("cls");
		Hotel();
		break;
	default:
		break;
	}
}
void Menu::Add()
{
	std::cout << "               Reservation Add\n               ---------------" << std::endl;
	std::cout << "client first name" << std::endl;
	std::cin >> name;
	std::cout << "client last name" << std::endl;
	std::cin >> lastName;
	std::cout << "client age" << std::endl;
	std::cin >> age;
	std::cout << "arrival date" << std::endl;
	std::cin >> arrivalDate;
	std::cout << "departure date" << std::endl;
	std::cin >> departureDate;
	system("pause");
	system("cls");
	Reservation();
}
void Menu::Remove()
{
	
}
void Menu::Display()   
{	
	std::cout << "=====================" << std::endl;
	std::cout << "Client:" << std::endl;
	std::cout << "first name: " << name << std::endl;
	std::cout << "last name: " << lastName << std::endl;
	std::cout << "age: " << age << std::endl;
	std::cout << "arrival date: " << arrivalDate << std::endl;
	std::cout << "departure date: " << departureDate << std::endl;
	std::cout << "=====================" << std::endl;
	system("pause");
	system("cls");
	Reservation();
}
int Menu::Count()
{
	return count;
}
#pragma endregion