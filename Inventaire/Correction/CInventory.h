#pragma once
#include <vector>
#include <string>
using namespace std;

class CItem;
class Entity;

class CInventory
{
#pragma region var
private:
	string name = "base inventory";
	vector<CItem*> items = vector<CItem*>();
	Entity* owner = nullptr;
#pragma endregion

#pragma region const/dest
public:
	CInventory() = default;
	CInventory(const string& _name, Entity* _owner);
	CInventory(const CInventory& _copy);
	virtual ~CInventory();
#pragma endregion

#pragma region methods
private:
	size_t FindItem(const CItem* _item);
public:
	void AddItem(CItem* _item);
	void UseItem(const int _item);
	void RemoveItem(CItem* _item);
	void Clear();
	int Count() const;
	void DisplayInventory();
	vector<CItem*> Items() const;
#pragma endregion


};

