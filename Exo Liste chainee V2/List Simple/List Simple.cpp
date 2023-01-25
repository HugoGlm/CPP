#include <iostream>
#include "List.h"

int main()
{
    List<int> l = List<int>();

    l.Add(5);
    l.Add(5);
    //l.Clear(5);

    l.Display();
}