#include <iostream>
#include <format>

void Hanoi(int _disk, char _a, char _b, char _c)
{
    if (_disk != 0)
    {
        Hanoi(_disk - 1, _a, _c, _b);
        std::cout << std::format("Move {} from {} to {}", _disk, _a , _b) << std::endl;
        Hanoi(_disk - 1, _c, _b, _a);
    }
}

int main()
{
    int disk = 3;
    char a = 'A';
    char b = 'B';
    char c = 'C';

    Hanoi(disk, a, b, c);
}