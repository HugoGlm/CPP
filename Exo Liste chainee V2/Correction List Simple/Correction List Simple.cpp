#include <iostream>
#include "List.h"
using namespace std;

template<typename T>
void Display(List<T> _list)
{
	for (int i = 0; i < _list.Count(); i++)
		cout << _list[i] << " ";
	cout << endl;
}

int main()
{
    List<int> _list = List<int>();

	for (int i = 0; i < 10; i++)
		_list.Add(i);
	_list.Add(3);

	_list.RemoveAll(3);

	Display(_list);
	
	_list.Clear();

	Display(_list);

	_list.Add(1);

	Display(_list);
}