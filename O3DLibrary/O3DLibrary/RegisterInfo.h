#pragma once
#include "Object.h"

namespace Core
{
	namespace PrimitiveType
	{
		class Boolean;
		class FString;
	}
	class O3DLIBRARY_API RegisterInfo : public Object
	{
#pragma region f/p
	private:
		PrimitiveType::FString name = "";
#pragma endregion
#pragma region constructor
	public:
		RegisterInfo() = default;
		RegisterInfo(PrimitiveType::FString _name);
#pragma endregion
#pragma region methods
	public:
		RegisterInfo Register();
#pragma endregion

	};
}