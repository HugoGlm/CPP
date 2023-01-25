#pragma once
#include "../../Object/Object.h"
#include <map>
#include <string>

class FileStream;

class ShowFile : public Object
{
#pragma region f/p
private:
	std::string name = "";
	std::string filePath = "";
	FileStream* stream = nullptr;
	std::map<std::string, std::string> allMessages = std::map<std::string, std::string>();
#pragma endregion
#pragma region constructor
public:
	ShowFile() = default;
	ShowFile(const std::string & _name);
	~ShowFile();
#pragma endregion
#pragma region methods
public:
	/// <summary>
	/// execute
	/// </summary>
	void Init();
	/// <summary>
	/// get messages in file
	/// </summary>
	/// <param name="_key">string</param>
	/// <returns>string</returns>
	std::string GetMessages(const std::string& _key) const;
	/// <summary>
	/// return name
	/// </summary>
	/// <returns>string</returns>
	std::string Name() const;
	/// <summary>
	/// return filepath
	/// </summary>
	/// <returns>string</returns>
	std::string FilePath() const;
#pragma endregion

};

