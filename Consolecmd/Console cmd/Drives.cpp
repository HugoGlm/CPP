#include "Drives.h"
#include "Utils.h"
#include <Windows.h>
#include <iostream>
#include <string>

#define BUFSIZE 512

std::string Drives::Name()
{
	return "drives";
}
std::string Drives::Description()
{
	return "Display all drives in the computer";
}

void Drives::Exec()
{
	std::string _res;
	TCHAR szTemp[BUFSIZE];
	szTemp[0] = '\0';
	if (GetLogicalDriveStringsW(BUFSIZE - 1, szTemp))
	{
		TCHAR szDrive[3] = TEXT(" :");
		BOOL bFound = FALSE;
		TCHAR* p = szTemp;
		while (!bFound && !*p)
		{
			*szDrive = *p;
			while (*p++);
		}
		for (TCHAR _d : szTemp)
		{
			if (_d == '\0')
			{
				std::cout << _res << std::endl;
				_res = "";
			}
			else
				_res += _d;
		}
	}
}
