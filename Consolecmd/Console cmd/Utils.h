#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
#include <format>
#include <vector>

#define color_white 15
#define color_red 4

class Utils
{
private:
	static inline HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	static inline COORD cursorPosition = {};
#pragma region Log
public:
	static void LogWithEffect(const std::string& _msg, const int _time = 20);
	static void Log(const std::string& _str);
	static void LogError(const std::string& _str);
	static void Help(const std::string& _desc, const std::string& _title);
#pragma endregion
#pragma region Utils
public:
	static std::string CurrentPath();
	static std::string GetPath(const std::string& _path);
	static std::string Replace(const std::string& _str, const char& _old, const char& _new);
	static std::string Replace(const std::string& _str, const std::string& _old, const std::string& _new);
	static std::vector<std::string> Parse(std::string _cmd);
	static void ClearConsole();
#pragma endregion
};