#pragma once

class Rect
{
#pragma region f/p
private:
	int width = 0, height = 0, x = 0, y = 0, xMax = 0, yMax = 0;
#pragma endregion
#pragma region constructor
public:
	Rect() = default;
	Rect(const int _width, const int _height, const int _x, const int _y);
	Rect(const Rect& _copy);
#pragma endregion
#pragma region methods
public:
	bool Contains(const int _x, const int _y);
	int X() const;
	int Y() const;
#pragma endregion
};

