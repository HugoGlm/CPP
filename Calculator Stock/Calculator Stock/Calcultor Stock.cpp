#include <iostream>
#include <string>
using namespace std;

const int memSize = 5;
int memIndex = 0;
string stock[memSize];

void ClearMemory()
{
    for (int i = 0; i < memSize; i++)
        stock[i] = "0";
}

void ReadMemory()
{
    cout << "Read current calc memory : \n";
    for (int i = 0; i < memSize; i++)
        cout << stock[i] << endl;
}

void SetMemory(string _toSave)
{
    stock[memIndex] = _toSave;
    memIndex++;
    memIndex = (memIndex > memSize - 1) ? memSize - 1 : memIndex;
}

string Addition(float _a, float _b)
{
    float _c = _a + _b;
    return to_string(_a) + " + " + to_string(_b) + " = " + to_string(_c);
}

string Divide(float _a, float _b)
{
    float _c = _b == 0 ? 0 : _a / _b;
    return to_string(_a) + " / " + to_string(_b) + " = " + to_string(_c);
}

int main()
{
    ClearMemory();
    SetMemory(Addition(10, 2));
    SetMemory(Addition(100, 5));
    SetMemory(Addition(10, 2));
    SetMemory(Addition(10, 2));
    SetMemory(Divide(20, 2));
    ReadMemory();
}