#include "Path.h"

#pragma region methods
std::string Path::GetPath(const std::string& _path)
{
    return Object::Replace(_path, '\\', '/');
}
std::string Path::Combine(const std::string& _a, const std::string& _b, const std::string& _c)
{
    return _a + '/' + _b + '/' + _c;
}
std::string Path::Combine(const std::string& _a, const std::string& _b)
{
    return _a + '/' + _b;
}
std::string Path::GetDirectoryPath(const std::string& _path)
{
    const std::string _result = GetPath(_path);
    const int _index = _result.find_last_of('/');
    return _result.substr(0, _index);
}
#pragma endregion

