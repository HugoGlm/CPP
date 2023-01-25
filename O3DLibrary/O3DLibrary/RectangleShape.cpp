#include "RectangleShape.h"
#include <gdiplus.h>

#pragma region const
Core::RectangleShape::RectangleShape(Position _pos, int _width, int _height)
    : Shape(_pos)
{
    width = _width;
    height = _height;
}
#pragma endregion

#pragma region override
void Core::RectangleShape::Draw(HDC _hdc)
{
    Shape::Draw(_hdc);
    if (!IsValid())
        return;
    Gdiplus::SolidBrush _brush(style.bkColor);
    graphics->FillRectangle(&_brush, Gdiplus::Rect(pos.x, pos.y, width, height));
}
#pragma endregion