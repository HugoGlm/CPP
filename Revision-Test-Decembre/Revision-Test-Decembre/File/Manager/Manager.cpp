#include "Manager.h"
#include "../../Path/Path.h"
#include "../../Environment/Environment.h"
#include "../../Directory/Directory.h"
#include "../../File/ShowFile/ShowFile.h"

#pragma region constructor
Manager::Manager()
{
    InitShowFile();
}
#pragma endregion

#pragma region methods
void Manager::InitShowFile()
{
    const std::string& _path = Path::Combine(Environment::CurrentDirectory(), "Path");
    if (!Directory::Exist(_path))
        return;
    for (const std::filesystem::directory_entry& _entry : std::filesystem::directory_iterator(_path.c_str()))
    {
        if (_entry.is_directory())
            continue;
        std::string _filePath = Path::GetPath(_entry.path().string());
        std::string _fileName = _filePath.substr(_filePath.find_last_of('/') + 1);
        _fileName = _fileName.substr(0, _fileName.find_last_of('.'));
        ShowFiles.insert(std::pair(_fileName, new ShowFile(_fileName)));
    }
}
ShowFile* Manager::GetShowFile(const std::string& _ShowFileName)
{
    if (!ShowFiles.contains(_ShowFileName))
        return nullptr;
    return ShowFiles[_ShowFileName];
}
ShowFile* Manager::AddShowFile(const std::string& _ShowFileName)
{
    if (ShowFiles.contains(_ShowFileName))
        return ShowFiles[_ShowFileName];
    ShowFile* _newShowFile = new ShowFile(_ShowFileName);
    ShowFiles.insert(std::pair(_ShowFileName, _newShowFile));
    return _newShowFile;
}
std::string Manager::GetMesssage(const std::string& _ShowFileName, const std::string& _key)
{
    ShowFile* _ShowFile = GetShowFile(_ShowFileName);
    if (_ShowFile == nullptr)
        return "";
    return _ShowFile->GetMessages(_key);
}
#pragma endregion

