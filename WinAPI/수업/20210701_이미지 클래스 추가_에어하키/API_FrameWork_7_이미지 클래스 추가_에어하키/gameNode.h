#pragma once
#include"image.h"
class gameNode
{

private:

	image* _backBuffer;	//백버퍼
	void setBackBuffer();//백버퍼 셋팅



public:
	gameNode();
	virtual~gameNode();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);


	image* getBackBuffer()const { return _backBuffer; }
	LRESULT MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);

};

