#include <iostream>
using namespace std;
                
int main()
{
    string _t = "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++.+++++++++++++++++++++++++++++.+++++++..+++.";
    
    int ascii = 0;
    for (char c: _t)
    {
        ascii = c == '+' ? ascii + 1 : c == '-' ? ascii - 1 : ascii;
        if (c == '.')
            cout << (char)ascii;
    }
    return 0;
}