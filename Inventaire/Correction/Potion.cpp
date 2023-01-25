#include <iostream>
#include "Potion.h"

#pragma region constructor
Potion::Potion(const std::string& _name, const float _value) : CItem(_name)
{
	value = _value;
}
Potion::Potion(const Potion& _copy)
{
	value = _copy.value;
}
#pragma endregion
#pragma region methods
float Potion::Value() const
{
	return value;
}
std::string Potion::ToString() const
{
	return CItem::ToString() + " value: " + std::to_string(value);
}
void Potion::OnUse(Entity* _entity)
{
	CItem::OnUse(_entity);
}
bool Potion::Equals(const CItem* _other) const
{
	const Potion* _potion = dynamic_cast<const Potion*>(_other);
	if (_potion == nullptr)
		return false;
	const bool _result = CItem::Equals(_other) && value == _potion->value;
	return _result;
}
#pragma endregion