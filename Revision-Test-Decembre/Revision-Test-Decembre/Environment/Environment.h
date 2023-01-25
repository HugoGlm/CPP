#pragma once
#include "../Object/Object.h"

class Environment : public Object
{
#pragma region methods
public:
	/// <summary>
	/// recupere  le directory
	/// </summary>
	/// <returns>string</returns>
	static std::string CurrentDirectory();
#pragma endregion

};

