#include "DynoScore.h"
#include "Utils.h"
#include "DynoGame.h"

void DynoScore::Draw()
{
	Utils::SetCursorPosition(WIN_WIDTH + 7, 5);
	std::cout << "Score: " << score;
}
void DynoScore::Erase()
{
}
void DynoScore::Update()
{
	score++;
}
DynoScore::operator int() const
{
	return score;
}
DynoScore& DynoScore::operator=(const int _value)
{
	score = _value;
	return *this;
}
DynoScore& DynoScore::operator+=(const int _value)
{
	score += _value;
	return *this;
}
