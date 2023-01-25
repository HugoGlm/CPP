#pragma once
#include "Entity.h"
#include "CInventory.h"


class Mob : public Entity
{
#pragma region f/p
private:
	CInventory* inventory = nullptr;
#pragma endregion
#pragma region constructor
public:
	Mob() = default;
	Mob(const std::string& _name, Vector2 _position, const float _maxLife = 100.0f, const float _maxMana = 100.0f);
	Mob(const Mob& _copy);
	~Mob();
#pragma endregion
#pragma region methods
public:
	CInventory* GetInventory() const;
#pragma endregion
};