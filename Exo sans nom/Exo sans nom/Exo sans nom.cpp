#include <iostream>
#include "List.h"
using namespace std;

template<typename T>
void Display(List<T> _list)
{
	for (int i = 0; i < _list.Count; i++)
		cout << _list[i] << " ";
	cout << endl;
}

int main()
{
	List<int> l = List<int>();

	l.Add(5);
	Display(l);
	l.Add(4);
	Display(l);
	l.Clear();
	Display(l);
	l.Add(5);
	Display(l);
}