#include <iostream>
#include "Potion.h"
#include "Weapon.h"
using namespace std;

template<typename T>
void Display(Potion<T> _list)
{
	for (int i = 0; i < _list.Count(); i++)
		cout << _list[i] << " ";
	cout << endl;
}

int main()
{
    Potion<string> p = Potion<string>();
    Weapon<string> w = Weapon<string>();

	w.ChooseWeapon();

	p.Add("Heal");
	p.Add("Mana");

	Display(p);

	p.Use("Mana");

	Display(p);
}