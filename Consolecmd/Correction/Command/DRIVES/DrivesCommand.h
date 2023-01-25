#pragma once
#include "../ICommand.h"

UCLASS()
class DrivesCommand : public ICommand
{
#pragma region override
public:
    virtual bool Execute(const std::vector<std::string>& _args) override;
    virtual std::string CommandName() const override;
    virtual std::string Help() const override;
    virtual std::string AdvancedHelp() const override;
#pragma endregion override

};

