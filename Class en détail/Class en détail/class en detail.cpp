#include <iostream>
#include "Example.h"
#include "ExampleChild.h"
using namespace std;

int main()
{
    Example e;
    string name = e;
    bool b = e;
    cout << name;
}