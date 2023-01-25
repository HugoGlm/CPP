#include "DynoGame.h"
#include "DynoMap.h"
#include "DynoPlayer.h"
#include "DynoPipe.h"
#include "Utils.h"

#pragma region constructor
DynoGame::DynoGame()
{
	map = new DynoMap();
	player = new DynoPlayer();
	pipeOne = new DynoPipe();
	pipeTwo = new DynoPipe();
}
DynoGame::~DynoGame()
{
	delete map;
	map = nullptr;
	delete player;
	player = nullptr;
	delete pipeOne;
	pipeOne = nullptr;
	delete pipeTwo;
	pipeTwo = nullptr;
}
#pragma endregion
#pragma region methods
void DynoGame::Draw()
{
	player->Draw();
	pipeOne->Draw();
	pipeTwo->Draw();
}
void DynoGame::Clear()
{
	player->Erase();
	pipeOne->Erase();
	pipeTwo->Erase();
}
void DynoGame::DisplayControls()
{
	Utils::SetCursorPosition(WIN_WIDTH + 5, 2);
	Utils::LogWithEffect(GameName());
	Utils::SetCursorPosition(WIN_WIDTH + 6, 4);
	Utils::LogWithEffect("----------");
	Utils::SetCursorPosition(WIN_WIDTH + 6, 6);
	Utils::LogWithEffect("----------");
	Utils::SetCursorPosition(WIN_WIDTH + 7, 12);
	Utils::LogWithEffect("Control ");
	Utils::SetCursorPosition(WIN_WIDTH + 7, 13);
	Utils::LogWithEffect("-------- ");
	Utils::SetCursorPosition(WIN_WIDTH + 2, 14);
	Utils::LogWithEffect("Spacebar for jump");
}
void DynoGame::UpdatePipe()
{
	pipeOne->Update();
	pipeTwo->Update();

	const int _pipePosition = pipeOne->Position();
	if (_pipePosition >= 40 && _pipePosition < 42)
	{
		pipeTwo->SetCanDraw(true);
		pipeTwo->SetPosition(4);
		pipeTwo->SetGapPosition(Utils::Random(3, 14)); //TODO change random
	}
}
void DynoGame::Init()
{
	isQuitting = false;
	score = 0;
	player->SetDead(false);
	player->SetPosition(SCREEN_HEIGHT - 5);
	pipeOne->SetCanDraw(true);
	pipeTwo->SetCanDraw(false);
	pipeOne->SetPosition(4);
	pipeTwo->SetPosition(4);
	pipeOne->SetCanDraw(Utils::Random(3, 14));
}
void DynoGame::UpdateScore()
{
	if (pipeOne->Position() > 68)
	{
		//TODO score update
		score.Update();
		score.Draw();
		pipeTwo->SetCanDraw(false);
		pipeOne->SetPosition(pipeTwo->Position());
		pipeOne->SetGapPosition(pipeTwo->GapPosition());
	}
}
#pragma endregion
#pragma region override
void DynoGame::OnStart()
{
	Utils::ClearConsole();
	Utils::SetCursor(false, 0);
	sleepTime = SLEEP_DEFAULT;
	Init();
	map->Draw();
}
void DynoGame::OnUpdate()
{
	while (!player->IsDead() && !isQuitting) //TODO change true
	{
		const char _input = Utils::CinNoBlock();
		if (_input == SPACE)
			player->Jump();
		else if (_input == ESCAPE)
		{
			isQuitting = true;
			continue;
		}
		Draw();

		if (player->IsCollide(pipeOne))
		{
			player->SetDead(true);
			continue;
		}
		Utils::Sleep(sleepTime);
		Clear();
		player->Update();
		UpdatePipe();
		UpdateScore();
	}
}
void DynoGame::OnEnd()
{
	player->Draw();
	Utils::SetCursorPosition(10, 5);
	std::cout << "SCORE: " << score;
	Utils::SetCursorPosition(15, 6);
	std::cout << PRESS_ANY_KEY;
	_getch();
	Utils::SetCursor(true, 20);
}
void DynoGame::DisplayMenu()
{
	DisplayControls();
	score.Draw();
	Utils::SetCursorPosition(10, 5);
	std::cout << PRESS_ANY_KEY;
	_getch(); // _ => if not pragma warning
	Utils::SetCursorPosition(10, 5);
	std::cout << Utils::Separator(strlen(PRESS_ANY_KEY), ' ');
}
std::string DynoGame::GameName() const
{
    return "Dyno Game";
}
std::string DynoGame::GameDescription() const
{
    return " Dyno Game !";
}
