#include <iostream>
#include "List.h"

int main()
{
    List list = List();

    list.AddFirst(5);
    list.Clear();
    list.AddLast(8);

    list.Display();
}