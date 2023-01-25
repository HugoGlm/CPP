#pragma once
#include "Entity.h"

class CInventory;
class Mob;

class Player : public Entity
{
#pragma region f/p
private:
	CInventory* inventory = nullptr;
#pragma endregion
#pragma region constructor / destructor
public:
	Player() = default;
	Player(const std::string& _name, Vector2* _position = new Vector2(0,0), const float _maxLife = 100.0f, const float _maxMana = 100.0f);
	Player(const Player& _copy);
	~Player();
#pragma endregion 
#pragma region methods
public:
	CInventory* GetInventory() const;
	void Move() override;
#pragma endregion
};

