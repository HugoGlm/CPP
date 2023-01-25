#include <iostream>
#include "KeyValuePair.h"
#include "Map.h"

int main()
{
    Map<int, std::string> tab = Map<int, std::string>
    {
        {0, "Thomas"},
        {1, "Giusy"},
        {2, "Yoni"}
    };

    for (KeyValuePair <int, std::string>  _pair : tab)
    {
        std::cout << _pair.Value() << std::endl;
    }

    return 0;
}