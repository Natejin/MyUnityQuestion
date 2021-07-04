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