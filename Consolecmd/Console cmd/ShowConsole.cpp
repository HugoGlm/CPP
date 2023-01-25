#include "ShowConsole.h"
#include "TaskList.h"
#include "CMDecho.h"
#include "CMDcls.h"
#include "Drives.h"
#include "Utils.h"
#include "Time.h"
#include "Help.h"
#include "Exit.h"
#include "Type.h"
#include "Tree.h"
#include "Cd.h"
#include <string>
#include <format>
#include <Windows.h>

#pragma comment(lib, "version.lib")

ShowConsole::ShowConsole()
{
	items.push_back(new TaskList);
	items.push_back(new CMDecho);
	items.push_back(new Drives);
	items.push_back(new CMDcls);
	items.push_back(new Help);
	items.push_back(new Time);
	items.push_back(new Exit);
	items.push_back(new Type);
	items.push_back(new Tree);
	items.push_back(new Cd);
}
void ShowConsole::Show()
{
	Utils::Log(Version());
	while ("exit")
	{
		std::cout << Utils::CurrentPath() << "> ";
		std::string _input = "";
		std::getline(std::cin, _input);
		std::vector<std::string> _cmd = Utils::Parse(_input);
		int _index = FindIndex(_cmd[0]);
		if (_index == -1)
			Utils::Log(_cmd[0] + "is not command !");
		else
			items[_index]->Exec();
	}
}
std::string ShowConsole::Version()
{
	/*#include "kernel32.dll"
	VS_FIXEDFILEINFO* info
	GetFileVersionInfoSizeExW;
	VerQueryValueW;*/
	return "Microsoft Windows [version " /*+ */ "]\n(c)Microsoft Corporation.All rights reserved."; //TODO version
}
int ShowConsole::FindIndex(const std::string _cmd)
{
	int _index = - 1;
	for (int i = 0; i < items.size(); i++)
		if (items[i]->Name() == _cmd)
	return i;
}