#pragma once
#include <iostream>

template<typename T>

class Node
{
#pragma region f/p
private:
	T* data = nullptr;
	Node* prev = nullptr;
	Node* next = nullptr;
#pragma endregion
#pragma region constructor
public:
	Node() = default;
	Node(T _data, Node _prev, Node _next);
	Node(const Node& _copy);
#pragma endregion
#pragma region methods
	T* Data();
	Node<T> Next();
	Node<T> Prev();
	void SetNext(Node* _next);
	void SetPrev(Node* _prev);
#pragma endregion
};

#pragma region constructor
template<typename T>
Node<T>::Node(T _data, Node _prev, Node _next)
{
	data = _data;
	next = _next;
	prev = _prev;
}

template<typename T>
Node<T>::Node(const Node& _copy)
{
	data = _copy.data;
	next = _copy.next;
	prev = _copy.prev;
}
#pragma endregion
#pragma region methods
template<typename T>
T* Node<T>::Data()
{
	return data;
}

template<typename T>
Node<T> Node<T>::Next()
{
	return next;
}

template<typename T>
Node<T> Node<T>::Prev()
{
	return prev;
}

template<typename T>
void Node<T>::SetNext(Node* _next)
{
	return _next
}
template<typename T>
void Node<T>::SetPrev(Node* _prev)
{
	return _prev;
}
#pragma endregion