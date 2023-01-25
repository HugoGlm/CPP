// Exo Calculatrice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#pragma region Include 
#include <iostream>
#include <string>
using namespace std;
#pragma endregion

#pragma region int calcul
int x, y, result;
#pragma endregion

#pragma region string contact
string enlocName = "What is your name ? ", enlocLastname = "What is your lastname ? ", enlocAge = "What is your age ? ",
name = "", lastname = "", age = "", showContact = "";
#pragma endregion

#pragma region Contact
// Here I take care of the contact, I request the information from the contact
void ShowName()
{
	cout << enlocName << "\n";
	cin >> name;
}

void ShowLastname()
{
	cout << enlocLastname << "\n";
	cin >> lastname;
}

void ShowAge()
{
	cout << enlocAge << "\n";
	cin >> age;
}

string ShowContact()
{
	ShowName(); cout << "\n";
	ShowLastname(); cout << "\n";
	ShowAge(); cout << "\n";
	cout << name << "\n" << lastname << "\n" << age << "\n";
	return showContact;
}

void TitleContact()
{
	cout << "Contact \n";
}
#pragma endregion

#pragma region Calcul
//Here I take care of the calcul, I ask the numbers and do the calculations
int Add(int _a, int _b)
{
	return _a + _b;
}

int Substract(int _a, int _b)
{
	return _a - _b;
}

int Multiply(int _a, int _b)
{
	return _a * _b;
}

int Div(int _a, int _b)
{
	return _a / _b;
}

void FirstNumber()
{
	cout << "Number One : ";
	cin >> x;	
	cout << "\n";
}

void LastNumber()
{
	cout << "Number Two : ";
	cin >> y;
	cout << "\n";
}

void Result()
{	
	FirstNumber();
	LastNumber();
	cout << "Add : " << Add(x, y) << "\n";
	cout << "Substract : " << Substract(x, y) << "\n";
	cout << "Multiply : " << Multiply(x, y) << "\n";
	cout << "Div : " << Div(x, y) << "\n";
}

void TitleCalculator()
{
	cout << "calculator \n";
}
#pragma endregion

#pragma region Result
//Here I take care of the result, I give the answers to display them
int main()
{
	TitleContact();
	ShowContact();
	TitleCalculator();
	Result();
}
#pragma endregion

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file