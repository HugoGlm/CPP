#pragma once
#include <iostream>
#include "Node.h"

template<typename T>

class List
{
#pragma region f/p
private:
	Node* head = nullptr;
	Node* last = nullptr;
#pragma endregion
#pragma region constructor
public:
	List() = default;
	List(T _head, T _last);
	List(const List& _copy);
	~List();
#pragma endregion
#pragma region methods
	void AddFirst(T _item);
	void AddLast(T _item);
	void AddBefore(T _item);
	void AddAfter(T _item);
	int count();
	void Clear();
	void Remove(T _item);
	void RemoveAt(T _item);
	void RemoveAll(T _item);
	void Display();
#pragma endregion
};

#pragma region constructor
template<typename T>
inline List<T>::List(T _head, T _last)
{
	head = _head;
	last = _last;
}
template<typename T>
inline List<T>::List(const List& _copy)
{
	head = _copy.head;
	last = _copy.last;
}
template<typename T>
inline List<T>::~List()
{
	Clear();
}
#pragma endregion
#pragma region methods
template<typename T>
inline void List<T>::AddFirst(T _item)
{
	_tmp = list;
	Node* node = new Node();
	if (head == nullptr)
		head = node;
	next->SetNext(_head);
	head = node;
	count++;
}
template<typename T>
inline void List<T>::AddLast(T _item)
{
}
template<typename T>
inline void List<T>::AddBefore(T _item)
{
}
template<typename T>
inline void List<T>::AddAfter(T _item)
{
}
template<typename T>
inline int List<T>::count()
{
	return count;
}
template<typename T>
inline void List<T>::Clear()
{
	count = 0;
	delete[] list;
}
template<typename T>
inline void List<T>::Remove(T _item)
{
}
template<typename T>
inline void List<T>::RemoveAt(T _item)
{
}
template<typename T>
inline void List<T>::RemoveAll(T _item)
{
}
template<typename T>
inline void List<T>::Display()
{
}
#pragma endregion