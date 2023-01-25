#pragma once
#include "../../Object/Object.h"

class FileWriter;
class FileReader;

class FileStream : public Object
{
#pragma region f/p
private:
	FileWriter* writer = nullptr;
	FileReader* reader = nullptr;
#pragma endregion
#pragma region constructor
public:
	FileStream() = default;
	FileStream(const std::string& _path);
	FileStream(const FileStream& _copy);
#pragma endregion
#pragma region methods
public:
	/// <summary>
	/// close directory
	/// </summary>
	void Close() const;
	/// <summary>
	/// write in directory
	/// </summary>
	/// <returns>FileWriter</returns>
	FileWriter* Writer() const;
	/// <summary>
	/// read directory
	/// </summary>
	/// <returns>FileReader</returns>
	FileReader* Reader() const;
	/// <summary>
	/// check if isValid
	/// </summary>
	/// <returns>bool</returns>
	bool IsValid() const;
#pragma endregion

};

