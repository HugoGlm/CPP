#pragma once
#include "Object.h"

namespace Core
{
	namespace PrimitiveType
	{
		class FString;
	}
	namespace Diagnostics
	{
		class Process : public Object
		{
#pragma region methods
		public:
			O3DLIBRARY_API static void Start(const Core::PrimitiveType::FString& _path, const Core::PrimitiveType::FString& _parameters);
			
#pragma endregion

		};
	}
}