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
	/*m_body = RectMakeCenter(WINSIZEX / 2, WINSIZEY - 100, 50, 100);
	m_bullet = RectMakeCenter(m_body.left + (m_body.right - m_body.left) / 2, m_body.top - 15, 30, 30);*/


	m_player1 = RectMakeCenter(WINSIZEX / 2 - 400, WINSIZEY / 2, 100, 50);
	m_player2 = RectMakeCenter(WINSIZEX / 2 + 400, WINSIZEY / 2, 100, 50);

	m_gaugeFront = RectMakeCenter(WINSIZEX / 2 + 300, 100, 400, 50);
	m_gaugeBack = RectMakeCenter(WINSIZEX / 2 + 300, 100, 400, 50);

	m_red = 0;
	m_green = 255;

	for (size_t i = 0; i < BULLETMAX; i++)
	{
		bullet[i].speed = 5.0f;
		bullet[i].isFire = false;

	}

	return S_OK;
}

void mainGame::release()
{
	gameNode::release();
}

void mainGame::update()
{

	gameNode::update();

	/*if (InputManager->isStayKeyDown(VK_RIGHT))OffsetRect(&m_body, 5, 0);
	if (InputManager->isStayKeyDown(VK_LEFT))OffsetRect(&m_body, -5, 0);
	if (InputManager->isOnceKeyDown(VK_SPACE))isFire = true;

	if (!isFire)
	{
		m_bullet = RectMakeCenter(m_body.left + (m_body.right - m_body.left) / 2, m_body.top - 15, 30, 30);
	}
	else
	{
		OffsetRect(&m_bullet, 0, -5);

		if (m_bullet.bottom < 0)
		{
			isFire = false;
		}

	}*/


	bulletMove();
	playerKeyControl();
	collision();
}

void mainGame::render(HDC hdc)
{
	/*Rectangle(hdc, m_body.left, m_body.top, m_body.right, m_body.bottom);
	
	if (isFire)
	{
		Ellipse(hdc, m_bullet.left, m_bullet.top, m_bullet.right, m_bullet.bottom);
	}*/

	Rectangle(hdc, m_player1.left, m_player1.top, m_player1.right, m_player1.bottom);
	Rectangle(hdc, m_player2.left, m_player2.top, m_player2.right, m_player2.bottom);
	Rectangle(hdc, m_gaugeBack.left, m_gaugeBack.top, m_gaugeBack.right, m_gaugeBack.bottom);

	HBRUSH brush = CreateSolidBrush(RGB(m_red, m_green, 0));
	Rectangle(hdc, m_gaugeFront.left, m_gaugeFront.top, m_gaugeFront.right, m_gaugeFront.bottom);
	FillRect(hdc, &m_gaugeFront, brush);
	DeleteObject(brush);
	gaugeDraw();


	for (size_t i = 0; i < BULLETMAX; i++)
	{

		if (!bullet[i].isFire)continue;
		Ellipse(hdc, bullet[i].rc.left, bullet[i].rc.top, bullet[i].rc.right, bullet[i].rc.bottom);
	}

}


void mainGame::bulletFire()
{
	for (size_t i = 0; i < BULLETMAX; i++)
	{
		//발사된 총알은 영향을 주지말자
		if (bullet[i].isFire)continue;

		bullet[i].isFire = true;
		bullet[i].rc = RectMakeCenter(m_player1.right + 15,
			m_player1.top + (m_player1.bottom - m_player1.top) / 2, 20, 20);
		break;

	}
}

void mainGame::bulletMove()
{
	for (size_t i = 0; i < BULLETMAX; i++)
	{
		//발사된 총알은 영향을 주지말자
		if (!bullet[i].isFire)continue;

		OffsetRect(&bullet[i].rc, bullet[i].speed, 0);

	}
}

void mainGame::gaugeDraw()
{
	if (m_gaugeFront.right - m_gaugeFront.left<=200)
	{
		m_red = 200;
	}
	if (m_gaugeFront.right - m_gaugeFront.left <= 80)
	{
		m_red = 255;
		m_green = 0;
	}
}

void mainGame::collision()
{
	for (size_t i = 0; i < BULLETMAX; i++)
	{
		RECT temp;
		if (IntersectRect(&temp, &bullet[i].rc, &m_player2))
		{
			bullet[i].isFire = false;
			bullet[i].rc = RectMakeCenter(m_player1.right + 15,
				m_player1.top + (m_player1.bottom - m_player1.top) / 2, 20, 20);
			m_gaugeFront.left += 20;

			if (m_gaugeFront.left >= m_gaugeFront.right)
			{
				m_gaugeFront.left = m_gaugeBack.right;
			}
		}
	}
}

void mainGame::playerKeyControl()
{
	if (InputManager->isStayKeyDown('W'))
	{
		OffsetRect(&m_player1, 0, -5);
	}
	if (InputManager->isStayKeyDown('S'))
	{
		OffsetRect(&m_player1, 0, 5);
	}
	if (InputManager->isOnceKeyDown(VK_SPACE))
	{
		bulletFire();
	}
}

