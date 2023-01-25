#include <iostream>
#include "Vector/Vector.h"

int main()
{
    Vector _v = Vector();
    Vector _v1 = Vector(1, 2, 3, 4);
    Vector _v2 = Vector(5, 6, 7, 8);
    //_v1.Display();
    //_v2.Display();
    //_v.Add(_v1, _v2).Display();
    std::cout << _v.Dot(_v1, _v2) << std::endl;
    //std::cout << _v1.Lenght() << std::endl;
    //_v.lerp(_v1, _v2, 0).Display();
    //std::cout << _v.Distance(_v1, _v2) << std::endl;
    //std::cout << _v1.LenghtSqr() << std::endl;
    //_v1.Absolute().Display();
    //_v2.Absolute().Display();
}