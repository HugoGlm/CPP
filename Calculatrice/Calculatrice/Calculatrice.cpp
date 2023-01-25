// Calculatrice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>


int numberOne,
    numberTwo,
    numberPlus,
    numberLess,
    numberTime,
    numberDiv; 

std::string enNumber = "Choose number",
       frNumber = "Choisit un nombre";

int Plus(std::string _loclabel)
{
    std::cout << _loclabel << "\n";
    std::cin >> numberOne;
    std::cout << _loclabel << "\n";
    std::cin >> numberTwo;
    numberPlus = numberOne + numberTwo;
    return numberPlus;
}

int Less(std::string _loclabel)
{
    numberLess = numberOne - numberTwo;
    return numberLess;
}
 
int Time(std::string _loclabel)
{
    numberTime = numberOne * numberTwo;
    return numberTime;
}

int Div(std::string _loclabel)
{
    numberDiv = numberOne / numberTwo;
    return numberDiv;
}

int main()
{
    std::cout << "Plus : " << Plus(enNumber);
    std::cout << "\n";
    std::cout << "Less : " << Less(enNumber);
    std::cout << "\n";
    std::cout << "Time : " << Time(enNumber);
    std::cout << "\n";
    std::cout << "Div : " << Div(enNumber);
    std::cout << "\n";
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
