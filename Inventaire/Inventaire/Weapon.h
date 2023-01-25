#pragma once
#include <iostream>
using namespace std;

template<typename T>

class Weapon
{
#pragma region f/p
private:
	T* weapon = nullptr;
#pragma endregion
#pragma region constructor
public:
	Weapon() = default;
	~Weapon();
#pragma endregion
#pragma region methods
	void SetWeapon(const T& _item);
	void ChooseWeapon();
	void Clear();
#pragma endregion
};

template<typename T>
Weapon<T>::~Weapon()
{
	Weapon<T>::Clear();
}
template<typename T>
void Weapon<T>::SetWeapon(const T& _item)
{
	int size = 3;
	weapon[size] = { "sword" "bow" "trident" };
}
template<typename T>
void Weapon<T>::ChooseWeapon()
{
	srand((unsigned int)time(NULL));
	string _input;
	cout << "Choose weapon :\n sword\n bow\n trident\n";
	cin >> _input;
	if (_input == "sword")
		cout << _input << " : " << rand() % (7 - 5 + 1) + 5 << " damage" << endl;
	else if (_input == "bow")
		cout << _input << " : " << rand() % (5 - 3 + 1) + 3 << " damage" << endl;
	else if (_input == "trident")
		cout << _input << " : " << rand() % (10 - 7 + 1) + 10 << " damage" << endl;
	else
		Weapon<T>::ChooseWeapon();
}
template<typename T>
void Weapon<T>::Clear()
{
	delete[] weapon;
	weapon = new T[0];
}