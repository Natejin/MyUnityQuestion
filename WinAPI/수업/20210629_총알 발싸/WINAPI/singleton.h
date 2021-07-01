//#pragma once
//
////======================================
////				SingleTon
////======================================
//
///*
//�̱��� ������ static member�� �ϳ��� �ν��Ͻ���
//�����ȴ�. ���α׷� �ȿ��� ������ ������ �����ϴ�.
//�������� �����ص� �ϳ��� �ν��Ͻ��� ������ �� �ֱ�������,
//�̱��������� ����ϸ� Ŭ���� �ڽ��� �ڱ��� ������ �ν��Ͻ���
//�����ϴ� ����� ĸ��ȭ �Ͽ� ������ �� �ִ�.
//�׸��� ���, ��ü����, �Ҹ�, �ν��Ͻ� ���� ���� ���..
//Ȱ�뿡 �����ϴ�.
//
//�ڱ� �����ΰ� ������ �ν��Ͻ��� �����ϴ� ����� ��ü������ �����ϴ°� ����.
//�ٸ� �ν��Ͻ��� �������� �ʵ��� ó���� �� �ְ� ���� ��� ���� ������ �� �� �ִ�.
//*/
//
//
//template<typename T>
//class Singleton
//{
//protected:
//	//�̱��� �ν��Ͻ� ����
//	static T* singleton;
//
//	Singleton() {};
//	virtual ~Singleton() {};
//
//public:
//	static T* GetSingleTon();
//	void releaseSingleTon();
//
//};
////�̱��� �ν��Ͻ� ����
//template<typename T>
//T* Singleton<T>::singleton = nullptr;
//
//
////�̱��� ��ü�� ��������
//template<typename T>
//T* Singleton<T>::GetSingleTon()
//{
//	//�̱��� ��ü�� ������ ���� ������
//	if (!singleton) singleton = new T;
//	return singleton;
//}
//
//template<typename T>
//void Singleton<T>::releaseSingleTon()
//{
//	if (singleton)
//	{
//		delete singleton;
//		singleton = nullptr;
//	}
//}


#include <Windows.h>
#pragma once

template<typename T>
class Singleton {
protected:
	static T* instance;
	Singleton() {};
	~Singleton() {};

public:
	static T* GetSingleton();
	void ReleaseSingleton();
};

template<typename T>
T* Singleton<T>::instance = NULL;

template<typename T>
T* Singleton<T>::GetSingleton() {
	if (!instance) instance = new T;
	return instance;
}

template<typename T>
void Singleton<T>::ReleaseSingleton() {
	if (instance) {
		delete instance;
		instance = 0;
	}
}