#include "CircleShape.h"
#include <gdiplus.h>

#pragma region const
Core::CircleShape::CircleShape(const Position& _pos, const float _radius)
    : Shape(_pos)
{
    radius = _radius;
}
#pragma endregion

#pragma region override
void Core::CircleShape::Draw(HDC _hdc)
{
    Shape::Draw(_hdc);
    if (!IsValid())
        return;
    Gdiplus::Rect _rect = Gdiplus::Rect(pos.x, pos.y, radius, radius);
    graphics->FillEllipse(new Gdiplus::SolidBrush(style.bkColor), _rect);
}
#pragma endregion