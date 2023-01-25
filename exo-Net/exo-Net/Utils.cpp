#include "Utils.h"

bool Utils::IsNullOrEmpty(const std::string& _str)
{
	return _str.value == nullptr || _str.length == 0;
}
std::wstring Utils::ToWString() const
{
	std::string _str = value;
	return std::wstring(_str.begin(), _str.end());
}