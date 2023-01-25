#include <iostream>
#include <string>



int main()
{
	std::string _code = "067111100105110103";
	if (_code.size() % 3 != 0)
	{
		std::cout << "ERROR" << std::endl;
		return 0;
	}
	std::string _result = "";
	int _index = 0;
	for (int i = 3; i <= _code.size(); i += 3)
	{
		std::string _str = _code.substr(_index, 3);
		_index = i;
		int _value = std::atoi(_str.c_str());
		_result += (char)_value;
	}
	std::cout << _result << std::endl;
}

/*
*donner la liste 
*prendre 3 chiffres en utilisant %
*si c'est pas trois lettre "error" 
*et la ressortir en ascii
*
*067111100105110103 => Coding
* 067 111 100 105 110 103
* C   O   D   I   N   G
*Chaque nombre est composee de 3 chiffres
*/