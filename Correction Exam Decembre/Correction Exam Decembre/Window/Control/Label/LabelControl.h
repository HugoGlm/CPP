#pragma once
#include "../WindowControl.h"
#include "../../../Event/Delegate/Delegate.h"
#include <map>

class LabelControl : public WindowControl
{
	DECLARE_CLASS_INFO(WindowControl)
#pragma region f/p
public:
	static inline std::map<int, LabelControl*> labels = std::map<int, LabelControl*>();
private:
	const wchar_t* text = TEXT("Default");
public:
	Delegate<void> OnClick = nullptr;
#pragma endregion
#pragma region constructor
public:
	LabelControl() = default;
	LabelControl(int _controlID, HWND _owner, const Rect& _rect, const wchar_t* _text);
	LabelControl(const LabelControl& _copy);
#pragma endregion
#pragma region methods
	std::string TextStr();
	std::wstring Text();
	void SetText(const wchar_t* _newText);
	void SetText(std::string _str);
#pragma endregion
#pragma region override
public:
	HWND Create() override;
#pragma endregion

};