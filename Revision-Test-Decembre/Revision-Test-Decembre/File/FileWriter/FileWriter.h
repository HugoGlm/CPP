#pragma once
#include "../../Object/Object.h"
#include <fstream>
#include <string>

class FileWriter : public Object
{
#pragma region f/p
private:
	std::string path = "";
	std::ofstream stream = std::ofstream();
#pragma endregion
#pragma region constructor
public:
	FileWriter() = default;
	FileWriter(const std::string& _path);
	FileWriter(const FileWriter& _copy);
#pragma endregion
#pragma region methods
public:
	/// <summary>
	/// check if isOpen
	/// </summary>
	/// <returns>bool</returns>
	bool IsOpen() const;
	/// <summary>
	/// write in file
	/// </summary>
	/// <param name="_value">string</param>
	void Write(const std::string& _value);
	/// <summary>
	/// clear file
	/// </summary>
	void Clear();
	/// <summary>
	/// close file
	/// </summary>
	void Close();
#pragma endregion

};

