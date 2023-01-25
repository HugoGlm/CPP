#include "File.h"
#include "FileStream/FileStream.h"
#include "../Path/Path.h"
#include "../Directory/Directory.h"
#include <fstream>

#pragma region constructor
File::File(const std::string& _path)
{
	path = _path;
}
File::File(const File& _copy)
{
	path = _copy.path;
}
#pragma endregion

#pragma region methods
bool File::Exist(const std::string& _path)
{
	std::ifstream _stream = std::ifstream(_path);
	const bool _exist = _stream.good();
	_stream.close();
	return _exist;
}
FileStream* File::Create(const std::string& _path)
{
	const std::string& _directoryPath = Path::GetDirectoryPath(_path);
	if (!Directory::Exist(_directoryPath))
		Directory::Create(_directoryPath);
	return new FileStream(_path);
}
#pragma endregion

