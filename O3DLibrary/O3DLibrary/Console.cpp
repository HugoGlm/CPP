#include "Console.h"
#include "FString.h"
#include "TextWritter.h"
#include "Path.h"
#include "Environment.h"
#include "Directory.h"
#include "DateTime.h"

Core::IO::TextWritter* Core::Console::Out = Out_Internal();

#pragma region methods
Core::IO::TextWritter* Core::Console::Out_Internal()
{
	const PrimitiveType::FString& _directoryPath = IO::Path::Combine({ IO::Path::GetParent(Core::Environment::CurrentDirectory), "App_Debug" });
	IO::Directory::MakeDirectory(_directoryPath);
	const PrimitiveType::FString& _fullPath = IO::Path::Combine({ _directoryPath, "Debug.log" });
	Core::IO::TextWritter* _writter = new Core::IO::TextWritter(_fullPath.ToCstr());
	_writter->Clear();
	return _writter;
}
void Core::Console::WriteLine(const PrimitiveType::FString& _label, const object _obj, const EConsoleColor& _color)
{
	SetConsoleTextAttribute(console, (int)_color);
	const PrimitiveType::FString _now = DateTime::Now().ToStringFormat("h:m:s");
	std::cout << _now << " : " << _label << " => " << _obj->ToString() << std::endl;
	*Out << PrimitiveType::FString("[LOG] ") + _now + " => " + _obj->ToString();
	SetConsoleTextAttribute(console, (int)EConsoleColor::Reset);
}
void Core::Console::WriteLine(const PrimitiveType::FString& _label, const Object& _obj, const EConsoleColor& _color)
{
	SetConsoleTextAttribute(console, (int)_color);
	const PrimitiveType::FString _now = DateTime::Now().ToStringFormat("h:m:s");
	std::cout << _now << " : " << _label << " => " << _obj.ToString() << std::endl;
	*Out << PrimitiveType::FString("[LOG] ") + _now + " => " + _obj.ToString();
	SetConsoleTextAttribute(console, (int)EConsoleColor::Reset);
}
#pragma endregion
