#include <iostream>
using namespace std;

template<typename T>
class Array
{
protected:
    T* tab = new T[0];
    int count = 0;
public:
    Array<T>(int _count)
    {
        count = _count;
        tab = new T[count];
    }
    Array<T>(int _count, T _index)
    {
        count = _count;
        tab = new T[count];
        for (int i = 0; i < _count; i++)
        {
            tab[i] = _index;
        }
    }
    Array<T>(initializer_list<T> _tab)
    {
        tab = new T[_tab.size()];
        count = _tab.size();
        int index = 0;
        for (T _item : _tab)
        {
            tab[index++] = _item;
        }
    }
    T At(int _index) {
        if (_index > 0 && _index < count)
        {
            T _result = tab[_index];
            return _result;
        }
        return NULL;
    }
    T Front()
    {
            return tab[count - 1];
    }
    T Back(int _count)
    {
        T _result = tab[0];
    }
    void Display()
    {
        for (int i = 0; i < count; i++)
            cout << tab[i] << " ";
    }
};

int main()
{
    Array<int> _tab1 = Array<int>(5);
    _tab1.Display();

    Array<int> _tab2 = Array<int>(5, 5);
    _tab2.Display();

    Array<int> _tab3 = Array<int>{ 1, 12, 10, 5 };
    _tab3.Display();

}