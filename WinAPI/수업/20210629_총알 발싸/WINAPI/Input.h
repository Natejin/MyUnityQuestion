#pragma once
#include"singleton.h"
#include"framework.h"
#include<bitset>
#define KEYMAX 256
class Input : public SingleTon<Input>
{
private:

	bitset<KEYMAX> _keyUp;
	bitset<KEYMAX> _keyDown;

public:
	Input();
	~Input();

	HRESULT init();
	void release();
	
	//�ѹ��� ������?
	bool isOnceKeyDown(int key);
	//�ѹ� ������ ����?
	bool isOnceKeyUp(int key);
	//������ �ֳ�?
	bool isStayKeyDown(int key);
	//���Ű�ΰ�?
	bool isToggleKey(int key);
};

