#include "DownlaodFile.h"
#include "Utils.h"
#include <ShlObj_core.h>
#include <ShObjIdl_core.h>

#pragma warning(disable: 4996)

#pragma region constructor
DownlaodFile::DownlaodFile(const char* _value)
{
	if (_value == nullptr) _value = "";
	const int _otherLength = strlen(_value);
	const int& _length = length;
	const int _newLength = _length + _otherLength;
	char* _char = new char[_newLength + 1];
	strcpy(_char, value);
	strcat(_char, _value);
	value = _char;
	length = _newLength;
}
DownlaodFile::DownlaodFile(const DownlaodFile& _copy)
{
	if (_copy.value == nullptr) return;
	const size_t _length = _copy.length;
	char* _new = new char[_length + 1];
	memcpy(_new, _copy.value, _length + 1);
	value = _new;
	length = _copy.length;
}
void DownlaodFile::Start(const std::string& _path, const std::string& _parameters)
{
    if (Utils::IsNullOrEmpty(_path))
        return;
	const std::wstring _pathToOpen = _path.ToWString();
    const std::wstring _params = _parameters.ToWString();
    ShellExecute(nullptr, nullptr, _pathToOpen.c_str(), _params.c_str(), nullptr, SW_SHOWNORMAL);
}
#pragma endregion