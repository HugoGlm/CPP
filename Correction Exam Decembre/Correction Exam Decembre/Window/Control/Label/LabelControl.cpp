#include "LabelControl.h"

#pragma region constructor
LabelControl::LabelControl(int _controlID, HWND _owner, const Rect& _rect, const wchar_t* _text) : super(_controlID, _owner, _rect)
{
	text = _text;
}
LabelControl::LabelControl(const LabelControl& _copy) : super(_copy)
{
	text = _copy.text;
}
#pragma endregion

#pragma region override
std::string LabelControl::TextStr()
{
	const std::wstring _text = Text();
	return std::string(_text.begin(), _text.end());
}
std::wstring LabelControl::Text()
{
	return text;
}
void LabelControl::SetText(const wchar_t* _newText)
{
	text = _newText;
	SetWindowTextA(instance, TextStr().c_str());
}
void LabelControl::SetText(std::string _str)
{
	const std::wstring _wstr(_str.begin(), _str.end());
	SetText(_wstr.c_str());
}
#pragma endregion

#pragma region override
HWND LabelControl::Create()
{
	instance = CreateWindowEx(
		0,
		L"STATIC",
		text,
		WS_CHILD | WS_VISIBLE,
		rect.X(),
		rect.Y(),
		rect.Width(),
		rect.Height(),
		owner,
		(HMENU)controlID,
		ownerInstance,
		nullptr
	);
	if (instance != NULL)
	{
		L"test";
		isInitialized = true;
		Show();
	}
	return instance;
}
#pragma endregion

