#include <initializer_list>
using namespace std;

template<typename T>
class Array
{
private:
	int count = 0;
	T* tab = nullptr;
public:
	Array(int _count)
	{
		count = _count;
		tab = new T[count];
	}
	Array(T _item, int _count)
	{
		count = _count;
		tab = new T[count];
		for (int i = 0; i < count; i++)
			tab[i] = _item;
	}
	Array(initializer_list<T> _tab)
	{
		count = tab.size();
		tab = new T[count];
		int _index = 0;
		for (T _item : _tab)
		{
			tab[_index] = _item;
			_index++;
		}
	}
	T& At(int _index)
	{
		return tab[_index];
	}
	T Front()
	{
		return tab[count - 1];
	}
	T Back()
	{
		return tab[0];
	}

	void Resize(int _newCount)
	{
		T* _tmp = tab;
		int _oldCount = count;
		count = _newCount;
		tab = new T[count];
		for (int i = 0; i < _oldCount; i++)
			tab[i] = _tmp[i];
	}

	bool operator==(const Array& _other)
	{
		if (count != _other.count)
			return false;
		for (int i = 0; i < count; i++)
		{
			if (tab[i] != _other.tab[i])
				return false;
		}
		return true;
	}
	bool operator!=(const Array& _other)
	{
		return !this->operator==(_other);
	}
	T& operator[](int _index)
	{
		return tab[_index];
	}
	int Count()
	{
		return count;
	}
};