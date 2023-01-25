#pragma once
#include "../Object/Object.h"
#include <string>

template<typename Res, typename... Args>
class Delegate : public Object
{
private:
	typedef Res(Object::* Function)(Args...);
	Function function = nullptr;
public:
	Delegate() = default;
	Delegate(nullptr_t);
	template<typename Class>
	Delegate(Res(Class::* ptr)(Args...));
	~Delegate() override;
public:
	Res Invoke(object _instance, Args... _args);
	void* GetAdress();
public:
	void operator=(nullptr_t);
	template<typename Class>
	void operator=(Res(Class::* ptr)(Args...));
};

template<typename Res, typename ...Args>
Delegate<Res, Args...>::Delegate(nullptr_t)
{
	function = nullptr;
}
template<typename Res, typename ...Args>
template<typename Class>
Delegate<Res, Args...>::Delegate(Res(Class::* ptr)(Args...))
{
	function = reinterpret_cast<Function>(ptr);
}
template<typename Res, typename ...Args>
Delegate<Res, Args...>::~Delegate()
{
	function = nullptr;
}
template<typename Res, typename ...Args>
Res Delegate<Res, Args...>::Invoke(object _instance, Args ..._args)
{
	return (_intance->*function)(_args...);
}
template<typename Res, typename ...Args>
void* Delegate<Res, Args...>::GetAdress()
{
	return (void*&)function;
}
template<typename Res, typename ...Args>
void Delegate<Res, Args...>::operator=(nullptr_t)
{
	function = nullptr;
}
template<typename Res, typename ...Args>
template<typename Class>
void Delegate<Res, Args...>::operator=(Res(Class::* ptr)(Args...))
{
	function = reinterpret_cast<Function>(ptr);
}
