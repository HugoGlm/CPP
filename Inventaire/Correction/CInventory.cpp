#include <iostream>
#include "CInventory.h"
#include "CItem.h"
using namespace std;

#pragma region const/dest
CInventory::CInventory(const string& _name, Entity* _owner)
{
	name = _name;
	owner = _owner;
}
CInventory::CInventory(const CInventory& _copy)
{
	name = _copy.name;
	items = _copy.items;
	owner = _copy.owner;
}
CInventory::~CInventory()
{
	items.clear();
}
#pragma endregion
size_t CInventory::FindItem(const CItem* _item)
{
	const size_t _size = items.size();
	for (size_t i = 0; i < _size; i++)
	{
		if (_item->Equals(items[i]))
			return i;
	}
	return -1;
}
void CInventory::AddItem(CItem* _item)
{
	const size_t _index = FindItem(_item);
	if (_index == -1)
		items.push_back(_item);
	else
		items[_index]->AddStack(1);
}
void CInventory::UseItem(const int _index)
{
	const int currentIndex = _index - 1;
	if (currentIndex < 0 || currentIndex > items.size())
		throw std::exception("invalid index");
	CItem* _item = items[currentIndex];
	if (_item == nullptr)
		return;
	_item->OnUse(owner);
	if (_item->Stack() == 0)
		RemoveItem(_item);
}
void CInventory::RemoveItem(CItem* _item)
{
	const size_t _index = FindItem(_item);
	if (_index == -1)
		return;
	else
		items.erase(items.begin() + _index);
}
void CInventory::Clear()
{
	items.clear();
}
int CInventory::Count() const
{
	return (int)items.size();
}
void CInventory::DisplayInventory()
{
	cout << "______________________" << name << "______________________" << endl;
	const size_t _size = items.size();
	for (size_t i = 0; i < _size; i++)
	{
		cout << i + 1 << ": " << items[i]->ToString() << endl;
	}
	cout << "______________________" << std::string(name.size(), '-') << "______________________" << endl;
}
vector<CItem*> CInventory::Items() const
{
	return items;
}
