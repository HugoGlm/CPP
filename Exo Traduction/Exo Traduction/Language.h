#pragma once
#include <string>
#include <map>

class FileStream;

class Language
{
#pragma region f/p
private:
	std::string languageName = "";
	std::string filePath = "";
	FileStream* stream = nullptr;
	std::map<std::string, std::string> allMessages = std::map<std::string, std::string>();
#pragma endregion f/p
#pragma region constructor
public:
	Language() = default;
	Language(const std::string& _languageName);
	~Language();
#pragma endregion constructor
#pragma region methods
	void InitMessages();
	std::string GetMessage(const std::string& _key) const;
	void AddMessageToFile(const std::string& _key, const std::string& _message);
	std::string LanguageName() const;
	std::string FilePath() const;
#pragma endregion methods
};

