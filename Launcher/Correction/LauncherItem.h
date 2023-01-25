#pragma once
#include "Object.h"

class IGame;

class LauncherItem : public Object
{
#pragma region f/p
private:
	IGame* game = nullptr;
#pragma endregion
#pragma region constructor
public:
	LauncherItem() = default;
	LauncherItem(IGame* _game);
	LauncherItem(const LauncherItem& _copy);
	~LauncherItem() override;
#pragma endregion
#pragma region methods
public:
	void OnClick();
	void Display();
	IGame* Game() const;
#pragma endregion
};

