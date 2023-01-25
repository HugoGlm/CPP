#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream stream("level0.scene");
    if (!stream.is_open()) return -2;
    string _str = "";
    string _result = "";
    while (getline(stream, _str))
    {
        _result += _str + "\n";
    }

    cout << _result << endl;

}