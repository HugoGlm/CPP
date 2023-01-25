#include <iostream>
#include "String.h"

int main()
{
    string _str = "Hello Word";
    std::cout << _str.SubString(0, _str.FirstIndexOf('o')) << std::endl;
    std::cout << _str.SubString(_str.FirstIndexOf('W')) << std::endl;
    std::cout << _str.SubString(0, _str.LastIndexOf('d')) << std::endl;
}