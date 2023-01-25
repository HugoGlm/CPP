#pragma once
#include <cstddef>

class Object;

template<typename Out, typename T1, typename T2>
class Func
{
#pragma region typedef
private:
	typedef Out(Object::* Function)(T1, T2);
	Function function = nullptr;
#pragma endregion
#pragma region constructor
public:
	Func(nullptr_t);
	template<typename Class>
	Func(Out(Class::* ptr)(T1, T2));
	~Func();
#pragma endregion
#pragma region methods
public:
	Out Invoke(Object* _instence, T1 _a, T2 _b);
#pragma endregion
#pragma region operator
public:
	void operator=(nullptr_t);
	template<typename Class>
	void operator=(Out(Class::* _ptr)(T1, T2));
#pragma endregion
};

#pragma region constructor
template<typename Out, typename T1, typename T2>
Func<Out, T1, T2>::Func(nullptr_t)
{
	function = nullptr;
}
template<typename Out, typename T1, typename T2>
Func<Out, T1, T2>::~Func()
{
	function = nullptr;
}
template<typename Out, typename T1, typename T2>
template<typename Class>
Func<Out, T1, T2>::Func(Out(Class::* ptr)(T1, T2))
{
	function = reinterpret_cast<Function>(ptr);
}
#pragma endregion
#pragma region methods
template<typename Out, typename T1, typename T2>
Out Func<Out, T1, T2>::Invoke(Object* _instence, T1 _a, T2 _b)
{
	return (_instence->*function) (_a, _b);
}
#pragma endregion
#pragma region operator
template<typename Out, typename T1, typename T2>
template<typename Class>
void Func<Out, T1, T2>::operator=(Out(Class::* _ptr)(T1, T2))
{
	function = reinterpret_cast<Function>(_ptr);
}
template<typename Out, typename T1, typename T2>
void Func<Out, T1, T2>::operator=(nullptr_t)
{
	function = nullptr;
}
#pragma endregion

