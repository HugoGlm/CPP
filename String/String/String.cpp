#include "String.h"
#include "String.h"
#include "String.h"
#include "String.h"
#include "String.h"
#include "String.h"
#include "String.h"
#include <String>

#pragma region constructor
String::String(const char* _value)
{

#pragma warning(disable: 4996)

    if (_value == nullptr) _value = "";
    const int _otherLength = strlen(_value);
    const int& _length = size;
    const int _newLength = _length + _otherLength;
    char* _char = new char[_newLength + 1];
    // ReSharper disable CppDeprecatedEntity
    strcpy(_char, string);
    // ReSharper disable once CppDeprecatedEntity
    strcat(_char, _value);
    string = _char;
    size = _newLength;
}
String::String(const String& _copy)
{
    string = _copy.string;
    size = _copy.size;
}
String::~String()
{
    string = "";
    size = 0;
}
#pragma endregion
#pragma region methods
String String::ToLower() const
{
    char* _str = nullptr;
    _str = new char[size];
    for (int i = 0; i < size; i++)
    {
        char _char = ' ';
        _char = std::tolower(string[i]);
        _str[i] = _char;
    }
    _str[size] = '\0';
    (const char*)_str;
    String _string = String(_str);
    return _string;
}
String String::ToUpper() const
{
    char* _str = nullptr;
    _str = new char[size];
    for (int i = 0; i < size; i++)
    {
        char _char = ' ';
        _char = std::toupper(string[i]);
        _str[i] = _char;
    }
    _str[size] = '\0';
    (const char*)_str;
    String _string = String(_str);
    return _string;
}
bool String::Contains(const String& _str)
{
    for (int i = 0; i < size; i++)
    {
        if (string[i] == _str[0])
        {
            for (int j = size; j < _str.size(); j++)
            { 
                return true;
            }
        }
    }
    return false;
}
#pragma endregion
#pragma region operator
String::operator const char* ()
{
    return string;
}
#pragma endregion