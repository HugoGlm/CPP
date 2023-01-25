#pragma once
#include "ItemCMD.h"

class Tree : public ItemCMD
{
#pragma region constructor
public:
	Tree() = default;
	~Tree() = default;
#pragma endregion
#pragma region methods
public:
	virtual std::string Name() override;
	virtual std::string Description() override;
	virtual void Exec() override;
#pragma endregion
};

