#pragma once
#include "../Object/Object.h"

class Menu //: public Object
{
#pragma region methods
public:
	int CreateWindows();
	static void Text();
	void Execute();
#pragma endregion
#pragma region override
public:
	//virtual LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) override;
#pragma endregion

};

