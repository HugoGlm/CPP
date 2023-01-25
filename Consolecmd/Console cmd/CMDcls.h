#pragma once
#include "ItemCMD.h"
#include "Utils.h"

class CMDcls : public ItemCMD
{
#pragma region constructor
public:
	CMDcls() = default;
	~CMDcls() = default;
#pragma endregion
#pragma region methods
public:
	virtual std::string Name() override;
	virtual std::string Description() override;
	virtual void Exec() override;
#pragma endregion
};

