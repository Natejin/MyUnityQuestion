#pragma once
#include "Game.h"


template <typename T>
class Singleton
{
protected:
	static T* pInstance;
	Singleton() {};
	virtual ~Singleton() { DestroyInst(); };
public:
	static T* GetInst() {
		if (!pInstance)	pInstance = new T;
		return pInstance;
	}

	static void DestroyInst() {
		if (pInstance != nullptr)
		{
			delete pInstance;
			pInstance = nullptr;
		}
	}
};

template <typename T>
T* Singleton<T>::pInstance = nullptr;
