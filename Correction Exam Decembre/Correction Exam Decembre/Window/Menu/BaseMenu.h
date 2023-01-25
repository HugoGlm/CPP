#pragma once
#include "../Control/textField/TextFieldControl.h"
#include "../Control/Button/ButtonControl.h"
#include "../Control/Label/LabelControl.h"
#include "../../Booking/Booking.h"
#include "../../Object/Object.h"
#include "../Window.h"
#include <vector>

class BaseMenu : public Object
{
	DECLARE_CLASS_INFO(Object)
#pragma region f/p
protected:
	static inline int currentControlID = 0;
	const char* name = "";
	bool isInitialized = false;
	Window* owner = nullptr;
	std::vector<WindowControl*> controls = std::vector<WindowControl*>();
	LabelControl* titleControl = nullptr;
#pragma endregion
#pragma region constructor
public:
	BaseMenu() = default;
	BaseMenu(Window* _owner, const char* _name);
	BaseMenu(const BaseMenu& _copy);
#pragma endregion
#pragma region methods
public:
	bool IsInitialized() const;
	virtual void Open();
	virtual void Close();
	virtual void Initialize();
	std::string Name() const;
protected:
	class ButtonControl* CreateButton(const Rect& _rect, const wchar_t* _text);
	class LabelControl* CreateLabel(const Rect& _rect, const wchar_t* _text);
	class TextFieldControl* CreateTextField(const Rect& _rect, const wchar_t* _defaultText);
	class CalendarControl* CreateCalendar(const Rect& _rect);
	class ButtonBookingControl* CreateBookingButton(const Rect& _rect, const wchar_t* _text, Booking* _booking);
#pragma endregion

};

