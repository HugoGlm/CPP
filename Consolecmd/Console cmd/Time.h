#pragma once
#include "ItemCMD.h"

class Time : public ItemCMD
{
#pragma region constructor
public:
	Time() = default;
	~Time() = default;
#pragma endregion
#pragma region methods
public:
	virtual std::string Name() override;
	virtual std::string Description() override;
	virtual void Exec() override;
#pragma endregion
};

