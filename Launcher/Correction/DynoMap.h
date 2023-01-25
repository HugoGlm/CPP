#pragma once
#include "IDrawable.h"

#define SLEEP_TIME_MAP 20

class DynoMap : public IDrawable
{
#pragma region constructor
public:
	DynoMap() = default;
	~DynoMap() override = default;
#pragma endregion
#pragma region methods
#pragma endregion
#pragma region override
	virtual void Draw() override;
	virtual void Erase() override;
	virtual void Update() override;
#pragma endregion
};

