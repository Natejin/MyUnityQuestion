#pragma once
#include"Singleton.h"
#include<bitset>

using namespace std;
#define KEYMAX 256

//경일게임아카데미 이창희교수님 버전
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

	//한번만 눌렀냐
	bool isOnceKeyDown(int key);
	//눌렀다가 뗏냐
	bool isOnceKeyUp(int key);
	//누르고 있냐
	bool isStayKeyDown(int key);
	//토글키냐
	bool isToggleKey(int key);
};

