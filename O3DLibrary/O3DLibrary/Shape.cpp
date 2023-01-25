#include "Shape.h"

#pragma region const
Core::Shape::Shape(Position _pos)
{
    pos = _pos;
}

Core::Shape::~Shape()
{
    delete pen;
    delete graphics;
    pen = nullptr;
    graphics = nullptr;
}
#pragma endregion

#pragma region methods
Core::Style& Core::Shape::GetStyle()
{
    return style;
}

Core::Position& Core::Shape::GetPosition()
{
    return pos;
}

bool Core::Shape::IsValid() const
{
    return pen != nullptr && graphics != nullptr;
}

void Core::Shape::Init(HDC _hdc)
{
    graphics = new Gdiplus::Graphics(_hdc);
    pen = new Gdiplus::Pen(style.bkColor);
}

void Core::Shape::Draw(HDC _hdc)
{
    if (!IsValid())
        Init(_hdc);
}

#pragma endregion