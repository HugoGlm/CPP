#pragma once
#include "ItemCMD.h"

class Cd : public ItemCMD
{
#pragma region constructor
public:
	Cd() = default;
	~Cd() = default;
#pragma endregion
#pragma region methods
public:
	virtual std::string Name() override;
	virtual std::string Description() override;
	virtual void Exec() override;
#pragma endregion
};

