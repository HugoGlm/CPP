#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class List
{
private:
    T* tab = new T[0];
    int count = 0;
public:
    List(initializer_list<T> _tab)
    {
        tab = new T[_tab.size()];   
        count = _tab.size();
        int index = 0;
        for (T _item : _tab)
        {
            tab[index++] = _item;
        }
    }
    void Display()
    {
        for (int i = 0; i < count; i++)
            cout << tab[i] << " ";
    }
};
int main()
{
    List<float> _tab = List<float>{ 0.1f, 1.2f, 0.5f };
    _tab.Display();
}