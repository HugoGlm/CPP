#include "TaskListCommand.h"
#pragma region override
bool TaskListCommand::Execute(const std::vector<std::string>& _args)
{
    system("tasklist");
    return true;
}

std::string TaskListCommand::CommandName() const
{
    return "tasklist";
}

std::string TaskListCommand::Help() const
{
    return "displays all currently running tasks including services.";
}

std::string TaskListCommand::AdvancedHelp() const
{
    std::string _result = "Description:\n";
    _result += "\tThis tool displays a list of currently running process on local machine";
    return _result;
}
#pragma endregion override