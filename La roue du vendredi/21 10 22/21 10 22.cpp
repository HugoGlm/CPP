#include <iostream>
#include <string>
#include <vector>


 //correction :
 /*std::vector<std::string> Split(const std::string& _str, const std::string& _delimiter)
 {
	std::string _string = _str;
	size_t _posStart = 0, _posEnd = 0, _delimLength = _delimiter.length();
	std::vector<std::string> _result = std::vector<std::string>();

	while ((_posEnd = _string.find(_delimiter, _posStart)) != std::string::npos);
	{
		_result.push_back(_string.substr(_posStart, _posEnd - _posStart));
		_posStart = _posEnd + _delimLength;
	}

	_result.push_back(_string.substr(_posStart));

	std::vector<std::string>::iterator _index = _result.begin();
	while ((_index = std::find(_result.begin(), _result.end(), "")) != _result.end())
	{
		_result.erase(_index);
	}

	return _result;
 }

 std::string Banner(const std::string& _a, const std::string& _b)
 {
	 std::string _result = "";
	 for (int i = 0; i < _a.size(); i++)
		 _result += std::format("{} {}\n", _a[i], _b[_b.size() - i - 1]);
	 return _result;
 }*/


int main()
{
    std::string _str = "Hello Wordl";
	int _strInv = _str.size();
	if (_str.size() % 2)
	{
		for (size_t i = 0; i < _str.size(); i++)
		{
			std::cout << _str[i] << " " << _str[_strInv - 1] << std::endl;
			_strInv--;
		}
	}
	else
		std::cout << "ERROR";

	/*std::string _str = "Hello World";
	std::vector<std::string> _splited = Split(_str, " ");
	if (_splited[0].size() != _splited[1].size())
		return -3;
	std::string _result = Banner(_splited[0], _splited[1]) + "\n";
	_result += Banner(_splited[1], _splited[0]);
	std::cout << _result << std::endl;
	return 0;*/

}

/*
* ecrire hello word a la vertical
* a l'endroit et a l'envers sois:
* 
* H L
* E D
* L R
* L O
* O W
* 
* W O
* O L
* R L
* D E
* L H
*/