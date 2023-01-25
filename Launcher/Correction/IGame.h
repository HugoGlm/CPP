#pragma once
#include "Object.h"
#include <string>


class IGame : public Object
{
#pragma region constructor
public:
	virtual ~IGame() = default;
#pragma endregion
#pragma region methods
	virtual void OnStart() = 0;
	virtual void OnUpdate() = 0;
	virtual void OnEnd() = 0;
	virtual void DisplayMenu() = 0;
	virtual std::string GameName() const = 0;
	virtual std::string GameDescription() const = 0;
#pragma endregion

};