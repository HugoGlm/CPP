#pragma once
#include "../WindowControl.h"
#include <map>

class TextFieldControl : public WindowControl
{
	DECLARE_CLASS_INFO(WindowControl)
#pragma region f/p
public:
	static inline std::map<int, TextFieldControl*> textFields = std::map<int, TextFieldControl*>();
private:
private:
	const wchar_t* defaultText = TEXT("");
	std::wstring currentText = TEXT("");
#pragma endregion
#pragma region constructor
public:
	TextFieldControl() = default;
	TextFieldControl(int _controlID, HWND _owner, Rect _rect, const wchar_t* _defaultText);
	TextFieldControl(const TextFieldControl& _copy);
#pragma endregion
#pragma region methods
public:
	void OnValueChange();
	std::wstring CurrentText() const;
	std::string CurrentTextStr() const;
	void OnTextChange(const wchar_t* _text);
	HWND Create() override;
#pragma endregion

};

