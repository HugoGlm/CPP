#include <iostream>
#include<Windows.h>
#include <string>
using namespace std;

int main()
{
    srand((unsigned int)time(NULL));
    cout << rand() % 10 << endl;
}