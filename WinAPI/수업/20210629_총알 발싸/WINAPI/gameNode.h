#pragma once
#include"framework.h"

class gameNode
{
public:
	gameNode();
	virtual ~gameNode();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);

	LRESULT MainProc(HWND hWnd, UINT imessage, WPARAM wParam, LPARAM lParam);
};

