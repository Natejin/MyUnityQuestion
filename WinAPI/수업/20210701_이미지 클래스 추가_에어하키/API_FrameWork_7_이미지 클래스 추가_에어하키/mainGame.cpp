#include"framework.h"
#include "mainGame.h"
mainGame::mainGame()
{
}
mainGame::~mainGame()
{
}
HRESULT mainGame::init()
{
	gameNode::init();
	_bgImage = new image;
	_bgImage->init("images/사나.bmp", WINSIZEX, WINSIZEY);

	_sigong = new image;
	_sigong->init("images/sigong.bmp", 40, 40, true, RGB(255, 0, 255));


	rc = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2, 40, 40);


	ah = new airHockey;
	ah->init();


	return S_OK;
}

void mainGame::release()
{
	gameNode::release();
	//SAFE_DELETE(_bgImage);
	SAFE_DELETE(ah);
}

void mainGame::update()
{

	gameNode::update();
	/*if (InputManager->isStayKeyDown(VK_LEFT))
	{
		OffsetRect(&rc, -5, 0);
	}
	if (InputManager->isStayKeyDown(VK_RIGHT))
	{
		OffsetRect(&rc, 5, 0);
	}
	if (InputManager->isStayKeyDown(VK_UP))
	{
		OffsetRect(&rc, 0, -5);
	}
	if (InputManager->isStayKeyDown(VK_DOWN))
	{
		OffsetRect(&rc, 0, 5);
	}*/
	ah->update();
}

void mainGame::render(HDC hdc)
{
	//백버퍼 뿌리자.

	HDC memDC = this->getBackBuffer()->getMemDC();
	PatBlt(memDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//==============================================

	_bgImage->render(memDC);

	_sigong->render(memDC, rc.left, rc.top);
	ah->render(memDC);


	//==============================================

	//백버퍼의 내용을 HDC그린다.(건드리지 말것.)
	this->getBackBuffer()->render(hdc, 0, 0);


}

