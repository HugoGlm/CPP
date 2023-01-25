#pragma once
#include "stdexcept"
using namespace std;

template<typename T>

class Potion
{
#pragma region f/p
private:
	T* tab = nullptr;
	T* popo = nullptr;
	int count = 0;
#pragma endregion
#pragma region constructor
public:
	Potion() = default;
	~Potion();
#pragma endregion
#pragma region methods
private:
	int FindOf(const T& _item);
public:
	void Use(const T& _item);
	void Add(const T& _item);
	/*void Stack(const T& _item);*/
	int Count();
#pragma endregion
#pragma region operator
	T& operator[](int _index);
#pragma endregion
};
template<typename T>
int Potion<T>::FindOf(const T& _item)
{
	for (int i = 0; i < count; i++)
	{
		if (tab[i] == _item)
			return i;
	}
	return -1;
}
template<typename T>
Potion<T>::~Potion()
{
	if (count > 0)
		delete[] tab;
	else
		delete[] tab;
	count = 0;
	tab = new T[0];
}
template<typename T>
void Potion<T>::Use(const T& _item)
{
	T* _tmp = tab;
	const int _index = FindOf(_item);
	tab = new T[count - 1];
	for (int i = 0; i < _index; i++)
		tab[i] = _tmp[i];
	for (int i = _index + 1; i < count; i++)
		tab[i - 1] = _tmp[i];
	count--;
}
template<typename T>
void Potion<T>::Add(const T& _item)
{
	T* _tmp = tab;
	tab = new T[count + 1];
	for (int i = 0; i < count; i++)
	{
		/*Potion<T>::Stack(_item);*/
		tab[i] = _tmp[i];
	}
	tab[count] = _item;
	count++;
}
//template<typename T>
//void Potion<T>::Stack(const T& _item)
//{
//	T* _tmp = tab;
//	int _count = count;
//	_count = 1;
//	if (Add(_item) == "Mana")
//	{
//		_count++;
//		_tmp.Add(_item) = _item + _count;
//	}
//	else if (Add(_item) == "Heal")
//	{
//		_count++;
//		_tmp.Add(_item) = _item + _count;
//	}
//}
template<typename T>
int Potion<T>::Count()
{
	return count;
}
template<typename T>
T& Potion<T>::operator[](int _index)
{
	return tab[_index];
}