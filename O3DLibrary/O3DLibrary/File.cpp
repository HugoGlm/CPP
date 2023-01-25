#include "File.h"
#include "Boolean.h"
#include "FString.h"
#include "FileStream.h"
#include "TextWritter.h"
#include "TextReader.h"
#include <fstream>

#pragma region constructor
Core::IO::File::File(const char* _path)
{
	path = _path;
}
Core::IO::File::File(const File& _copy)
{
	path = _copy.path;
}
Core::IO::File::~File()
{
	delete path;
	path = nullptr;
}
#pragma endregion

#pragma region methods
Core::IO::FileStream* Core::IO::File::Create(const PrimitiveType::FString& _path)
{
	if (Exist(_path))
		return new FileStream(_path.ToCstr());
	const char* _pathCstr = _path.ToCstr();
	std::ofstream _stream = std::ofstream(_pathCstr);
	return new FileStream(_pathCstr);
}
Core::PrimitiveType::Boolean Core::IO::File::Exist(const PrimitiveType::FString& _path)
{
	std::ifstream _stream = std::ifstream(_path.ToCstr());
	const bool _result = _stream.good();
	_stream.close();
	return _result;
}
#pragma endregion
