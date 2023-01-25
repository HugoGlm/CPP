#include <iostream>
#include "Map.h"
#include <vector>


int main()
{
	Map<int, std::string> tab = Map<int, std::string>();

	tab.Clear();

	tab.Insert(0, "Thomas");

	for (KeyValuePair<int, std::string> _pair : tab)
	{
		std::cout << _pair.Value() << std::endl;
	}
	return 0;
} 