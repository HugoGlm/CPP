#pragma once
#include "../ICommand.h"

UCLASS()
class HelpCommand : public ICommand
{
#pragma region override
    virtual bool Execute(const std::vector<std::string>& _args) override;
    virtual std::string CommandName() const override;
    virtual std::string Help() const override;
    virtual std::string AdvancedHelp() const override;
#pragma endregion override

};