#include "Input.h"

InputManager::InputManager(){}

InputManager::~InputManager(){}

HRESULT InputManager::Init()
{
	//키가 전부 눌려있지 않은 상태로 초기화
	for (int i = 0; i < KEYMAX; i++)
	{
		_keyUp.set(i, false);
		_keyDown.set(i, false);
	}

	return S_OK;
}

void InputManager::Release()
{
}

bool InputManager::isOnceKeyDown(int key)
{
	//GetAsyncKeyState : 현재 키의 상태를 알아온다.
	//키가 눌렸을때나 떨어졌을때 호출
	//0x8000 : 이전에는 누른적이 없고 호출 시점에서 눌린 상태
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
	if (GetKeyState(key) & 0x0001)return true;
	return false;
}
