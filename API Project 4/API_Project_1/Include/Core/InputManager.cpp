#include "InputManager.h"

InputManager::InputManager()
{
}

InputManager::~InputManager()
{
}

bool InputManager::Init()
{
	//Ű�� ���� �������� ���� ���·� �ʱ�ȭ����
	for (int i = 0; i < KEYMAX; i++)
	{
		_keyUp.set(i, false);
		_keyDown.set(i, false);
	}


	////���̽�ƽ ����̽� ������ 0�̸�
	//if ((wNumDevs = joyGetNumDevs()) == 0) {
	//	//�������� ����ϰ� �޽��� �ڽ��� �ȳ� �� ���α׷� ����
	//	MessageBeep(MB_ICONEXCLAMATION);
	//	//MessageBox(g_hWnd, TEXT("���̽�ƽ ����̹��� �����ϴ�."), NULL,
	//	//	MB_OK | MB_ICONEXCLAMATION);
	//	//PostMessage(g_hWnd, WM_CLOSE, 0, 0L);

	//}

	////���̽�ƽ1�� ����Ǿ��°�? 
	//bDev1Attached = joyGetPos(JOYSTICKID1, &joyinfo) != JOYERR_UNPLUGGED;


	////���̽�ƽ2�� ����Ǿ��°�? 
	//bDev2Attached = wNumDevs == 2 && joyGetPos(JOYSTICKID2,&joyinfo) != JOYERR_UNPLUGGED;

	//���̽�ƽ1, 2���ϳ��� ����Ǿ��ٸ� 
	//if(bDev1Attached || bDev2Attached) // decide which joystick to use ����̽�ƽ�� ����������� 
	//	wDeviceID = bDev1Attached ? JOYSTICKID1 : JOYSTICKID2; 
	//else {
	//	MessageBeep(MB_ICONEXCLAMATION);
	//	MessageBeep(MB_ICONEXCLAMATION);
	//	//MessageBox(g_hWnd, TEXT("����� ���̽�ƽ�� �����ϴ�."), NULL,
	//	//	MB_OK | MB_ICONEXCLAMATION);
	//	//PostMessage(g_hWnd, WM_CLOSE, 0, 0L);
	//}




	return true;
}



void InputManager::Release()
{
}

bool InputManager::isOnceKeyDown(int key)
{
	//GetAsyncKeyState���� Ű�� ���¸� �˾ƿ��� �༮
	//Ű�� ������������ ���������� ȣ��
	//0x8000 �������� �������� ���� ȣ��������� ��������
	if (GetAsyncKeyState(key) & 0x8000)
	{
		if (!_keyDown[key])
		{
			_keyDown.set(key, true);
			return true;
		}
	}
	else
	{
		_keyDown.set(key, false);
	}
	return false;
}

bool InputManager::isOnceKeyUp(int key)
{
	if (GetAsyncKeyState(key) & 0x8000)
	{
		_keyUp.set(key, true);
	}
	else
	{
		if (_keyUp[key])
		{
			_keyUp.set(key, false);
			return true;
		}
	}

	return false;
}

bool InputManager::isStayKeyDown(int key)
{
	if (GetAsyncKeyState(key) & 0x8000)return true;
	return false;
}

bool InputManager::isToggleKey(int key)
{
	//GetKeyState :���� Ű�� ��ۻ���
		//0x0001������ �������� �ְ� ȣ��������� �ȴ��� ����

	if (GetKeyState(key) & 0x0001)return true;
	return false;
}
