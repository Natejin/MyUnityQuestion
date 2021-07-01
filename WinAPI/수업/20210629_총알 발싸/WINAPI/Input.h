#pragma once
#include"singleton.h"
#include"framework.h"
#include<bitset>
#define KEYMAX 256
class InputManager : public Singleton<InputManager>
{
private:

	bitset<KEYMAX> _keyUp;
	bitset<KEYMAX> _keyDown;

public:
	InputManager();
	~InputManager();

	HRESULT Init();
	void Release();
	
	//�ѹ��� ������?
	bool isOnceKeyDown(int key);
	//�ѹ� ������ ����?
	bool isOnceKeyUp(int key);
	//������ �ֳ�?
	bool isStayKeyDown(int key);
	//���Ű�ΰ�?
	bool isToggleKey(int key);
};

