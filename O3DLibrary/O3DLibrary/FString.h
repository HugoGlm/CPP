#pragma once
#include "Object.h"
#include <string>
#include <ostream>
#include <vector>

namespace Core
{
	namespace PrimitiveType
	{
#pragma warning(disable: 4996)

		class Boolean;
		class Integer;

		class O3DLIBRARY_API FString : public Object
		{
#pragma region f/p
		private:
			const char* value = "";
			int length = 0;
		public:
			static const FString Empty;
#pragma endregion 

#pragma region constructor/destructor
		public:
			FString();
			FString(const char* _value);
			FString(const FString& _copy);
			FString(std::string::iterator _begin, std::string::iterator _end);
#pragma endregion 

#pragma region methods
		public:
			static std::vector<std::string> Split(const std::string& _str, const char _c);
			void Append(const char _char);
			void Append(const FString& _value);
			static FString Convert(const std::wstring& _wstring);
			FString SubString(const int _begin, const int _end) const;
			FString SubString(const int _begin) const;
			FString Replace(const char _old, const char _new) const;
			FString Replace(const FString& _old, const FString& _new) const;
			FString Trim() const;
			FString ToUpper() const;
			FString ToLower() const;
			Integer Length() const;
			Boolean StartWith(const char _c) const;
			Boolean StartWith(const FString& _str) const;
			Boolean EndWith(const char _c) const;
			Boolean EndWith(const FString& _str) const;
			Boolean Contains(const FString& _str) const;
			Integer LastIndexOf(const char _c) const;
			Integer FirstIndexOf(const char _c) const;
			Integer Find(const FString& _str) const;
			std::wstring ToWString() const;
			const char* ToCstr() const;
			static Boolean IsNullOrEmpty(const FString& _str);
			Boolean Equals(const FString& _other) const;
			template<typename ...Args>
			static FString Format(const FString& _str, Args... _args);
#pragma endregion

#pragma region override
		public:
			FString ToString() const override;
			Boolean Equals(const Object* _obj) const override;
#pragma endregion

#pragma region operator
			operator const char* () const;
			friend std::ostream& operator<<(std::ostream& _os, const FString& _str);
			Boolean operator==(const FString& _other) const;
			Boolean operator!=(const FString& _other) const;
			FString operator+(const FString& _other) const;
			FString& operator+=(const FString& _other);
			char operator[](const int _index);
#pragma endregion
		};

#pragma region methods
		template<typename ...Args>
		FString FString::Format(const FString& _str, Args ..._args)
		{
			FString _result = "";
			std::vector<object> _arguments = std::vector<object>();
			//size_t _count = sizeof...(_args); //=> nombre d'arguments dans _args
			(_arguments.push_back(&_args), ...);
			int _index = 0;
			for (int i = 0; i < _str.length; i++)
			{
				if (_str[i] == '{' && _str[i + 1] == '}')
				{
					_result.Append(_arguments[_index]->ToString());
					_index++, i++;
				}
				else _result.Append(_str[i]);
			}
			return _result;
		}
#pragma endregion
	}
}