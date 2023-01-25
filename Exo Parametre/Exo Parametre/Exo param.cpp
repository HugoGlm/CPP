// Exo param.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#pragma region includes
#include <iostream>
#include <string>
using namespace std;
#pragma endregion

#pragma region loc

string enlocname = "My name is : ", enloclastname = "My lastname is : ", enlocage = "My age is : ",
	   frlocname = "Mon prenom est : ", frloclastname = "Mon nom est : ", frlocage = "Mon age est : ",
	   splocname = "Me llamo : ", sploclastname = "Me apellido : ", splocage = "mi edad : ",
       defaultname = "",
	   defaultlastname = "",
	   defaultage = "";
#pragma endregion

void ShowName(string _loclabel, string _name)
{
	cout << _loclabel << _name << "\n";
}

void SetDefaultName()
{
	cout << "What is your name ? \n";
	cin >> defaultname;
}

void SetDefaultLastname()
{
	cout << "What is your lastname ? \n";
	cin >> defaultlastname;
}

void SetDefaultAge()
{
	cout << "What is your age ? \n";
	cin >> defaultage;
}

int main()
{
	SetDefaultName();
	SetDefaultLastname();
	SetDefaultAge();
	ShowName(enlocname, defaultname);
	ShowName(enloclastname, defaultlastname);
	ShowName(enlocage, defaultage);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
