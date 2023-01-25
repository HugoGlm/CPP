#pragma once
#include "../Object/Object.h"

class Path : public Object
{
#pragma region methods
public: 
	/// <summary>
	/// get path
	/// </summary>
	/// <param name="_path">string</param>
	/// <returns>string</returns>
	static std::string GetPath(const std::string& _path);
	/// <summary>
	/// combine 3 string
	/// </summary>
	/// <param name="_a">string</param>
	/// <param name="_b">string</param>
	/// <param name="_c">string</param>
	/// <returns>string</returns>
	static std::string Combine(const std::string& _a, const std::string& _b, const std::string& _c);
	/// <summary>
	/// combine 2 string
	/// </summary>
	/// <param name="_a">string</param>
	/// <param name="_b">string</param>
	/// <returns>string</returns>
	static std::string Combine(const std::string& _a, const std::string& _b);
	/// <summary>
	/// get directory path
	/// </summary>
	/// <param name="_path">string</param>
	/// <returns>string</returns>
	static std::string GetDirectoryPath(const std::string& _path);
#pragma endregion

};

