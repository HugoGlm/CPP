#include "DynoMap.h"
#include "DynoGame.h"
#include "Utils.h"

void DynoMap::Draw()
{
	for (int i = 0; i < SCREEN_WIDTH + 1; i++)
	{
		Utils::SetCursorPosition(i, 0);
		std::cout << "±";
		Utils::SetCursorPosition(i, SCREEN_HEIGHT);
		std::cout << "±";
		Utils::Sleep(SLEEP_TIME_MAP);
	}
	for (int i = 0; i < SCREEN_HEIGHT; i++)
	{
		Utils::SetCursorPosition(0, i);
		std::cout << "±";
		Utils::SetCursorPosition(SCREEN_WIDTH, i);
		std::cout << "±";
		Utils::Sleep(SLEEP_TIME_MAP);
	}
	for (int i = 0; i < SCREEN_HEIGHT; i++)
	{
		Utils::SetCursorPosition(WIN_WIDTH, i);
		std::cout << "±";
		Utils::Sleep(SLEEP_TIME_MAP);
	}
}
void DynoMap::Erase()
{
}
void DynoMap::Update()
{
}
