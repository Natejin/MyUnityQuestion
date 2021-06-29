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
	
	//한번만 눌렀나?
	bool isOnceKeyDown(int key);
	//한번 누르고 땠나?
	bool isOnceKeyUp(int key);
	//누르고 있나?
	bool isStayKeyDown(int key);
	//토글키인가?
	bool isToggleKey(int key);
};

