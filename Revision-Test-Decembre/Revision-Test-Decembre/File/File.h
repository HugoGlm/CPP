#pragma once
#include "../Object/Object.h"

class FileStream;

class File : public Object
{
#pragma region f/p
private:
	std::string path = "";
#pragma endregion
#pragma region constructor
public:
	File() = default;
	File(const std::string& _path);
	File(const File& _copy);
#pragma endregion
#pragma region mmethods
public:
	/// <summary>
	/// chaeck if file Exist
	/// </summary>
	/// <param name="_path">string</param>
	/// <returns>bool</returns>
	static bool Exist(const std::string& _path);
	/// <summary>
	/// create file
	/// </summary>
	/// <param name="_path">string</param>
	/// <returns>FileStream</returns>
	static FileStream* Create(const std::string& _path);
#pragma endregion

};

