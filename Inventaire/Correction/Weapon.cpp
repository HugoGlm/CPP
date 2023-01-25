#include <iostream>
#include "Weapon.h"
#include "Entity.h"

#pragma region constructor
Weapon::Weapon(const std::string& _name, const float _damage) : CItem(_name)
{
	damage = _damage;
	SetIsStackable(false);
}
Weapon::Weapon(const Weapon& _copy)
{
	damage = _copy.damage;
}
#pragma endregion
#pragma region methods
float Weapon::Damage() const
{
	return damage;
}
void Weapon::SetDamage(const float _damage)
{
	damage = _damage < 0 ? 0 : _damage;
}
std::string Weapon::ToString() const
{
	return CItem::ToString() + ", damages: " + std::to_string(damage);
}
void Weapon::OnUse(Entity* _entity)
{
	_entity->TakeDamage(damage);
	std::cout << _entity->Name() + " receive: " + std::to_string(damage) + " damage !" << std::endl;
}
#pragma endregion