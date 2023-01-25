#include <iostream>
#include <map>
#include <vector>
#include <string>
#include "TranslateManager.h"
#include "Language.h"
#include "Utils.h"
#include "StringUtils.h"

int main()
{
	setlocale(LC_ALL, "");
	TranslateManager manager = TranslateManager();
	Utils::Log(manager.GetMessage("fr", "hello"));
	Utils::Log(manager.GetMessage("en", "hello"));
}