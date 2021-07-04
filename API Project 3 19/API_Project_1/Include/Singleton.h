#pragma once
#include "Game.h"


//=======================================
//singletonBase(�̳༮���� Singleton�� �����.)
//=======================================
/*
	Singleton ������ static member�� �ϳ��� �ν��Ͻ���
	�����ȴ�. ���α׷� �ȿ��� ���������� ������ �����ϴ�.

	���������� �����ص� �ϳ��� �ν��Ͻ��� �����Ҽ� �ֱ� ������
	Singleton������ ����ϸ� Ŭ���� �ڽ��� �ڱ��� ������ �ν��Ͻ���
	�����ϴ� ����� ĸ��ȭ �Ͽ� ���� �Ҽ� �ִ�.
	���� ���, ��ü���� �� �Ҹ�, �ν��Ͻ� ���� ���� ����..
	Ȱ�뿡 �����ϴ�.

	�ڱ� �����ΰ� �ڱ��� ������ �ν��Ͻ��� �����ϴ�
	����� ��ü������ �����ϴ� ���� ����.
	�̳༮�� �ٸ� �ν��Ͻ��� �������� �ʵ��� ó���Ҽ� �ְ�
	���� ��� ���� ������ �Ѽ� �ִ�.
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


//Singleton ��ü�� ��������
template<class T>
T* Singleton<T>::GetSingleton()
{
	//Singleton ��ü�� ������ ���� �����ڤ�.
	if (!pInstance)	pInstance = new T;
	return pInstance;
}

//Singleton ������ ����
template<class T>
void Singleton<T>::ReleaseSingleton()
{
	//Singleton ������ ����
	//SAFE_DELETE(pInstance);
	if (pInstance)
	{
		delete pInstance;
		pInstance = nullptr;
	}
}