#pragma once
#include <iostream>
#include "ItemCMD.h"

class CMDecho : public ItemCMD
{
#pragma region constructor
public:
	CMDecho() = default;
	~CMDecho() = default;
#pragma endregion
#pragma region methods
public:
	virtual std::string Name() override;
	virtual std::string Description() override;
	virtual void Exec() override;
#pragma endregion
};

