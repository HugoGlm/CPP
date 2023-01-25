#pragma once
#include <iostream>
using namespace std;

template<typename T>

class List
{
#pragma region f/p
private:
	List<T>* number = nullptr;
	int count = 0;
	int* list = nullptr;
#pragma endregion
#pragma region constructor
public:
	List() = default;
	~List();
#pragma endregion
#pragma region methods
public:
	void Add(const T& _item);
	void Clear(const T& _item);
	int Count() const;
	void Remove(const T& _item);
	void RemoveAt(const T& _item);
	void RemoveAll(const T& _item);
	void Contains(const T& _item);
	void Display();
	T& Data();
#pragma endregion
};

template<typename T>
List<T>::~List()
{
	count = 0;
	number = nullptr;
}
template<typename T>
inline List<T>::List(initializer_list<T> _tab)
{
}
template<typename T>
void List<T>::Add(const T& _item)
{
	count++;
	_oldList = list[];
	list* _list = new List();
	for (int i = 0; i < count; i++)
	{
		list[i] = _oldList[i];
	}
	count++;
}
template<typename T>
void List<T>::Clear(const T& _item)
{
	delete number;
	//count = 0;
	number = nullptr;
}
template<typename T>
int List<T>::Count() const
{
	return count;
}
template<typename T>
void List<T>::Remove(const T& _item)
{

}
template<typename T>
void List<T>::RemoveAt(const T& _item)
{

}
template<typename T>
void List<T>::RemoveAll(const T& _item)
{

}
template<typename T>
void List<T>::Contains(const T& _item)
{

}
template<typename T>
void List<T>::Display()
{
	List<T>* _number = number;
	while (_number != nullptr)
	{
		cout << _number << ", ";
	}
	cout << std::endl;
}
template<typename T>
T& List<T>::Data()
{
	return data;
}
