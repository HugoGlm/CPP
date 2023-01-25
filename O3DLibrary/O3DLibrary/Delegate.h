#pragma once
#include "object.h"
#include "Exception.h"

namespace Core
{
	namespace Event
	{
		template<typename Res, typename... Params>
		class O3DLIBRARY_API Delegate : public Object
		{
#pragma region f/p
		private:
			typedef Res(Object::* Function) (Params...);
			Function functionPtr = nullptr;
			Object* instance = nullptr;
#pragma endregion
#pragma region constructor
		public:
			Delegate(nullptr_t)
			{
				instance = nullptr;
				functionPtr = nullptr;
			}
#pragma endregion
#pragma region methods
		public:
			template<typename Class>
			void SetDynamic(Class* _instance, Res(Class::* _ptr)(Params...))
			{
				if (!std::is_base_of_v<Object, Class>)
					throw Exception("Class must be inherited of Object");
				instance = _instance;
				functionPtr = reinterpret_cast<Function>(_ptr);
			}

			template<typename Class>
			void SetDynamic(nullptr_t, Res(Class::* _ptr)(Params...))
			{
				if (!std::is_base_of_v<Object, Class>)
					throw Exception("Class must be inherited of Object");
				instance = nullptr;
				functionPtr = nullptr;
			}

			Res Invoke(Params... _params)
			{
				if (instance == nullptr)
					throw Exception("Instance is nullptr !");
				if (functionPtr == nullptr)
					throw Exception("functionPtr is nullptr !");
				return (instance->*functionPtr) (_params...);
			}

			void* GetAddress() const
			{
				return (void*&)functionPtr;
			}
#pragma endregion
#pragma region operator
		public:
			void operator=(nullptr_t)
			{
				return (void*&)functionPtr;
			}
			bool operator==(const Delegate& _other)
			{
				return GetAddress() == _other.GetAddress();
			}
			bool operator!=(const Delegate& _other)
			{
				return !this->operator==(_other);
			}
			template<typename Class>
			bool operator==(Res(Class::* _ptr)(Params...))
			{
				return GetAddress() == (void*&)_ptr;
			}
			template<typename Class>
			bool operator!=(Res(Class::* _ptr)(Params...))
			{
				return !this->operator==(_ptr);
			}
#pragma endregion

		};
	}
}