#pragma once

template<typename T>
class Singleton
{
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
	}
#pragma endregion
#pragma region methods
public:
	virtual void OnDestroy() {}
	static T* Instance()
	{
		if (instance == nullptr)
			instance = new T();
		return instance;
	}
#pragma endregion
};