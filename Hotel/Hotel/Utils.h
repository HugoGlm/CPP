#pragma once
#include <iostream>

class Utils
{
public:
    static void Log(const std::string& _msg);

    template<typename T>
    static T UserChoice(const std::string& _msg);
};
template<typename T>
T Utils::UserChoice(const std::string& _msg)
{
    T _res = T();
    std::cout << _msg << std::endl;
    std::cin >> _res;
    return _res;
}