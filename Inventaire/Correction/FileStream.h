#pragma once
#include <iostream>

class FileReader;

class FileStream
{
#pragma region f/p
private:
	FileReader* reader = nullptr;
#pragma endregion
#pragma region constructor
public:
	FileStream() = default;
	FileStream(const std::string& _path);
	FileStream(const FileStream& _copy);
#pragma endregion
#pragma region methods
public:
	void Close() const;
	FileReader* Reader() const;
	bool IsValid() const;
#pragma endregion
};

