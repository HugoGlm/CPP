#pragma once
#include "Object.h"
#include "FString.h"

namespace Core
{
	namespace PrimitiveType
	{
		class Boolean sealed : public Object
		{
#pragma region f/p
		private:
			bool value = false;
#pragma endregion
#pragma region constructor
		public:
			O3DLIBRARY_API Boolean() = default;
			O3DLIBRARY_API Boolean(const bool _value);
			O3DLIBRARY_API Boolean(const Boolean& _copy);
#pragma endregion
#pragma region override
		public:
			O3DLIBRARY_API FString ToString() const override;
#pragma endregion
#pragma region operator
		public:
			Boolean operator==(const Boolean& _other) const;
			Boolean operator!=(const Boolean& _other) const;
			operator bool() const;
			Boolean operator!() const;
#pragma endregion

		};
	}
}
