#pragma once
#include "ItemCMD.h"

class TaskList : public ItemCMD
{
#pragma region constructor
public:
	TaskList() = default;
	~TaskList() = default;
#pragma endregion
#pragma region methods
public:
	virtual std::string Name() override;
	virtual std::string Description() override;
	virtual void Exec() override;
#pragma endregion
};