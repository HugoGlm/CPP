#pragma once
#include "ItemCMD.h"
#include <iostream>

class Exit : public ItemCMD
{
#pragma region constructor
public:
	Exit() = default;
	~Exit() = default;
#pragma endregion
#pragma region methods
public:
	virtual std::string Name() override;
	virtual std::string Description() override;
	virtual void Exec() override;
#pragma endregion
	
};

