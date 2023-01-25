#include "mob.h"

#pragma region constructor
Mob::Mob(const std::string& _name, Vector2 _position, const float _maxLife, const float _maxMana)
	: Entity(_name, _position, _maxLife, _maxMana)
{
	inventory = new CInventory(_name + " Inventory", this);
}
Mob::Mob(const Mob& _copy)
{
	inventory = _copy.inventory;
}
Mob::~Mob()
{
	delete inventory;
}
#pragma endregion
#pragma region methods
CInventory* Mob::GetInventory() const
{
	return inventory;
}
#pragma endregion