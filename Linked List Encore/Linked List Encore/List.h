#pragma once
#include <initializer_list>
#include <iostream>
#include "Node.h"

template<typename T>

class List
{
#pragma region f/p
private:
	Node<T>* head = nullptr;
	Node<T>* first = nullptr;
	Node<T>* last = nullptr;
	int count = 0;
#pragma endregion
#pragma region constructor
public:
	List() = default;
	List(const initializer_list<T>& _tab);
	~List();
#pragma endregion
#pragma region methods
private:
	Node<T>* Find(const T& _item);
public:
	void AddFirst(const T& _item);
	void AddLast(const T& _item);
	void AddBefore(const T& _index, const T& _item);
	void AddAfter(const T& _index, const T& _item);
	int count();
	void Clear();
	void Remove(const T& _item);
	void RemoveFirst();
	void RemoveLast();
	void Display();
	void At(const int& _index);
#pragma endregion
};

#pragma region constructor
template<typename T>
List<T>::List(const initializer_list<T>& _tab)
{
	for (const T& _item : _tab)
		AddLast(_item);
}
template<typename T>
List<T>::~List()
{
	Clear();
}
#pragma endregion
#pragma region methods
template<typename T>
Node<T>* List<T>::Find(const T& _item)
{
	Node<T>* _head = head;
	while (_head != nullptr)
	{
		if (_head->operator==(_item))
			return _head;
		_head = _head->Next();
	}
	return nullptr;
}
template<typename T>
void List<T>::AddFirst(const T& _item)
{
	Node<T>* _newNode = new Node<T>(_item);
	if (head == nullptr)
	{
		head = _newNode;
		first = _newNode;
		last = _newNode;
	}
	else
	{
		_newNode->SetNext(fisrt);
		first->Setprev();
		head = first = _newNode;
	}
	count++;
}
template<typename T>
void List<T>::AddLast(const T& _item)
{
	if (head == nullptr)
	{
		AddFirst(_item);
		return;
	}
	else
	{
		Node<T>* _newNode = new Node<T>*(_item, nullptr, last);
		last = SetNext(_newNode);
		last = _newNode;
	}
	count++;
}
template<typename T>
void List<T>::AddBefore(const T& _index, const T& _item)
{
}
template<typename T>
void List<T>::AddAfter(const T& _index, const T& _item)
{
}
template<typename T>
int List<T>::count()
{
	return 0;
}
template<typename T>
void List<T>::Clear()
{
}
template<typename T>
void List<T>::Remove(const T& _item)
{
}
template<typename T>
void List<T>::RemoveFirst()
{
}
template<typename T>
void List<T>::RemoveLast()
{
}
template<typename T>
void List<T>::Display()
{
}
template<typename T>
void List<T>::At(const int& _index)
{
}
#pragma endregion