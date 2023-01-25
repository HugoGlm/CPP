#include <iostream>
using namespace std;

int a = 5, b = 15;

#pragma region Proto
void Adresse(int _a);
void MultiplyAdresse(int _a);
void SwapAToB();
#pragma endregion

void Adresse(int _a)
{
    cout << "--- adresse de l'entier ---\n";
    cout << &_a << endl;
}
void MultiplyAdresse(int _a)
{
    cout << "--- Double de l'adresse ---\n";
    int* _ptr = new int(_a);
    cout << _ptr << " " << *_ptr << endl;
    *_ptr = *_ptr * 2;
    cout << _ptr << " " << *_ptr << endl;
    delete _ptr;
}
void SwapAToB(int& _a, int& _b)
{
    int _tmp = _a;
    _a = _b;
    _b = _tmp;
}
int main()
{
    cout << a << " " << b << endl;
    SwapAToB(a, b);
    cout << a << " " << b << endl;
    //Adresse(a);
    //MultiplyAdresse(a);
}