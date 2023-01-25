#include "Node.h"
#include <iostream>
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
	bool Contains(int _data)
	{
		Node* _tree = tree;
		while (_tree != nullptr)
		{
			if (_tree->data == _data)
				return true;
			_tree = tree->next;
		}
		delete _tree;
		return false;
	}
	Node* Find(int _item)
	{
		Node* _tree = tree;
		while (_tree != nullptr && _tree->data != _item)
			_tree = _tree->next;
		return _tree;
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
	void RemoveFirst()
	{
		Node* _tree = tree;
		tree = _tree->next;
		first = tree;
		delete _tree;
		count--;
	}
	void RemoveLast()
	{
		Node* _tree = tree;
		while (_tree->next->next != nullptr)
		{
			_tree = _tree->next;
		}
		_tree = _tree->next;
		last = _tree;
		delete _tree;
		count--;
	}
	void Remove(int _item)
	{
		Node* _tree = tree;
		if (_tree == first)
			RemoveFirst();
		else if (_tree == last)
			RemoveLast();
		else
		{
			while (_tree != nullptr && _tree->data != _item)
			{
				_tree = _tree->next;
			}
			if (_tree == nullptr)
				return;
			_tree->prev->next = _tree->next;
			_tree->next->prev = _tree->prev;
			delete _tree;
			count--;
		}
	}
	void AddBefore(int _index, int _item)
	{
		Node* _tree = Find(_index);
		if (_tree == nullptr)
			return;
		if (_tree->prev == nullptr)
		{
			AddFirst(_item);
			return;
		}
		Node* _newNode = new Node(_item, _tree, _tree->prev);
		_tree->prev->next = _newNode;
		_tree->prev = _newNode;
		count++;
	}
	void AddAfter(int _index, int _item)
	{
		Node* _tree = Find(_index);
		if (_tree == nullptr)
			return;
		if (_tree->prev == nullptr)
		{
			AddLast(_item);
			return;
		}
		Node* _newNode = new Node(_item, _tree->next, _tree);
		_tree->next = _newNode;
		count++;
	}

	int& operator[](int _index)
	{
		int _result = -1;
		if (_index < 0 || _index > count)
			return _result;
		Node* _tree = tree;
		int _currentIndex = _index;
		while (_currentIndex > 0 && _tree != nullptr)
		{
			_currentIndex--;
			_tree = _tree->next;
		}
		if (_tree == nullptr)
			return _result;
		return _tree->data;
	}
};