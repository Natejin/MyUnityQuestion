#pragma once

//======================================
//				SingleTon
//======================================

/*
�̱��� ������ static member�� �ϳ��� �ν��Ͻ���
�����ȴ�. ���α׷� �ȿ��� ������ ������ �����ϴ�.
�������� �����ص� �ϳ��� �ν��Ͻ��� ������ �� �ֱ�������,
�̱��������� ����ϸ� Ŭ���� �ڽ��� �ڱ��� ������ �ν��Ͻ���
�����ϴ� ����� ĸ��ȭ �Ͽ� ������ �� �ִ�.
�׸��� ���, ��ü����, �Ҹ�, �ν��Ͻ� ���� ���� ���..
Ȱ�뿡 �����ϴ�.

�ڱ� �����ΰ� ������ �ν��Ͻ��� �����ϴ� ����� ��ü������ �����ϴ°� ����.
�ٸ� �ν��Ͻ��� �������� �ʵ��� ó���� �� �ְ� ���� ��� ���� ������ �� �� �ִ�.
*/


template<typename T>
class SingleTon
{
protected:
	//�̱��� �ν��Ͻ� ����
	static T* singleton;

	SingleTon() {};
	~SingleTon() {};

public:
	static T* GetSingleTon();
	void releaseSingleTon();

};
//�̱��� �ν��Ͻ� ����
template<typename T>
T* SingleTon<T>::singleton = nullptr;


//�̱��� ��ü�� ��������
template<typename T>
T* SingleTon<T>::GetSingleTon()
{
	//�̱��� ��ü�� ������ ���� ������
	if (!singleton) singleton = new T;
	return singleton;
}

template<typename T>
void SingleTon<T>::releaseSingleTon()
{
	if (singleton)
	{
		delete singleton;
		singleton = nullptr;
	}
}
