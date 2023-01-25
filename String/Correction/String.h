#pragma once
#include <vector>

#pragma warning(disable: 4996)

class String
{
#pragma region f/p
private:
	const char* value = "";
	int length = 0;
#pragma endregion
#pragma region constructor
public:
	String(const char* _value);
	String(const String& _copy);
	~String();
#pragma endregion
#pragma region methods
public:
	String ToLower() const;
	String ToUpper() const;
	bool Contains(const String& _str) const;
	std::vector<String> Split(const char _c);
	String Replace(const char _old, const char _new);
	int LastIndexOf(const char _c);
	int FirstIndexOf(const char _c);
	String Join(const std::vector<String>& _value);
	String Trim();
	String SubString(const int _begin) const;
	String SubString(const int _begin, const int _end) const;
	int CountOf(const char _c);
	static bool IsNullOrEmpty(const String& _str);
#pragma endregion
#pragma region operator
	String& operator+=(const char _c);
	String& operator+=(const String& _str);
	String operator+(const String& _other);
	operator const char* ();
#pragma endregion
};
typedef String string;