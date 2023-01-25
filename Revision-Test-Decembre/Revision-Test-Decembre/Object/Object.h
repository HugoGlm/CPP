#pragma once
#include <iostream>
#include <string>

class Object
{
#pragma region f/p
private:

#pragma endregion
#pragma region constructor
public:
	Object() = default;
	virtual ~Object() = default;
#pragma endregion
#pragma region methods
public:
	/// <summary>
	/// return Object
	/// </summary>
	/// <returns>string</returns>
	virtual std::string ToString() const;
	/// <summary>
	/// replace string in char
	/// </summary>
	/// <param name="_str">string</param>
	/// <param name="_old">char</param>
	/// <param name="_new">char</param>
	/// <returns>string</returns>
	static std::string Replace(const std::string& _str, const char& _old, const char& _new);
	/// <summary>
	/// replace string in other string
	/// </summary>
	/// <param name="_str">string</param>
	/// <param name="_old">string</param>
	/// <param name="_new">string</param>
	/// <returns>string</returns>
	static std::string Replace(const std::string& _str, const std::string& _old, const std::string& _new);
#pragma endregion

};

