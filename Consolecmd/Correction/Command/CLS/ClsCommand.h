#pragma once
#include "../ICommand.h"

UCLASS()
class ClsCommand : public ICommand
{
#pragma region constructor/destructor
public:
	ClsCommand() = default;
	~ClsCommand() override = default;
#pragma endregion constructor/destructor
#pragma region override
public:
	virtual bool Execute(const std::vector<std::string>& _args) override;
	virtual std::string CommandName() const override;
	virtual std::string Help() const override;
	virtual std::string AdvancedHelp() const override;
#pragma endregion override
};

