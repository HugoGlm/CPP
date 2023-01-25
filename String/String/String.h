#pragma once
#include <vector>

class String
{
#pragma region f/p
private:
    const char* string = "";
    int size = 0;
#pragma endregion
#pragma region constructor
public:
    String() = default;
    String(const char* _value);
    String(const String& _copy);
    ~String();
#pragma endregion 
#pragma region methods
public:
    String ToLower() const;
    String ToUpper() const;
    String Replace(const String& _value);
    String Join(const String& _str1, const String& _str2, const String& _str3);
    std::vector<String> Split(const String& _value);
    String& SubString(int _begin);
    String& SubString(int _begin, int end);
    String& Trim(String& _str);
    bool IsNullOrEmpty();
    bool Contains(const String& _str);
    int FirstIndexOf(const char _char);
    int LastIndexOf(const char _char);
#pragma endregion
#pragma region operator
public:
    operator const char*();
#pragma endregion
};