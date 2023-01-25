#pragma once
#include <map>
#include <string>

class Language;

class TranslateManager
{
#pragma region f/p
private:
	std::map<std::string, Language*> languages = std::map<std::string, Language*>();
#pragma endregion f/p
#pragma region constructor
public:
	TranslateManager();
#pragma endregion constructor
#pragma region methods
public:
	void InitLanguages();
	Language* GetLanguage(const std::string& _languageName);
	Language* AddLanguage(const std::string& _languageName);
	std::string GetMessage(const std::string& _languageName, const std::string& _key);
#pragma endregion methods
};
