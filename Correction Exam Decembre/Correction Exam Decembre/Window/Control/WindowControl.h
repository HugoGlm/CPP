#pragma once
#include "../../Object/Object.h"
#include "../../Utils/Rect/Rect.h"
#include <windows.h>

class WindowControl : public Object
{
	DECLARE_CLASS_INFO(Object);

#pragma region f/p
protected:
	int controlID = 0;
	HWND owner = nullptr;
	HWND instance = nullptr;
	HINSTANCE ownerInstance;
	Rect rect = Rect();
	bool isInitialized = false;
	bool isShow = true;
#pragma endregion
#pragma region constructor
public:
	WindowControl() = default;
	WindowControl(int _controlID, HWND _owner, const Rect& _rect);
	WindowControl(const WindowControl& _copy);
#pragma endregion
#pragma region methods
public:
	void Show();
	void Hide();
	bool IsInitialized() const;
	virtual HWND Create();
#pragma endregion

};

