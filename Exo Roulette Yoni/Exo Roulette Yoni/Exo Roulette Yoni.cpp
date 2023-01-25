#include <iostream>
#include <string>
using namespace std;

string code = "poiuytrewq123456789";
string uncode = "I like to code";
string key = "iw3";

string InputOut()
{
    string _result;

    for (int i = 0; i < key.size(); i++)
    {
        int _index = 0;
        while (key[i] != code[_index] && code[_index] != ' ')
            _index++;
        _result += uncode[_index];
    }
    return _result;
}

int main()
{
    cout << InputOut();

    //poiuytrewq123456789
    //I like to code
    //iw3
    //out = > lod

    //$ % ? !< [] {} - \'' &/*>e
    //I use arch, btw
    //?
    //out => u

    //zxcvbnm9876$#
    //I like pizza!
    //$
    //out => a

}