#pragma once
#include "Object.h"

namespace Core
{
	namespace IO
	{
		class Boolean;

		class Directory : public Object
		{
#pragma region methods
		public:
			O3DLIBRARY_API static void MakeDirectory(const PrimitiveType::FString& _path);
			O3DLIBRARY_API static PrimitiveType::Boolean Exist(const Core::PrimitiveType::FString& _path);
#pragma endregion

		};
	}
}
