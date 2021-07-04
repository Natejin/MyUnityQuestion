#pragma once
#include"Singleton.h"
#include<bitset>

using namespace std;
#define KEYMAX 256

//���ϰ��Ӿ�ī���� ��â�񱳼��� ����
class InputManager : public Singleton<InputManager>
{
private:

	bitset<KEYMAX> _keyUp;
	bitset<KEYMAX> _keyDown;

public:
	InputManager();
	~InputManager();

	bool Init();

	void Release();

	//�ѹ��� ������
	bool isOnceKeyDown(int key);
	//�����ٰ� �³�
	bool isOnceKeyUp(int key);
	//������ �ֳ�
	bool isStayKeyDown(int key);
	//���Ű��
	bool isToggleKey(int key);
};

