

#pragma once

#include "Game.h"
template <typename T>
class Singleton
{
protected:
	static T* instance;
	Singleton() {};
	~Singleton() {};
public:
	static T* GetInst() {
		if (!instance)	instance = new T;
		return instance;
	}

	static void DestroyInst() {
		if (instance)
		{
			delete instance;
			instance = nullptr;
		}
		
		//SAFE_DELETE(instance);
	}
};

template <typename T>
T* Singleton<T>::instance = nullptr;
