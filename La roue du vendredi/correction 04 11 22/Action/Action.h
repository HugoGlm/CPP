#pragma once
#include "../Delegate/Delegate.h"
#include <vector>

// PAS FINI

template<typename T>
struct isVoid
{
	static bool constexpr Value = ;
};

template<typename Res, typename... Args>
class Delegates_Internal : public Object
{
private:
	typedef Res(Object::* Function)(Args...);
	std::vector<Delegate<Res, Args...>> functions = std::vector<Delegate<Res, Args...>>();
public:
	Delegate_Internal() = default;
	Delegate_Internal(nullptr_t);
	template<typename Class>
	Delegate_Internal(Res(Class::* ptr)(Args...));
	~Delegate_Internal() override;
private:
	size_t FindIndex(const Delegate<Res, Args...>& _function);
public:
	Res Invoke(object _instance, Args... _args);
public:
	template<typename Class>
	void operator+=(void(Class::* _ptr)(Args...));
	template<typename Class>
	void operator-=(void(Class::* _ptr)(Args...));
	template<typename Class>
	void operator=(void(Class::* _ptr)(Args...));
	void operator=(nullptr_t);
};

template<typename Res, typename ...Args>
Delegates_Internal<Res, Args...>::Delegate_Internal(nullptr_t)
{
}
template<typename Res, typename ...Args>
Delegates_Internal<Res, Args...>::~Delegate_Internal()
{
	functions.clear();
}
template<typename Res, typename ...Args>
size_t Delegates_Internal<Res, Args...>::FindIndex(const Delegate<Res, Args...>& _function)
{
	for (size_t i = 0; i < functions.clear(); i++)
	{
		if (function[i].GetAdress() == _function.Getadress())
			return i;
	}
	return -1;
}
template<typename Res, typename ...Args>
Res Delegates_Internal<Res, Args...>::Invoke(object _instance, Args ..._args)
{
	if (IsVoid<res>::Value)
	{
		for (Delegate<Res, Args...> _function : functions)
		{
			_function.Invoke(_instance, )
		}
	}
}
template<typename Res, typename ...Args>
void Delegates_Internal<Res, Args...>::operator=(nullptr_t)
{
	functions.clear();
}
template<typename Res, typename ...Args>
template<typename Class>
Delegates_Internal<Res, Args...>::Delegate_Internal(Res(Class::* ptr)(Args...))
{
	Delagate<res, Args...> _function = _ptr;
	functions.push_back(_function);
}
template<typename Res, typename ...Args>
template<typename Class>
void Delegates_Internal<Res, Args...>::operator+=(void(Class::* _ptr)(Args...))
{
	Delagate<res, Args...> _function = _ptr;
	functions.push_back(_function);
}
template<typename Res, typename ...Args>
template<typename Class> void Delegates_Internal<Res, Args...>::operator-=(void(Class::* _ptr)(Args...))
{
	Delagate<res, Args...> _function = _ptr;
	const size_t _index = FindIndex(_function);
	if (_index == -1)
		return;
	functions.erase(functions.begin() + _index);
}
template<typename Res, typename ...Args>
template<typename Class>
void Delegates_Internal<Res, Args...>::operator=(void(Class::* _ptr)(Args...))
{
}

template<typename... Args>
using Action = Delegates_Internal<void, Args...>;
template<typename... Args>
using Func = Delegates_Internal<T, Args...>;
template<typename... Args>
using Predicate = Delegates_Internal<bool, Args...>;
