#pragma once
#include "Object.h"
#include "O3DLibrary.h"

namespace Core
{
	namespace PrimitiveType
	{
		class FString;
	}
	class O3DLIBRARY_API ClipBoard
	{
#pragma region methods
	public:
		static void Copy(const PrimitiveType::FString& _text);
#pragma endregion

	};
}

