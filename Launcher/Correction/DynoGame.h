#pragma once
#include "IGame.h"
#include "DynoScore.h"

#define SCREEN_WIDTH 90
#define SCREEN_HEIGHT 26
#define WIN_WIDTH 70
#define MENU_WIDTH 20
#define SLEEP_DEFAULT 100
#define GAP_SIZE 7
#define PRESS_ANY_KEY "Press any key..."

class DynoMap;
class DynoPlayer;
class DynoPipe;

class DynoGame : public IGame
{
#pragma region f/p
private:
	DynoMap* map = nullptr;
	DynoPlayer* player = nullptr;
	DynoPipe* pipeOne = nullptr;
	DynoPipe* pipeTwo = nullptr;
	DynoScore score = DynoScore();
	bool isQuitting = false;
	int sleepTime = 0;
#pragma endregion
#pragma region constructor
public:
	DynoGame();
	~DynoGame() override;
#pragma endregion
#pragma region methods
private:
	void Draw();
	void Clear();
	void DisplayControls();
	void UpdatePipe();
	void Init();
	void UpdateScore();
#pragma endregion
#pragma region override
public:
	virtual void OnStart() override;
	virtual void OnUpdate() override;
	virtual void OnEnd() override;
	virtual void DisplayMenu() override;
	virtual std::string GameName() const override;
	virtual std::string GameDescription() const override;
#pragma endregion
};

