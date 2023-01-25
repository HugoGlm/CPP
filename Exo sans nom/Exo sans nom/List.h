#pragma once
using namespace std;

template<typename T>

class List
{
#pragma region f/p
private:
	int count = 0;
	T* tab = nullptr;
#pragma endregion
#pragma region constructor
public:
	List();
	List(const T& _copy);
	~List();
#pragma endregion
#pragma region methods
private:
	void FindOf(const T& _item);
public:
	void Add(const T& _item);
	void Clear();
	int Count();
	void Remove(const T& _item);
	void RemoveAt(const T& _index);
	void RemoveAll(const T& _item);
	bool Contains(const T& _item);
#pragma endregion
};
#pragma region constructor
template<typename T>
void List<T>::FindOf(const T& _item)
{
	
}
template<typename T>
List<T>::List()
{
	tab = new T[0];
	count = 0;
}
template<typename T>
List<T>::List(const T& _copy)
{
	for (int i = 0; i < _copy.Count(); i++)
	{
		Add(_copy.tab[i]);
	}
}
template<typename T>
List<T>::~List()
{
	Clear();
}
#pragma endregion
#pragma region methods
template<typename T>
void List<T>::Add(const T& _item)
{
	T* _tmp = tab;
	tab = new T[count + 1];
	for (int i = 0; i < count; i++)
		tab[i] = _tmp[i];
	tab[count] = _item;
	count++;
}
template<typename T>
void List<T>::Clear()
{
	if (count > 0)
		delete[] tab;
	else
		delete[] tab;
	count = 0;
	tab = new T[0];
}
template<typename T>
int List<T>::Count()
{
	return count;
}
template<typename T>
void List<T>::Remove(const T& _item)
{

}
template<typename T>
void List<T>::RemoveAt(const T& _index)
{

}
template<typename T>
void List<T>::RemoveAll(const T& _item)
{

}
template<typename T>
bool List<T>::Contains(const T& _item)
{

}