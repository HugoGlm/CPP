#pragma once
#include <string>
using namespace std;

class Entity;

class CItem
{
#pragma region Var
private:
	string name = "";
	bool isStackable = true;
	int stack = 1;
	int maxStack = 64;
#pragma endregion

#pragma region const/dest
public:
	CItem() = default;

	CItem(const string& _name);

	CItem(const CItem& _copy);

	virtual ~CItem() = default;
#pragma endregion

#pragma region Methods
public:
	bool IsStackable() const;
	int Stack() const;
	int MaxStack() const;
	void SetIsStackable(const bool _status);
	void AddStack(const int _value);
	void SetStack(const int _stack);
	void SetMaxStack(const int _maStack);
	virtual void OnUse(Entity* _entity);
	virtual string ToString() const;
	virtual bool Equals(const CItem* _other) const;
#pragma endregion

};
