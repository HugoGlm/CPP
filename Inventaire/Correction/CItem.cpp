#include "CItem.h"
#include "Utils.h"

#pragma region const/dest
CItem::CItem(const string& _name)
{
	name = _name;
}

CItem::CItem(const CItem& _copy)
{
	name = _copy.name;
	isStackable = _copy.isStackable;
	stack = _copy.stack;
	maxStack = _copy.maxStack;
}
#pragma endregion


#pragma region methods
bool CItem::IsStackable() const
{
	return isStackable;
}

int CItem::Stack() const
{
	return stack;
}

int CItem::MaxStack() const
{
	return maxStack;
}

void CItem::SetIsStackable(const bool _status)
{
	isStackable = _status;
}

void CItem::AddStack(const int _value)
{
	if (!isStackable)
		return;
	stack = Utils::Clamp(stack + _value, 0, maxStack);
}

void CItem::SetStack(const int _stack)
{
	if (!isStackable)
		return;
	stack = Utils::Clamp(_stack, 0, maxStack);
}

void CItem::SetMaxStack(const int _maxStack)
{
	maxStack = _maxStack;
}

void CItem::OnUse(Entity* _entity)
{
	stack = Utils::Clamp(stack - 1, 0, maxStack);
}

string CItem::ToString() const
{
	return name + " x " + to_string(stack);
}

bool CItem::Equals(const CItem* _other) const
{
	return name == _other->name && isStackable == _other->isStackable;
}

#pragma endregion
