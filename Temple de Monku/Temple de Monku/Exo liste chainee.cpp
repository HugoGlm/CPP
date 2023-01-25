#include <iostream>
#include <string>
using namespace std;

class Node
{
protected:
	int data;
	Node* next = nullptr;
	Node* last = nullptr;
public:
	Node(int _data) {
		data = _data;
	};
	int GetData() {
		return data;
	}
	void SetNext(Node* _next) {
		next = _next;
	}
	void SetLast(Node* _last) {
		last = _last;
	}
	Node* GetNext() {
		return next;
	}
	Node* GetLast() {
		return last;
	}
};
class List
{
protected:
	Node* node = nullptr;
public:
	List() = default;
	List(int* tab)
	{
		List* list = new List();
		list->AddFirst(tab[0]);
		for (int i = 0; i < 9; i++)
		{
			list->AddAfter(tab[i + 1], i);
		}
		list->Display();
	}
	void Display() {
		Node* _node = node;
		while (_node != nullptr)
		{
			cout << _node->GetData() << " ";
			_node = _node->GetNext();
		}
		cout << endl;
	}
	void AddFirst(int _data) {
		if (node == nullptr)
		{
			node = new Node(_data);
		}
		else
		{
			Node* _newNode = new Node(_data);
			_newNode->SetNext(node);
			node->SetLast(_newNode);
			node = _newNode;
		}
	}
	void AddLast(int _data) {
		if (node == nullptr)
		{
			node = new Node(_data);
		}
		else
		{
			Node* _node = node;
			while (_node->GetNext() != nullptr)
			{
				_node = _node->GetNext();
			}
			Node* _newNode = new Node(_data);
			_newNode->SetLast(_node);
			_node->SetNext(_newNode);
		}
	}
	void Clear() {
		while (node != nullptr)
		{
			Node* _node = node->GetNext();
			node->SetLast(nullptr);
			node->SetNext(nullptr);
			node = _node;
		}
	}
	bool AddAfter(int _data, int _index) {
		Node* _node = node;
		for (int i = 0; i < _index; i++)
		{
			if (_node == nullptr)
				return false;
			_node = _node->GetNext();
		}

		Node* _newNode = new Node(_data);
		_newNode->SetLast(_node);
		if (_node->GetNext() != nullptr)
		{
			Node* _afterNode = _node->GetNext();
			_newNode->SetNext(_node->GetNext());
			_afterNode->SetLast(_newNode->GetNext());
		}
		_node->SetNext(_newNode);

		return true;
	}
	bool AddBefore(int _data, int _index) {
		Node* _node = node;
		for (int i = 0; i < _index; i++)
		{
			if (_node == nullptr)
				return false;
			_node = _node->GetNext();
		}

		Node* _newNode = new Node(_data);
		if (_node->GetLast() != nullptr)
		{
			Node* _beforeNode = _node->GetLast();
			_newNode->SetNext(_node);
			_newNode->SetLast(_node->GetLast());
			_beforeNode->SetNext(_newNode);
			_node->SetLast(_newNode);
			return true;
		}

		_newNode->SetNext(_node);
		_node->SetLast(_newNode);
		node = _newNode;

		return true;
	}
	bool Remove(int _index) {
		Node* _node = node;
		for (int i = 0; i < _index; i++)
		{
			if (_node == nullptr)
				return false;
			_node = _node->GetNext();
		}

		Node* _lastNode = _node->GetLast();
		Node* _nextNode = _node->GetNext();

		if (_lastNode == nullptr)
			node = _nextNode;

		_node->SetLast(nullptr);
		_node->SetNext(nullptr);

		if (_lastNode != nullptr && _nextNode != nullptr)
		{
			_lastNode->SetNext(_nextNode);
			_nextNode->SetLast(_lastNode);
		}
		else if (_lastNode != nullptr && _nextNode == nullptr)
		{
			_lastNode->SetNext(_nextNode);
		}
		else if (_lastNode == nullptr && _nextNode != nullptr)
		{
			_nextNode->SetLast(_lastNode);
		}

	}
	void RemoveFirst() {
		Node* _node = node;
		Node* _nextNode = _node->GetNext();
		_node->SetNext(nullptr);
		node = _nextNode;
	}
	void RemoveLast() {
		Node* _node = node;
		while (_node->GetNext() != nullptr)
		{
			_node = _node->GetNext();
		}
		Node* _lastNode = _node->GetLast();
		_node->SetLast(nullptr);
		_lastNode->SetNext(nullptr);
	}
	bool Contains(int _data) {
		Node* _node = node;
		while (_node != nullptr)
		{
			if (_node->GetData() == _data)
				return true;
			_node = _node->GetNext();
		}
		return false;
	}
};
int main()
{
	int tab[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	List* l = new List(tab);
}