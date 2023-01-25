#pragma once
#include <vector>
#include <string>

class File
{
#pragma region constructor
public:
	static std::vector<std::string> GetAllLines(const std::string& _path);
#pragma endregion
};

