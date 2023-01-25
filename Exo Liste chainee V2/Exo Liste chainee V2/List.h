#pragma once
#include <iostream>
#include "Node.h"
using namespace std;

class List
{
private:
	Node* tree = nullptr;
	Node* first = nullptr;
	Node* last = nullptr;
	int count = 0;
public:
	List() = default;
	List(initializer_list<int> _tab)
	{
		for (int _item : _tab)
		{
			AddLast(_item);
		}
	}
	void Display()
	{
		Node* _tree = tree;
		while (_tree != nullptr)
		{
			cout << _tree->data << " ";
			_tree = _tree->next;
		}
		cout << endl;
	}
	void AddFirst(int _data)
	{
		Node* _newNode = new Node(_data);
		if (tree == nullptr)
		{
			first = last = tree = _newNode;
		}
		else
		{
			_newNode->next = tree;
			first = tree = _newNode;
		}
		count++;
	}
	void AddLast(int _data)
	{
		if (tree == nullptr)
		{
			AddFirst(_data);
			return;
		}
		Node* _tree = tree;
		while (_tree->next != nullptr)
			_tree = _tree->next;
		Node* _newNode = new Node(_data);
		last->next = _newNode;
		last = _newNode;
		count++;
	}
	void Clear()
	{
		delete tree;
		tree = nullptr;
		count = 0;
	}
	void AddAfter(int _data)
	{

	}
	void AddBefore(int _data)
	{

	}
	void Remove(int _data)
	{

	}
	void RemoveFirst(int _data)
	{

	}
	void RemoveLast(int _data)
	{

	}
	void Contains(int _data)
	{

	}
};

