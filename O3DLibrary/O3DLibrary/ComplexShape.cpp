#include "ComplexShape.h"
#include <gdiplus.h>

#pragma region const
Core::ComplexShape::ComplexShape(const std::vector<Gdiplus::PointF>& _points)
    :Shape({ 0,0 })
{
    points = _points;
}
#pragma endregion

#pragma region override
void Core::ComplexShape::Draw(HDC _hdc)
{
    Shape::Draw(_hdc);
    if (!IsValid())
        return;
    graphics->FillPolygon(new Gdiplus::SolidBrush(style.bkColor), points.data(), points.size());
}
#pragma endregion