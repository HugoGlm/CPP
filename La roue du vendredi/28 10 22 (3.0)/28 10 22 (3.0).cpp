#include <iostream>

int main()
{
    //renvoie 1234 avec 1*2 & 3*4 -> 2444
    std::string _suite = "1234";
    std::string _result;
	if (_suite.size() % 2)
		throw std::exception();
	for (int i = 0; i < _suite.size(); i += 2)
	{
		int _a = _suite[i] - '0';
		_result += std::string(_a, _suite[i + 1]);
	}
	std::cout << _result;
}