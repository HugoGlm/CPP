#include "TaskList.h"

std::string TaskList::Name()
{
    return "tasklist";
}
std::string TaskList::Description()
{
    return "Displays all currently running tasks including services.";
}
void TaskList::Exec()
{
    system("TaskList");
}
