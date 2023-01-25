#pragma once
#include <vector>
#include "Exception.h"

class Object;

template<typename... Args>
class Action
{
#pragma region f/p
private:
	typedef void(Object::* Function)(Args...);
	std::vector<Function> functions = std::vector<Function>();
#pragma endregion
#pragma region constructor
public:
	Action(nullptr_t);
	template<typename Class>
	Action(void(Class::* ptr)(Args...));
	~Action();
#pragma endregion
#pragma region methods
public:
	void Invoke(Object* _instence, Args... _value);
#pragma endregion
#pragma region operator
public:
	template<typename Class>
	void operator+=(void(Class::* _ptr)(Args...));
	template<typename Class>
	void operator-=(void(Class::* _ptr)(Args...));
	template<typename Class>
	void operator=(void(Class::* _ptr)(Args...));
	void operator=(nullptr_t);
#pragma endregion
};

#pragma region constructor
template<typename... Args>
Action<Args...>::Action(nullptr_t)
{
	functions.clear();
}
template<typename... Args>
template<typename Class>
Action<Args...>::Action(void(Class::* _ptr)(Args...))
{
	functions.push_back(reinterpret_cast<Function>(_ptr));
}
template<typename... Args>
Action<Args...>::~Action()
{
}
#pragma endregion
#pragma region methods
template<typename... Args>
template<typename Class>
void Action<Args...>::operator+=(void(Class::* _ptr)(Args...))
{
	functions.push_back(reinterpret_cast<Function>(_ptr));
}
template<typename... Args>
template<typename Class>
void Action<Args...>::operator-=(void(Class::* _ptr)(Args...))
{
	Function _function = reinterpret_cast<Function>(_ptr);
	for (size_t i = 0; i < functions.size(); i++)
	{
		if (functions[i] == _function)
		{
			functions.erase(functions.begin() + i);
			return;
		}
	}
}
template<typename... Args>
template<typename Class>
void Action<Args...>::operator=(void(Class::* _ptr)(Args...))
{
	functions.clear();
	functions.push_back(reinterpret_cast<Function>(_ptr));
}
template<typename... Args>
void Action<Args...>::operator=(nullptr_t)
{
	functions.clear();
}
template<typename... Args>
void Action<Args...>::Invoke(Object* _instance, Args... _value)
{
	throw Exception("invalid invoke");
	for (size_t i = 0; i < functions.size(); i++)
	{
		(_instance->*functions[i]) (_value...);
	}
}
#pragma endregion