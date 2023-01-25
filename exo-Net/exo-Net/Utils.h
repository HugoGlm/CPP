#pragma once
#include <string>

class Utils
{

#pragma region f/p
private:
	const char* value = "";
	int length = 0;
#pragma endregion
#pragma region methods
public:
	static bool IsNullOrEmpty(const std::string& _str);
	std::wstring ToWString() const;
#pragma endregion

};

