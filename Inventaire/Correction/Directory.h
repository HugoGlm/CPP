#pragma once
#include <string>

class Directory
{
#pragma region f/p
private:
	std::string name = "";
	std::string path = "";
#pragma endregion
#pragma region constructor
public:
	Directory() = default;
	Directory(const std::string& _path);
#pragma endregion
#pragma region methods
public:
	std::string Name() const;
	std::string Path() const;
#pragma endregion
#pragma region operator
public:
	static Directory* Create(const std::string& _path);
	static bool Exist(const std::string& _path);
	static bool Delete(const std::string& _path);
#pragma endregion
};

