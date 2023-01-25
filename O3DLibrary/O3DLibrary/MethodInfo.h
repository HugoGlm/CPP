#pragma once
#include "O3DLibrary.h"
#include "ParameterInfo.h"
#include <exception>
#include <vector>

namespace Core
{
	class Object;
#pragma warning(disable : 4251)


	class O3DLIBRARY_API BaseMethodInfo
	{
	public:
		virtual ~BaseMethodInfo() = default;
	};

	template<typename Result, typename... Params>
	class O3DLIBRARY_API MethodInfo : public BaseMethodInfo
	{
#pragma region f/p
	private:
		std::vector<Parameterinfo> params = std::vector<Parameterinfo>();
		typedef Result(Object::* Function)(Params...);
		Function functionPtr = nullptr;
		Object* instance = nullptr;
#pragma endregion
#pragma region constructor
	public:
		MethodInfo() = default;
		template<typename Class>
		MethodInfo(Class* _instance, Result(Class::* ptr)(Params...), std::vector<Parameterinfo> _params = {})
		{
			instance = _instance;
			functionPtr = reinterpret_cast<Function>(ptr);
			params = _params;
		}
#pragma endregion
#pragma region methods
	public:
		std::vector<Parameterinfo> Parameters() const
		{
			return params;
		}
		Result Invoke(Params... _params)
		{
			if (functionPtr == nullptr)
				throw std::exception("function is null !");
			if (instance == nullptr)
				throw std::exception("instance is null !");
			return (instance->*functionPtr)(_params...);
		}
		void* GetAdress()
		{
			return (void*&)functionPtr;
		}
#pragma endregion

	};
}