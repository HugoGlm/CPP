#include <iostream>
#include "List.h"

template<typename T>
void Display(List<T> _list)
{
	for (int i = 0; i < _list.Count(); i++)
		std::cout << _list[i] << " ";
	std::cout << std::endl;
}

int main()
{
	List<int> l = List<int>();

	l.Add(0);
	l.Add(1);
	l.Add(2);
	l.Add(3);
	l.Add(4);
	l.Add(5);
	l.Add(6);
	l.Add(7);
	l.Add(8);

	Display(l);

	l.RemoveAt(3);

	Display(l);
}