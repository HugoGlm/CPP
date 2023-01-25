#pragma once
#include <vector>
#include <iostream>

class Case;
class Player;
class Vector2;

class Map
{
#pragma region f/p
private:
	std::vector<Case*> cases = std::vector<Case*>();
	std::string mapName = "default name";
	std::string mapPath = "";
	Case* enter = nullptr;
	Case* exit = nullptr;
	Case* mob = nullptr;
	Player* player = nullptr;
#pragma endregion
#pragma region constructor
public:
	Map() = default;
	Map(const std::string& _mapPath);
	Map(const Map& _copy);
	~Map();
#pragma endregion
#pragma region methods
private:
	void Init();
public:
	void Display();
	bool IsValid();
	Case* GetCaseAtPosition(const Vector2& _position);
	void SetPlayer(Player* _player);
	Player* GetPlayer() const;
	Case* Enter() const;
	Case* Exit() const;
	Case* Mob() const;
	std::string MapName() const;
#pragma endregion
};

