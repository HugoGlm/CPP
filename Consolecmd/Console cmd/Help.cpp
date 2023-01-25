#include "Help.h"
#include "Utils.h"

Help::Help(Time* _time, TaskList* _taskList, CMDecho* _echo, CMDcls* _cls, Drives* _drives, Exit* _exit, Type* _type, Tree* _tree, Cd* _cd)
{
	time = _time;
	taskList = _taskList;
	echo = _echo;
	cls = _cls;
	drives = _drives;
	exit = _exit;
	type = _type;
	tree = _tree;
	cd = _cd;
}
Help::Help(const Help& _copy)
{
	time = _copy.time;
	taskList = _copy.taskList;
	echo = _copy.echo;
	cls = _copy.cls;
	drives = _copy.drives;
	exit = _copy.exit;
	type = _copy.type;
	tree = _copy.tree;
	cd = _copy.cd;
}
Help::~Help()
{
	time = nullptr;
	taskList = nullptr;
	echo = nullptr;
	cls = nullptr;
	drives = nullptr;
	exit = nullptr;
	type = nullptr;
	tree = nullptr;
	cd = nullptr;
}
std::string Help::Name()
{
	return "help";
}
std::string Help::Description()
{
	return "Provides Help information for Windows commands.";
}
void Help::Exec()
{
	Utils::Log("----------HELP----------");
	Utils::Help(cd->Name(), cd->Description());
	Utils::Help(cls->Name(), cls->Description());
	Utils::Help(drives->Name(), drives->Description());
	Utils::Help(echo->Name(), echo->Description());
	Utils::Help(exit->Name(), exit->Description());
	Utils::Help(Name(), Description()); // le Help
	Utils::Help(taskList->Name(), taskList->Description());
	Utils::Help(time->Name(), time->Description());
	Utils::Help(tree->Name(), tree->Description());
	Utils::Help(type->Name(), type->Description());
	Utils::Log("------------------------");
}
