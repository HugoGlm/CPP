#pragma once
#include "Object.h"
#include <Windows.h>
#include <gdiplus.h>
#include <vector>

namespace Core
{
    struct Position
    {
        float x;
        float y;
    };

    struct Style
    {
        Gdiplus::Color bkColor = Gdiplus::Color::White;
    };

    class Shape : public Object
    {
#pragma region var
    protected:
        Gdiplus::Pen* pen = nullptr;
        Gdiplus::Graphics* graphics = nullptr;
        Gdiplus::Color color = Gdiplus::Color::Black;
        Style style = Style();
        Position pos = Position();
#pragma endregion
#pragma region const/dest 
    public:
        O3DLIBRARY_API Shape() = default;
        O3DLIBRARY_API Shape(Position _pos);
        O3DLIBRARY_API Shape(const Shape&) = default;
        O3DLIBRARY_API ~Shape();
#pragma endregion
#pragma region methods
    public:
        O3DLIBRARY_API Style& GetStyle();
        O3DLIBRARY_API Position& GetPosition();
        O3DLIBRARY_API bool IsValid() const;
        O3DLIBRARY_API void Init(HDC _hdc);
        O3DLIBRARY_API virtual void Draw(HDC _hdc);
#pragma endregion

    };
}