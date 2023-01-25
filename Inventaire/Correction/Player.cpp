#include "Player.h"
#include "CInventory.h"
#include "Utils.h"
#include "Vector2.h"
#include "Case.h"
#include "Map.h"
#include "Mob.h"

#pragma region constructor / destructor
Player::Player(const std::string& _name, Vector2* _position, const float _maxLife, const float _maxMana)
	: Entity(_name, _position, _maxLife, _maxMana)
{
	inventory = new CInventory(_name + " Inventory", this);
}
Player::Player(const Player& _copy) : Entity(_copy)
{
	inventory = _copy.inventory;
}
Player::~Player()
{
	delete inventory;
}
#pragma endregion
#pragma region methods
CInventory* Player::GetInventory() const
{
	return inventory;
}
void Player::Move()
{
	char _input = Utils::UserChoice<char>("Move with z, q, s, d : ");
	Vector2 _position = *Position();
	switch (std::tolower(_input))
	{
	case 'z':
		_position -= Vector2(0, 1);
		break;
	case 'q':
		_position -= Vector2(1, 0);
		break;
	case 's':
		_position += Vector2(0, 1);
		break;
	case 'd':
		_position += Vector2(1, 0);
		break;
	default:
		break;
	}
	Case* _case = GetMap()->GetCaseAtPosition(_position);
	if (_case == nullptr || _case->IsWall())
		return;
	Position()->Set(_position);
	if (_case->HasMob())
		;
}
#pragma endregion