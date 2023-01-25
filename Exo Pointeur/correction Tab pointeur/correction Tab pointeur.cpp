#pragma region include
#include <iostream>
#include <string>

using namespace std;
#pragma endregion

int* tab = nullptr;
int sizeTab = 0;

//#pragma region Proto
//void clear();
//void InitArray(int& _size);
//void InsertValue();
//void ReadArray();
//void Sort();
//void Add();
//#pragma endregion
//
//void InitArray(int& _size)
//{
//    cout << "set array size : " << endl;
//    _size = 0;
//    cin >> _size;
//    _size = _size <= 0 ? 1 : _size;
//    intArray = new int[_size];
//    cout << "new int* array size : " << _size << endl;
//}
//void InsertValue()
//{
//    for (int i = 0; i < sizeArray; i++)
//    {
//        int _input;
//        cout << "Set value : ";
//        cin >> _input;
//        cout << "new value " << _input << " at index : " << i << endl;
//        intArray[i] = _input;
//    }
//}
//void ReadArray()
//{
//    for (size_t i = 0; i < sizeArray; i++)
//        cout << intArray[i] << endl;
//}
//void clear()
//{
//    delete[] intArray;
//}
//void Sort()
//{
//    int _tmp = 0;
//    for (int i = 0; i < sizeArray; i++)
//    {
//        for (int j = i; j < sizeArray; j++)
//        {
//            if (intArray[i] > intArray[j])
//            {
//                _tmp = intArray[i];
//                intArray[i] = intArray[j];
//                intArray[j] = _tmp;
//            }
//        }
//    }
//}

void Add(int );
void Clear();
void Read();

void Add(int _value)
{
    int* _tmp = tab;
    cout << _tmp << " == " << tab << endl;
    sizeTab++;
    tab = new int[sizeTab];
    for (int i = 0; i < sizeTab - 1; i++)
        tab[i] = _tmp[i];
    tab[sizeTab - 1] = _value;
}
void Read()
{
    for (int i = 0; i < sizeTab; i++)
        cout << tab[i] << endl;
}
void Clear()
{
    sizeTab = 0;
    delete[] tab;
}
int main()
{
    Add(10);
    Add(100);
    Add(20);
    Add(150);
    Read();
    Clear();

    /*while (true)
    {
        InitArray(sizeArray);
        InsertValue();
        Sort();
        ReadArray();
        clear();
    }*/
}