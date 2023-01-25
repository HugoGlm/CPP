#include "Directory.h"
#include "Utils.h"
#include "Path.h"

#pragma region constructor
Directory::Directory(const std::string& _path)
{
	path = Path::GetPath(_path);
	name = path.substr(path.find_last_of('/') + 1);
	Utils::Log(name);
}
#pragma endregion
#pragma region methods
std::string Directory::Name() const
{
	return name;
}

std::string Directory::Path() const
{
	return path;
}
#pragma endregion
#pragma region operator
Directory* Directory::Create(const std::string& _path)
{
	return nullptr;
}

bool Directory::Exist(const std::string& _path)
{
	return false;
}

bool Directory::Delete(const std::string& _path)
{
	return false;
}
#pragma endregion