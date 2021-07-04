#include "InputManager.h"

InputManager::InputManager()
{
}

InputManager::~InputManager()
{
}

bool InputManager::Init()
{
	//키가 전부 눌려있지 않은 상태로 초기화하자
	for (int i = 0; i < KEYMAX; i++)
	{
		_keyUp.set(i, false);
		_keyDown.set(i, false);
	}


	////조이스틱 디바이스 개수가 0이면
	//if ((wNumDevs = joyGetNumDevs()) == 0) {
	//	//비프음을 출력하고 메시지 박스로 안내 후 프로그램 종료
	//	MessageBeep(MB_ICONEXCLAMATION);
	//	//MessageBox(g_hWnd, TEXT("조이스틱 드라이버가 없습니다."), NULL,
	//	//	MB_OK | MB_ICONEXCLAMATION);
	//	//PostMessage(g_hWnd, WM_CLOSE, 0, 0L);

	//}

	////조이스틱1이 연결되었는가? 
	//bDev1Attached = joyGetPos(JOYSTICKID1, &joyinfo) != JOYERR_UNPLUGGED;


	////조이스틱2가 연결되었는가? 
	//bDev2Attached = wNumDevs == 2 && joyGetPos(JOYSTICKID2,&joyinfo) != JOYERR_UNPLUGGED;

	//조이스틱1, 2중하나라도 연결되었다면 
	//if(bDev1Attached || bDev2Attached) // decide which joystick to use 어떤조이스틱을 사용할지결정 
	//	wDeviceID = bDev1Attached ? JOYSTICKID1 : JOYSTICKID2; 
	//else {
	//	MessageBeep(MB_ICONEXCLAMATION);
	//	MessageBeep(MB_ICONEXCLAMATION);
	//	//MessageBox(g_hWnd, TEXT("연결된 조이스틱이 없습니다."), NULL,
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
	//GetAsyncKeyState현재 키의 상태를 알아오는 녀석
	//키가 눌려졌을때나 떨어졌을때 호출
	//0x8000 이전에는 누른적이 없고 호출시점에서 눌린상태
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
	//GetKeyState :현재 키의 토글상태
		//0x0001이전에 누른적이 있고 호출시점에서 안눌린 상태

	if (GetKeyState(key) & 0x0001)return true;
	return false;
}
