#include <iostream>
#include "HealPotion.h"
#include "Entity.h"

#pragma region constructor
HealPotion::HealPotion(const float _value) : Potion("Potion Health", _value)
{
}
#pragma endregion
#pragma region methods
void HealPotion::OnUse(Entity* _entity)
{
	Potion::OnUse(_entity);
	_entity->AddLife(Value());
	std::cout << "new life for " + _entity->Name() + ": " + std::to_string(_entity->Life()) << std::endl;
}
#pragma endregion