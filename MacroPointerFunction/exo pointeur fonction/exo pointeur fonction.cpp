#include <iostream>
#include <format>
#include "Object.h"
#include "IGame.h"

#define USER "Hugo"
#define nameof(x) #x
#define Add(a, b) a + b
#define PURE_VIRTUAL() = 0;
#define null nullptr;
#define in :

void Display(Object* _o)
{
	std::cout << std::format("is Interface: {}\n", _o->IsInterface());
	std::cout << std::format("is Class: {}\n", _o->IsClass());
	std::cout << std::format("is Abstract: {}\n", _o->IsAbstract());
	std::cout << "\n\n";
}

//class A : public Object
//{
//public:
//	void Test(float _a)
//	{
//		std::cout << _a << std::endl;
//	}
//	void Hello(float _b)
//	{
//		std::cout << "hello: " << _b << std::endl;
//	}
//	void HelloKitty(const std::string&, float)
//	{
//
//	}
//	int Add(const int _a, const int _b)
//	{
//		return _a + _b;
//	}
//};

int main()
{
	IGame* game = new IGame();
	game->Test();
	game->GetParentClass()->Test();

	/*Object o;
	o.SetBitMask(Interface);
	Display(o);
	o.SetBitMask(Abstract);
	Display(o);*/

	/*int a = 0;
	std::cout << nameof(a) << std::endl;;
	std::cout << Add(5, 10) << std::endl;;*/

	/*Action<float> onTest = &A::Test;
	A* _a = new A();
	onTest.Invoke(_a, 5);
	onTest -= &A::Test;
	onTest.Invoke(_a, 5);
	onTest += &A::Hello;
	onTest.Invoke(_a, 5);
	delete _a;*/

	/*Func<int, int, int> OnAdd = &A::Add;
	A* _instance = new A();
	const int _result = OnAdd.Invoke(_instance, 5, 10);
	std::cout << _result;*/

	/*A _a = A();
	Action<float> OnUpdate = &A::Test;
	Action<const std::string&, float> OnUpdate1 = &A::HelloKitty;
	OnUpdate.Invoke(&_a, 5.0f);
	OnUpdate1.Invoke(&_a, "Hello Kitty: ", 5.0f);*/

	/*A _a = A();
	Action<float> OnUpdate = &A::Test;
	try 
		OnUpdate.Invoke(&_a, 5.0f);
	catch (const Exception& _e)
		std::cout << _e.ToString();*/
}