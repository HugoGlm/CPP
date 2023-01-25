#include <iostream>
#include <string>
#include "List.h"
#include "Node.h"

int main()
{
    List<int> list = List<int>();
    list.AddLast(0);
    list.AddLast(1);

    try
    {
        list.At(10);
    }
    catch (const std::exception& e)
    {
        cout << e.what() << endl;
    }
    
    return 0;
}