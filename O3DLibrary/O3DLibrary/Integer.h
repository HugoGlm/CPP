#pragma once
#include "Object.h"
#include <limits>

namespace Core
{
	namespace PrimitiveType
	{
		class Boolean;
		class FString;
		class O3DLIBRARY_API Integer sealed : public Object
		{
#pragma region var
		private:
			int value = INT_MIN;
		public:
			static Integer MinValue();
			static Integer MaxValue();
#pragma endregion

#pragma region const
		public:
			Integer() = default;
			Integer(const int _val);
			Integer(const Integer& _copy);
#pragma endregion

#pragma region methods
		public:
			Boolean Equals(const Integer& _other) const;
			static Integer Parse(const FString& _str);
			static Boolean TryParse(const FString& _str, Integer& _out);
#pragma endregion

#pragma region override
		public:
			FString ToString() const override;
			Boolean Equals(const Object* _obj) const override;
#pragma endregion

#pragma region operator
		public:
			operator int() const;
			Object& operator=(const Object* obj);
			Integer operator+(const Integer& _other) const;
			Integer operator++(int);
			Integer operator++();
			Integer& operator+=(const Integer& _other);
			Integer operator--(int);
			Integer operator--();
			Integer operator-(const Integer& _other) const;
			Integer& operator-=(const Integer& _other);
			Integer operator*(const Integer& _other) const;
			Integer& operator*=(const Integer& _other);
			Integer operator/(const Integer& _other) const;
			Integer& operator/=(const Integer& _other);
			Integer operator%(const Integer& _other) const;
			Integer& operator%=(const Integer& _other);
			Integer operator-();
			Boolean operator<(const Integer& _other) const;
			Boolean operator<=(const Integer& _other) const;
			Boolean operator>(const Integer& _other) const;
			Boolean operator>=(const Integer& _other) const;
			Boolean operator==(const Integer& _other) const;
			Boolean operator!=(const Integer& _other) const;
#pragma endregion
		};
	}
}