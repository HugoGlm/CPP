#pragma once
#include <filesystem>
#include <map>
#include <string>

class ShowFile;

class Manager
{
#pragma region f/p
private:
	std::map<std::string, ShowFile*> ShowFiles = std::map<std::string, ShowFile*>();
#pragma endregion
#pragma region constructor
public:
	Manager();
#pragma endregion
#pragma region methods
public:
	/// <summary>
	/// execute
	/// </summary>
	void InitShowFile();
	/// <summary>
	/// get file
	/// </summary>
	/// <param name="_ShowFileName">string</param>
	/// <returns>ShowFile</returns>
	ShowFile* GetShowFile(const std::string& _ShowFileName);
	/// <summary>
	/// add file
	/// </summary>
	/// <param name="_ShowFileName">string</param>
	/// <returns>ShowFile</returns>
	ShowFile* AddShowFile(const std::string& _ShowFileName);
	/// <summary>
	/// get message in file
	/// </summary>
	/// <param name="_ShowFileName">string</param>
	/// <param name="_key">string</param>
	/// <returns>string</returns>
	std::string GetMesssage(const std::string& _ShowFileName, const std::string& _key);
#pragma endregion

};