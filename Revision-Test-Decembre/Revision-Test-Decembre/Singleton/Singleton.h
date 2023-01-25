#pragma once
#include "../Object/Object.h"

template<typename T>
class Singleton : public Object
{
#pragma region f/p
private:
	static inline T* instance = nullptr;
#pragma endregion
#pragma region constructor
public:
	Singleton() = default;
	Singleton() override
	{
		onDestroy();
	}
#pragma endregion
#pragma region methods
public:
	virtual void OnDestroy() { }
	static T* Instance()
	{
		if (instance == nullptr)
			instance = new T();
		return instance;
	}
#pragma endregion

};
