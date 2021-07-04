#pragma once
#include "Game.h"


//=======================================
//singletonBase(이녀석으로 Singleton을 만든다.)
//=======================================
/*
	Singleton 패턴은 static member로 하나의 인스턴스만
	생성된다. 프로그램 안에서 전역적으로 접근이 가능하다.

	전역변수를 선언해도 하나의 인스턴스를 유지할수 있긴 하지만
	Singleton패턴을 사용하면 클래스 자신이 자기의 유일한 인스턴스로
	접근하는 방법을 캡슐화 하여 관리 할수 있다.
	또한 상속, 객체생성 및 소멸, 인스턴스 개수 제어 등등등..
	활용에 유리하다.

	자기 스스로가 자기의 유일한 인스턴스로 접근하는
	방법을 자체적으로 관리하는 것이 좋다.
	이녀석은 다른 인스턴스가 생성되지 않도록 처리할수 있고
	접근 방법 또한 제한을 둘수 있다.
*/
template <class T>
class Singleton
{
protected:
	static T* pInstance;
	Singleton() {};
	virtual ~Singleton() {};
public:
	static T* GetSingleton();
	static void ReleaseSingleton();
};

template <class T>
T* Singleton<T>::pInstance = nullptr;


//Singleton 객체를 가져오자
template<class T>
T* Singleton<T>::GetSingleton()
{
	//Singleton 객체가 없으면 새로 만들자ㅏ.
	if (!pInstance)	pInstance = new T;
	return pInstance;
}

//Singleton 있으면 해제
template<class T>
void Singleton<T>::ReleaseSingleton()
{
	//Singleton 있으면 해제
	//SAFE_DELETE(pInstance);
	if (pInstance)
	{
		delete pInstance;
		pInstance = nullptr;
	}
}