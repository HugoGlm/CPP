#include "Utils.h"
#include <filesystem>
#pragma warning(disable: 4996)

void Utils::LogWithEffect(const std::string& _msg, const int _time)
{
	for (char _c : _msg)
	{
		std::cout << _c;
		::Sleep(_time);
	}
}
void Utils::Log(const std::string& _str)
{
	std::cout << _str << std::endl;
}
void Utils::LogError(const std::string& _str)
{
	const HANDLE _handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(_handle, color_red);
	std::cout << "[ERROR] => " << _str << std::endl;
	SetConsoleTextAttribute(_handle, color_white);
}
void Utils::Help(const std::string& _title, const std::string& _desc)
{
	std::cout << std::setw(10) << std::right << _title << "\t\t" << _desc << std::endl;
}
std::string Utils::CurrentPath()
{
	std::string _path = Utils::GetPath(std::filesystem::current_path().string());
	return _path.substr(0, _path.find_last_of('/') - 36);
}
std::string Utils::GetPath(const std::string& _path)
{
	return Utils::Replace(_path, '\\', '/');
}
std::string Utils::Replace(const std::string& _str, const char& _old, const char& _new)
{
	std::string _result = _str;
	const size_t _size = _result.size();
	for (size_t i = 0; i < _size; i++)
	{
		if (_result[i] == _old)
			_result[i] = _new;
	}
	return _result;
}
std::string Utils::Replace(const std::string& _str, const std::string& _old, const std::string& _new)
{
	std::string _result = _str;
	size_t _startPos = 0;
	while ((_startPos = _result.find(_old, _startPos)) != std::string::npos)
	{
		_result.replace(_startPos, _old.size(), _new);
		_startPos += _new.size();
	}
	return _result;
}
std::vector<std::string> Utils::Parse(std::string _cmd)
{
	std::vector<std::string> _res = std::vector<std::string>();

	if (_cmd.find_first_of(' ') == std::string::npos)
	{
		_res.push_back(_cmd);
		_res.push_back("");
		return _res;
	}

	while (_cmd.find_first_of(' ') != std::string::npos)
	{
		std::string _tmp = _cmd.substr(0, _cmd.find_first_of(' ')); //warning 'space'
		_res.push_back(_tmp);
		_cmd = _cmd.substr(_cmd.find_first_of(' ') + 1, _cmd.size());
	}
	_res.push_back(_cmd);
	return _res;
}
void Utils::ClearConsole()
{
	system("cls");
}