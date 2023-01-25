#pragma once
#include "Object.h"
#include "FString.h"
#include "Hash.h"

namespace Core
{
	namespace Collection
	{
		template<typename TKey, typename TValue>
		class O3DLIBRARY_API KeyValuePair : public Object
		{
			static_assert(std::is_base_of_v<Object, TKey>, "Key must be an inherited of Object");
			static_assert(std::is_base_of_v<Object, TValue>, "Value must be an inherited of Object");
#pragma region f/p
		private: 
			TKey key = TKey();
			TValue value = TValue();
#pragma endregion
#pragma region constructor
		public:
			KeyValuePair() = default;
			KeyValuePair(const TKey& _key, const TValue& _value)
			{
				key = _key;
				value = _value;
			}
			KeyValuePair(const KeyValuePair& _copy)
			{
				key = _copy.key;
				value = _copy.value;
			}
#pragma endregion
#pragma region methods
		public:
			TKey Key() const
			{
				return key;
			}
			TValue& Value()
			{
				return value;
			}
			TValue Value() const
			{
				return value;
			}
#pragma endregion

#pragma region override
		public:
			PrimitiveType::FString ToString() const override
			{
				const PrimitiveType::FString& _keyStr = Utils::Hash::GetObjectToString(key);
				const PrimitiveType::FString& _valueStr = Utils::Hash::GetObjectToString(value);
				return PrimitiveType::FString::Format("Key: {}, Value: {}", _keyStr, _valueStr);
			}
			int GetHashCode() const override
			{
				return Utils::Hash::GetObjectHashCode(key) ^ Utils::Hash::GetObjectHashCode(value) << 1;
			}
#pragma endregion
#pragma region operator
		public:
			KeyValuePair operator=(const KeyValuePair& _other)
			{
				key = _other.key;
				value = _other.value;
				return* this;
			}
			bool operator==(const KeyValuePair& _other)
			{
				return key == _other.key && value == _other.value;
			}
			bool operator !=(const KeyValuePair& _other)
			{
				return !(*this == _other);
				// return !this->operator==(_other); // method 2
			}
			bool operator==(const TKey& _key)
			{
				return key == _key;
			}
			bool operator !=(const TKey& _key)
			{
				return !(*this == _key);
				// return !this->operator==(_key); // method 2
			}
			
#pragma endregion

		};
	}
}