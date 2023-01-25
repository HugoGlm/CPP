#pragma once
#include "../Object/Object.h"

class Directory : public Object
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
	/// <summary>
	/// return name
	/// </summary>
	/// <returns>string</returns>
	std::string Name() const;
	/// <summary>
	/// return path
	/// </summary>
	/// <returns>string</returns>
	std::string Path() const;
	/// <summary>
	/// create directory
	/// </summary>
	/// <param name="_path">string</param>
	/// <returns>directory</returns>
	static Directory* Create(const std::string& _path);
	/// <summary>
	/// chack if directory exist
	/// </summary>
	/// <param name="_path">string</param>
	/// <returns>bool</returns>
	static bool Exist(const std::string& _path);
	/// <summary>
	/// delete directory
	/// </summary>
	/// <param name="_path">string</param>
	/// <returns>bool</returns>
	static bool Delete(const std::string& _path);
#pragma endregion

};

