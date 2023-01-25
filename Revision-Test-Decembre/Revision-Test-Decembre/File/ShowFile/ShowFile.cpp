#include "ShowFile.h"
#include "../../Path/Path.h"
#include "../../Environment/Environment.h"
#include "../../File/File.h"
#include "../../File/FileStream/FileStream.h"
#include "../../File/FileReader/FileReader.h"
#include <vector>

#pragma region constructor
ShowFile::ShowFile(const std::string& _name)
{
	name = _name;
	filePath = Path::Combine(Environment::CurrentDirectory(), "Path", _name + ".txt");
	stream = File::Create(filePath);
	Init();
}
ShowFile::~ShowFile()
{
	stream->Close();
	delete stream;
	stream = nullptr;
}
void ShowFile::Init()
{
	if (!stream->IsValid())
		return;
	const std::vector<std::string> _allLines = stream->Reader()->GetAllLines();
	for (int i = 0; i < _allLines.size(); i++)
	{
		const std::string _line = _allLines[i];
		std::string _key = _line.substr(0, _line.find_last_of(':'));
		Object::Replace(_key, " ", "");
		if (allMessages.contains(_key))
			continue;
		std::string _message = _line.substr(_line.find_last_of(':') + 1);
		allMessages.insert(std::pair(_key, _message));
	}
}
std::string ShowFile::GetMessages(const std::string& _key) const
{
	if (!allMessages.contains(_key))
		return "";
	return allMessages.at(_key);
}
std::string ShowFile::Name() const
{
	return name;
}
std::string ShowFile::FilePath() const
{
	return filePath;
}
#pragma endregion

