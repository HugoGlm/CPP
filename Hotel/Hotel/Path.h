#pragma once
#include <iostream>

class Path
{
public:
	static std::string GetPath(const std::string& _path);
	static std::string GetFileNameWithoutExtension(const std::string& _path);
};

