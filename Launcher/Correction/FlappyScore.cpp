#include "FlappyScore.h"
#include "Utils.h"
#include "FlappyBird.h"

void FlappyScore::Draw()
{
	Utils::SetCursorPosition(WIN_WIDTH + 7, 5);
	std::cout << "Score: " << score;
}
void FlappyScore::Erase()
{
}
void FlappyScore::Update()
{
	score++;
}
FlappyScore::operator int() const
{
	return score;
}
FlappyScore& FlappyScore::operator=(const int _value)
{
	score = _value;
	return *this;
}
FlappyScore& FlappyScore::operator+=(const int _value)
{
	score += _value;
	return *this;
}
