#include <iostream>
#include "Utils/Quaternion/Quaternion.h"
#include <Windows.h>

void SetWindowsSize(const int _width, const int _height)
{
    HWND _console = GetConsoleWindow();
    RECT _rect;
    GetWindowRect(_console, &_rect);
    MoveWindow(_console, _rect.left, _rect.top, _width, _height, true);
}
void Display(std::string _text, Quaternion _item)
{
    std::string _aff = "==============================";
    std::cout << _aff << std::endl << _text << std::endl << "{" << _item.ToString() << "}" << std::endl << _aff << std::endl;
}
void Display(std::string _text, float _item)
{
    std::string _aff = "==============================";
    std::cout << _aff << std::endl << _text << std::endl << "{" << _item << "}" << std::endl << _aff << std::endl;
}

int main()
{
    SetWindowsSize(1000, 800);
    Quaternion quat = Quaternion(50, 25, 80, 125);
    Quaternion quat1 = Quaternion(80, 30, 25, 40);
    Display("Nomalize", Quaternion::Normalize(quat));
    Display("Conjugate", Quaternion::Conjugate(quat));
    Display("Inverse", Quaternion::Inverse(quat));
    Display("Negate", Quaternion::Negate(quat));
    Display("Lerp => 0", Quaternion::Lerp(quat, quat1, 0.0f));
    Display("Lerp => 0.5", Quaternion::Lerp(quat, quat1, 0.5f));
    Display("Lerp => 1", Quaternion::Lerp(quat, quat1, 1.0f));
    Display("Dot", Quaternion::Dot(quat, quat1));
    Display("Angle", Quaternion::Angle(quat, quat1));
    Display("Length", quat.Length());
    Display("Length Squared", quat.LengthSquared());
}