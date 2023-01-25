#pragma once
#include <iostream>
#include "TaskList.h"
#include "CMDecho.h"
#include "CMDcls.h"
#include "Drives.h"
#include "Utils.h"
#include "Time.h"
#include "Exit.h"
#include "Type.h"
#include "Tree.h"
#include "Cd.h"

class Help : public ItemCMD
{
#pragma	region f/p
private:
	Time* time = new Time();
	TaskList* taskList = new TaskList();
	CMDecho* echo = new CMDecho();
	CMDcls* cls = new CMDcls();
	Drives* drives = new Drives();
	Exit* exit = new Exit();
	Type* type = new Type();
	Tree* tree = new Tree();
	Cd* cd = new Cd();
#pragma endregion
#pragma	region constructor
public:
	Help() = default;
	Help(Time* _time, TaskList* _taskList, CMDecho* _echo, CMDcls* _cls, Drives* _drives, Exit* _exit, Type* _type, Tree* _tree, Cd* _cd);
	Help(const Help& _copy);
	~Help();
#pragma endregion
#pragma	region methods
public:
	virtual std::string Name() override;
	virtual std::string Description() override; 
	virtual void Exec() override;
#pragma endregion
};

