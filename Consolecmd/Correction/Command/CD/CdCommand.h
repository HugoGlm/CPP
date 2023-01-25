#pragma once
#include "../ICommand.h"

UCLASS()
class CdCommand : public ICommand
{
#pragma region methods
private:
    static std::string GetProfileFolder();
#pragma endregion methods

#pragma region f/p
public:
    static inline std::string CurrentPath = GetProfileFolder();
#pragma endregion f/p
#pragma region constructor/destructor
public:
    CdCommand() = default;
    ~CdCommand() override = default;
#pragma endregion constructor/destructor
#pragma region override
public:
    virtual bool Execute(const std::vector<std::string>& _args) override;
    virtual std::string CommandName() const override;
    virtual std::string Help() const override;
    virtual std::string AdvancedHelp() const override;
#pragma endregion override
};

