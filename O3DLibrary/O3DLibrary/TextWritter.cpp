#include "TextWritter.h"
#include "FString.h"

#pragma region constructor
Core::IO::TextWritter::TextWritter(const char* _path)
{
	path = _path;
	stream = std::ofstream(_path, std::ios_base::app | std::ios_base::out);
}
Core::IO::TextWritter::TextWritter(const PrimitiveType::FString& _path) 
	: TextWritter(_path.ToCstr()) { }
Core::IO::TextWritter::TextWritter(const TextWritter& _copy)
{
	path = _copy.path;
	stream = std::ofstream(path, std::ios_base::app | std::ios_base::out);
}
#pragma endregion

#pragma region methods
Core::PrimitiveType::Boolean Core::IO::TextWritter::IsOpen() const
{
	return stream.is_open();
}
Core::PrimitiveType::Boolean Core::IO::TextWritter::Exist() const
{
	return stream.good();
}
Core::PrimitiveType::Boolean Core::IO::TextWritter::Path() const
{
	return path;
}
void Core::IO::TextWritter::Close()
{
	if (stream.is_open())
		stream.close();
}
void Core::IO::TextWritter::Clear()
{
	Close();
	stream = std::ofstream(path, std::ofstream::out | std::ofstream::trunc);
}
void Core::IO::TextWritter::Write(const Object& _obj)
{
	if (!IsOpen())
		return;
	stream << _obj.ToString();
	stream << std::endl;
}
void Core::IO::TextWritter::Write(const Object* _obj)
{
	if (!IsOpen())
		return;
	stream << _obj->ToString();
	stream << std::endl;
}
#pragma endregion

#pragma region override
Core::PrimitiveType::FString Core::IO::TextWritter::ToString() const
{
	return path;
}
Core::PrimitiveType::Boolean Core::IO::TextWritter::Equals(const Object* _obj) const
{
	const TextWritter* _other = dynamic_cast<const TextWritter*>(_obj);
	if (_other == nullptr)
		return false;
	return Equals(*_other);
}
Core::PrimitiveType::Boolean Core::IO::TextWritter::Equals(const TextWritter& _obj) const
{
	return path == _obj.path;
}
#pragma endregion

#pragma region operator
void Core::IO::TextWritter::operator<<(const Object& _obj)
{
	if (!IsOpen())
		return;
	stream << _obj.ToString();
	stream << std::endl;
}
void Core::IO::TextWritter::operator<<(const Object* _obj)
{
	if (!IsOpen())
		return;
	stream << _obj->ToString();
	stream << std::endl;
}
#pragma endregion
