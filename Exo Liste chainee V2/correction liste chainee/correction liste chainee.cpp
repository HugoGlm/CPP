#include <iostream>
#include "List.h"
using namespace std;

int main()
{
    List list = List{0,12,3,4,54,87,51,5};
    list[5] = 100;
    cout << list[5];
}