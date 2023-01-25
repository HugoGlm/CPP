#pragma once
#include <string>
#include <ostream>

class DownlaodFile
{
#pragma region f/p
private:
	const char* value = "";
	int length = 0;
	std::string adresse = "";
	std::string destination = "";
#pragma endregion
#pragma region constructor
public:
	DownlaodFile() = default;
	DownlaodFile(const char* _value);
	DownlaodFile(const DownlaodFile& _copy);
#pragma endregion
#pragma region methods
public:
	void Start(const std::string& _path, const std::string& _parameters);
#pragma endregion

};

