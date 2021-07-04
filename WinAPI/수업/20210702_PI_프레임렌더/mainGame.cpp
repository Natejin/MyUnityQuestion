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
	
	_bgImage = new Sprite;
	_bgImage->init("images/�̿�����.bmp", WINSIZEX, WINSIZEY);
	_rockman = new Sprite;
	_rockman->init("images/�ϸ�.bmp", WINSIZEX / 2, WINSIZEY / 2, 960, 200, 10, 2, true, RGB(255, 0, 255));


	return S_OK;
}

void mainGame::release()
{
	gameNode::release();

}

void mainGame::update()
{

	gameNode::update();

	if (InputManager->isStayKeyDown(VK_LEFT))
	{
		isLeft = true;
		_rockman->SetX(_rockman->GetX() - 2.0f);
	}
	if (InputManager->isStayKeyDown(VK_RIGHT))
	{
		isLeft = false;
		_rockman->SetX(_rockman->GetX() + 2.0f);
	}
	if (isLeft)
	{
		m_count++;
		_rockman->SetFrameY(1);

		if (m_count % 5 == 0)
		{
			m_count = 0;
			m_index--;
			if (m_index < _rockman->GetMaxFrameY())
			{
				m_index = 9;
			}
			_rockman->SetFrameX(m_index);
		}
	}
	else {
		m_count++;
		_rockman->SetFrameY(0);

		if (m_count % 5 == 0)
		{
			m_count = 0;
			m_index++;
			if (m_index >= _rockman->GetMaxFrameX())
			{
				m_index = 0;
			}
			_rockman->SetFrameX(m_index);
		}
	}
}

void mainGame::render(HDC hdc)
{
	//����� �Ѹ���.
	HDC memDC = this->getBackBuffer()->GetMemDC();
	PatBlt(memDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//==============================================
	_bgImage->Render(memDC);
	
	_rockman->FrameRender(memDC, _rockman->GetX(), _rockman->GetY(), _rockman->GetFrameX(), _rockman->GetFrameY());
	//==============================================

	//������� ������ HDC�׸���.(�ǵ帮�� ����.)
	this->getBackBuffer()->Render(hdc, 0, 0);


}

