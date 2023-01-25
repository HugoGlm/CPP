// Condition.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

bool isValid = true,
     notValid = false;

void TestBool()
{
    if (isValid == notValid)
    {
        cout << "Faux !\n";
    }
    else
    {
        cout << "Next !";
    }
}

int main()
{
    TestBool();
}