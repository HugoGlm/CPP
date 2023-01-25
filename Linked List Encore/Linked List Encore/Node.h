#pragma once

template<typename T>

class Node
{
#pragma region f/p
private:
	Node* next = nullptr;
	Node* prev = nullptr;
	T data = T();
#pragma endregion
#pragma region constructor
	Node() = default;
	Node(const T& _data, Node* _next = nullptr, Node* _prev = nullptr);
	Node* Next() const;
	Node* Prev() const;
	T& Data();
	void SetNext(Node* _next);
	void Setprev(Node* _prev);
#pragma endregion
#pragma region methods
	bool operator == (const T& _item);
	operator T();
#pragma endregion

};

#pragma region constructor
template<typename T>
Node<T>::Node(const T& _data, Node* _next, Node* _prev)
{
	data = _data;
	prev = _prev;
	next = _next;
}
template<typename T>
Node<T>* Node<T>::Next() const
{
	return next;
}
template<typename T>
Node<T>* Node<T>::Prev() const
{
	return prev;
}
template<typename T>
T& Node<T>::Data()
{
	return data;
}
template<typename T>
void Node<T>::SetNext(Node* _next)
{
	return _next;
}
template<typename T>
void Node<T>::Setprev(Node* _prev)
{
	return _prev;
}
#pragma endregion
#pragma region operator
template<typename T>
bool Node<T>::operator==(const T& _item)
{
	return data == _item;
}
template<typename T>
Node<T>::operator T()
{
	return data;
}
#pragma endregion