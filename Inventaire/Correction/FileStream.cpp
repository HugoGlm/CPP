#include "FileStream.h"
#include "FileReader.h"

#pragma region constructor
FileStream::FileStream(const std::string& _path)
{
    reader = new FileReader(_path);
}
FileStream::FileStream(const FileStream& _copy)
{
    reader = _copy.reader;
}
#pragma endregion
#pragma region methods
void FileStream::Close() const
{
    reader->Close();
}
FileReader* FileStream::Reader() const
{
    return reader;
}
bool FileStream::IsValid() const
{
    return reader->IsOpen();
}
#pragma endregion