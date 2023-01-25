#pragma once
#include "Potion.h"

class HealPotion : public Potion
{
#pragma region constructor
public:
	HealPotion() = default;
	HealPotion(const float _value);
#pragma endregion
#pragma region methods
public:
	void OnUse(Entity* _entity) override;
#pragma endregion
};

