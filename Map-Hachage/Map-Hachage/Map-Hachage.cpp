#include <iostream>
#include "Map/Map.h"

int main()
{
    Map<int, std::string> map = Map<int, std::string>();

	map.Clear();

	map.Insert(0, "zero");
	map.Insert(1, "one");
	map.Insert(2, "two");
	map.Insert(3, "tree");

	for (KeyValuePair<int, std::string> _pair : map)
	{
		std::cout << _pair.Value() << std::endl;
	}
}