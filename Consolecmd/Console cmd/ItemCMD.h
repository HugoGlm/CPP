#pragma once
#include <string>


class ItemCMD
{
#pragma region f/p
private:
	std::string name = "";
	std::string description = "";
#pragma region
#pragma region constructor
public:
	ItemCMD() = default;
	ItemCMD(const std::string _name, const std::string _desc);
	~ItemCMD();
#pragma region
#pragma region methods
	virtual std::string Name() = 0;
	virtual std::string Description() = 0;
	virtual void Exec() = 0;
#pragma region
};

