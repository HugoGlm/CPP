#pragma once
#include <string>
#include <windows.h>

class Object
{
#pragma region constructor
public:
	Object() = default;
	Object(const Object& _copy) = default;
	virtual ~Object() = default;
#pragma endregion
#pragma region methods
public:
	std::string ToString() const;
	virtual LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) = 0;
#pragma endregion
};

