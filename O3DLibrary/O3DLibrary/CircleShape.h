#pragma once
#include "Shape.h"

namespace Core
{
    class O3DLIBRARY_API CircleShape : public Shape
    {
#pragma region var
    private:
        float radius = 10.0f;
#pragma endregion
#pragma region const
    public:
        CircleShape(const Position& _pos, const float _radius);
#pragma endregion
#pragma region override
    public:
        void Draw(HDC _hdc) override;
#pragma endregion

    };
}