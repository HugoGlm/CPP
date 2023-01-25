#include "Button.h"
#include "Rect.h"
#include "Console.h"
#include <iostream>

#pragma region constructor
Button::Button(const std::string& _content, Rect* _rect)
{
	content = _content;
	rect = _rect;
	Console::SetCursorPosition(_rect->X(), rect->Y());
	std::cout << _content;
}
Button::Button(const Button& _copy)
{
	content = _copy.content;
	rect = _copy.rect;
}
#pragma endregion

#pragma region methods
void Button::OnClick()
{
	std::cout << " on click !" << std::endl;
}
Rect* Button::GetRect() const
{
	return rect;
}
#pragma endregion

