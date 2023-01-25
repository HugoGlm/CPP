#pragma once
#include "Object.h"

namespace Core
{
	namespace IO
	{
		class TextReader;
		class TextWritter;
		class FileStream;

		class File : public Object
		{

#pragma region f/p
		private:
			const char* path = nullptr;
#pragma endregion
#pragma region constructor
		public:
			O3DLIBRARY_API File() = default;
			O3DLIBRARY_API File(const char* _path);
			O3DLIBRARY_API File(const File& _copy);
			O3DLIBRARY_API ~File();
#pragma endregion
#pragma region methods
		public:
			O3DLIBRARY_API static FileStream* Create(const PrimitiveType::FString& _path);
			O3DLIBRARY_API static PrimitiveType::Boolean Exist(const PrimitiveType::FString& _path);
#pragma endregion

		};
	}
}
