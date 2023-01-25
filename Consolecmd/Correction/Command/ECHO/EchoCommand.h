#pragma once
#include "../ICommand.h"

UCLASS()
class EchoCommand : public ICommand
{
#pragma region f/p
private:
    bool isOn = true;
#pragma endregion f/p
#pragma region constructor/destructor
public:
    EchoCommand() = default;
    ~EchoCommand() override = default;
#pragma endregion constructor/destructor
#pragma region override
public:
    virtual bool Execute(const std::vector<std::string>& _args) override;
    virtual std::string CommandName() const override;
    virtual std::string Help() const override;
    virtual std::string AdvancedHelp() const override;
#pragma endregion override
};

