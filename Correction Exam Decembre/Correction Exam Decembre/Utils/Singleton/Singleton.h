#pragma once
#include "../../Object/Object.h"

template<typename T>
class Singleton : public Object
{
	DECLARE_CLASS_INFO(Object)
#pragma region f/p
private:
	static inline T* instance = nullptr;
#pragma endregion
#pragma region constructor
public:
	Singleton() = default;
	~Singleton()
	{
		OnDestroy();
		delete instance;
		instance = nullptr;
	}
#pragma endregion
#pragma region methods
protected:
	virtual void OnDestroy(){	}
public:
	static T* Instance()
	{
		if (instance == nullptr)
			instance = new T();
		return instance;
	}
#pragma endregion

};