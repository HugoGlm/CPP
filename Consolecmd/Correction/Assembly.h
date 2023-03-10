#pragma once
#include "Domain/AppDomain.h"

#include "Command/CD/CdCommand.h"
REGISTER_CLASS(CdCommand)
#include "Command/CLS/ClsCommand.h"
REGISTER_CLASS(ClsCommand)
#include "Command/DRIVES/DrivesCommand.h"
REGISTER_CLASS(DrivesCommand)
#include "Command/ECHO/EchoCommand.h"
REGISTER_CLASS(EchoCommand)
#include "Command/EXIT/ExitCommand.h"
REGISTER_CLASS(ExitCommand)
#include "Command/HELP/HelpCommand.h"
REGISTER_CLASS(HelpCommand)
#include "Command/TASKLIST/TaskListCommand.h"
REGISTER_CLASS(TaskListCommand)
#include "Command/TIME/TimeCommand.h"
REGISTER_CLASS(TimeCommand)
#include "Command/TREE/TreeCommand.h"
REGISTER_CLASS(TreeCommand)
#include "Command/TYPE/TypeCommand.h"
REGISTER_CLASS(TypeCommand)
#include "Object/Object.h"
REGISTER_CLASS(Object)

