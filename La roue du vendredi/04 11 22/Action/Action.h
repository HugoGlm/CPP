#pragma once
#include <vector>

class Object;

template<typename... Args>
class Action
{
#pragma region f/p
private:
	typedef void (Object::* Function)(Args...);
	std::vector<Function*> functions = std::vector<Function*>();
#pragma endregion
#pragma region constructor
public:
	Action(nullptr_t);
	template<typename Class>
	Action(Function* _func);
	~Action();
#pragma endregion
#pragma region methods
public:
	void Invoke(Object* _instance, Args... _value);
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
template<typename ...Args>
Action<Args...>::Action(nullptr_t)
{
}
template<typename ...Args>
template<typename Class>
Action<Args...>::Action(Function* _func)
{

}
template<typename ...Args>
Action<Args...>::~Action()
{
}
#pragma endregion
#pragma region methods
template<typename ...Args>
void Action<Args...>::Invoke(Object* _instance, Args ..._value)
{
}
#pragma endregion
#pragma region operator
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

}
template<typename... Args>
template<typename Class>
void Action<Args...>::operator=(void(Class::* _ptr)(Args...))
{
	
}
template<typename ...Args>
void Action<Args...>::operator=(nullptr_t)
{
}

#pragma endregion
