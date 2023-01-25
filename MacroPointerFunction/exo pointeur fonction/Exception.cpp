#include "Exception.h"
#include <format>

#pragma region constructor
Exception::Exception(const std::source_location& _location)
{
    std::string _fileName = _location.file_name();
    _fileName = _fileName.substr(_fileName.find_last_of('\\') + 1);
    error = std::format("{} in class {} in function {} at line {}", "error", _fileName, _location.function_name(), _location.line());
}
Exception::Exception(const std::string& _error, const std::source_location& _location)
{

    std::string _fileName = _location.file_name();
    _fileName = _fileName.substr(_fileName.find_last_of('\\') + 1);
    error = std::format("{} in class {} in function {} at line {}", _error, _fileName, _location.function_name(), _location.line());
}
#pragma endregion
#pragma region override
std::string Exception::ToString() const
{
    return error;
}
#pragma endregion