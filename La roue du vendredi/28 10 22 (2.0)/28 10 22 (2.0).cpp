#include <iostream>
#include <string>

#pragma warning(disable: 4996)

char* ToCharArray(const std::string& _str)
{
	char* _result = new char[_str.size() + 1];
	strcpy(_result, _str.c_str());
	return _result;
}

int main()
{
	int n = 50;
	char* _array = ToCharArray(std::to_string(n));
	std::reverse(_array, _array + strlen(_array));
	std::cout << n - std::stoi(_array);
}