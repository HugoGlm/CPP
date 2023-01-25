#pragma once
#include "Shape.h"
#include <vector>

namespace Core
{
    class O3DLIBRARY_API ComplexShape : public Shape
    {
#pragma region var
    private:
        std::vector<Gdiplus::PointF> points = std::vector<Gdiplus::PointF>();
#pragma endregion
#pragma region const
    public:
        ComplexShape(const std::vector<Gdiplus::PointF>& _points);
#pragma endregion
#pragma region override
    public:
        void Draw(HDC _hdc) override;
#pragma endregion

    };
}