#pragma once
#include "Object.h"

namespace Core
{
	namespace IO
	{
		class TextWritter;
		class TextReader;

		class FileStream : public Object
		{
#pragma region f/p
		private:
			const char* path = "";
			TextReader* reader = nullptr;
			TextWritter* writter = nullptr;
#pragma endregion
#pragma region constructor
		public:
			O3DLIBRARY_API FileStream() = default;
			O3DLIBRARY_API FileStream(const char* _path);
			O3DLIBRARY_API FileStream(const FileStream& _copy);
			O3DLIBRARY_API ~FileStream() override;
#pragma endregion
#pragma region methods
		public:
			O3DLIBRARY_API void Close();
			O3DLIBRARY_API TextReader* Reader() const;
			O3DLIBRARY_API TextWritter* Writter() const;
			O3DLIBRARY_API PrimitiveType::FString Path() const;
			O3DLIBRARY_API PrimitiveType::Boolean Equals(const FileStream& _other) const;
#pragma endregion
#pragma region override
		public:
			O3DLIBRARY_API PrimitiveType::FString ToString() const override;
			O3DLIBRARY_API PrimitiveType::Boolean Equals(const Object* _obj) const override;
#pragma endregion
#pragma region operator
		public:
			O3DLIBRARY_API void operator<<(const Object* _obj);
			O3DLIBRARY_API void operator<<(const Object& _obj);
#pragma endregion

		};
	}
}