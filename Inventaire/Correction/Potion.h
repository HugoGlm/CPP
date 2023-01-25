#pragma once
#include <string>
#include "CItem.h"

class Potion : public CItem
{
#pragma region f/p
private:
	float value = 0.0f;
#pragma endregion
#pragma region constructor
public:
	Potion() = default;
	Potion(const std::string& _name, const float _value);
	Potion(const Potion& _copy);
#pragma endregion
#pragma region methods
public:
	float Value() const;
	std::string ToString() const override;
	void OnUse(Entity* _entity) override;
	bool Equals(const CItem* _other) const override;
#pragma endregion
};