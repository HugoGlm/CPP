#include <iostream>
#include "Array.h"
using namespace std;

int main()
{
	Array<int> _tab = Array<int>(10);
	for (int i = 0; i < 10; i++)
		_tab.At(i) = i;

	_tab.Resize(4);

	for (int i = 0; i < _tab.Count(); i++)
		cout << _tab[i] << " ";
}