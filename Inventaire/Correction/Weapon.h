#pragma once
#include "CItem.h"

class Weapon : public CItem
{
#pragma region f/p
private:
	float damage = 0.0f;
#pragma endregion
#pragma region constructor
public:
	Weapon() = default;
	Weapon(const std::string& _name, const float _damage);
	Weapon(const Weapon& _copy);
#pragma endregion
#pragma region methods 
public:
	float Damage() const;
	void SetDamage(const float _damage);
	std::string ToString() const override;
	void OnUse(Entity* _entity) override;
#pragma endregion
};

