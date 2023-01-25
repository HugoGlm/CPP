#pragma once
#include "ItemCMD.h"

class Type : public ItemCMD
{
#pragma region constructor
public:
	Type() = default;
	~Type() = default;
#pragma endregion
#pragma region methods
public:
	virtual std::string Name() override;
	virtual std::string Description() override;
	virtual void Exec() override;
#pragma endregion
};

