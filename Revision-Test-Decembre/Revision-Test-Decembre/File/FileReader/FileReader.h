#pragma once
#include "../../Object/Object.h"
#include <fstream>
#include <vector>
#include <string>

class FileReader :  public Object
{
#pragma region f/p
private:
	std::string path = "";
	std::ifstream stream = std::ifstream();
#pragma endregion
#pragma region constructor
public:
	FileReader() = default;
	FileReader(const std::string& _path);
	FileReader(const FileReader& _copy);
#pragma endregion
#pragma region methods
public:
	/// <summary>
	/// check if isOpen
	/// </summary>
	/// <returns>bool</returns>
	bool IsOpen() const;
	/// <summary>
	/// close File
	/// </summary>
	void Close();
	/// <summary>
	/// get all lines in file
	/// </summary>
	/// <returns></returns>
	std::vector<std::string> GetAllLines();
#pragma endregion

};

