#include "Path.h"
#include "StringUtils.h"

std::string Path::GetPath(const std::string& _path)
{
    return StringUtils::Replace(_path, '\\', '/');
}
std::string Path::GetFileNameWithoutExtension(const std::string& _path)
{
    std::string _result = GetPath(_path);
    _result = _result.substr(_result.find_last_of('/') + 1);
    return _result.substr(0, _result.find_last_of('.'));
}
