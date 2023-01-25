#pragma once
#include "Shape.h"

namespace Core
{
    class RectangleShape : public Shape
    {
#pragma region var
    private:
        int width = 20;
        int height = 10;
#pragma endregion

#pragma region const
    public:
        O3DLIBRARY_API RectangleShape(Position _pos, int _width, int _height);;
#pragma endregion

#pragma region override
    public:
        O3DLIBRARY_API void Draw(HDC _hdc) override;
#pragma endregion

    };
}