#include "Utils.h"
#include <iostream>

void Utils::Log(const std::string& _msg)
{
	std::cout << "[Log] => " << _msg << std::endl;
}