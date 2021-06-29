#include "GameManager_Bullet.h"

GameManager_Bullet::GameManager_Bullet()
{
}

GameManager_Bullet::~GameManager_Bullet()
{
}

HRESULT GameManager_Bullet::init()
{
	/*m_body = RectMakeCenter(WINSIZEX / 2, WINSIZEY - 100, 50, 100);
		m_bullet = RectMakeCenter(m_body.left + (m_body.right - m_body.left) / 2, m_body.top - 15, 30, 30);*/


	//m_player1 = RectMakeCenter(WINSIZEX / 2 - 400, WINSIZEY / 2, 100, 50);
	//m_player2 = RectMakeCenter(WINSIZEX / 2 + 400, WINSIZEY / 2, 100, 50);



	m_red = 0;
	m_green = 255;

	//for (size_t i = 0; i < BULLETMAX; i++)
	//{
	//	bullet[i].speed = 5.0f;
	//	bullet[i].isFire = false;
	//}
	//플레이어 생성

	player = BulletPlayer(100,WINSIZEY/2, 40, 20, 5, 5);
	enemy = BulletEnemy(800,WINSIZEY/2, 40, 20, 0, 5);
	UI.init();
	//총알 생성
	//for (size_t i = 0; i < 5; i++)
	//{
	//	bullets.push_back(Bullet(100,100+i*50, 5, 5, 10, 5));
	//}
	return S_OK;
}

void GameManager_Bullet::release()
{
	
}

void GameManager_Bullet::update()
{
	UI.update();

	if (InputManager->isOnceKeyDown(VK_SPACE)) {
		bullets.push_back(Bullet(player.pos.x + 50, player.pos.y, 5, 5, 10, 0));
	}


	
	for (size_t i = 0; i < bullets.size(); i++)
	{
		bullets[i].bulletMove();
	}
	player.Input(1);


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


	//bulletMove();
	//playerKeyControl();
	//collision();

	//for (size_t i = 0; i < BULLETMAX; i++)
	//{
	//	RECT temp;
	//	if (IntersectRect(&temp, &bullet[i].rc, &))
	//	{
	//		bullet[i].rc = RectMakeCenter(m_player1.right + 15,
	//			m_player1.top + (m_player1.bottom - m_player1.top) / 2, 20, 20);
	//		m_gaugeFront.left += 20;

	//		if (m_gaugeFront.left >= m_gaugeFront.right)
	//		{
	//			m_gaugeFront.left = m_gaugeBack.right;
	//		}
	//	}
	//}
	FixedUpdate();
}

void GameManager_Bullet::FixedUpdate()
{

}


void GameManager_Bullet::render(HDC hdc)
{

	//Rectangle(hdc, m_body.left, m_body.top, m_body.right, m_body.bottom);

	//if (isFire)
	//{
	//	Ellipse(hdc, m_bullet.left, m_bullet.top, m_bullet.right, m_bullet.bottom);
	//}

	//Rectangle(hdc, m_player1.left, m_player1.top, m_player1.right, m_player1.bottom);
	//Rectangle(hdc, m_player2.left, m_player2.top, m_player2.right, m_player2.bottom);
	//Rectangle(hdc, m_gaugeBack.left, m_gaugeBack.top, m_gaugeBack.right, m_gaugeBack.bottom);

	//HBRUSH brush = CreateSolidBrush(RGB(m_red, m_green, 0));
	//Rectangle(hdc, m_gaugeFront.left, m_gaugeFront.top, m_gaugeFront.right, m_gaugeFront.bottom);
	//FillRecty(hdc, &m_gaugeFront, brush);
	//DeleteObject(brush);
	//gaugeDraw();


	//for (size_t i = 0; i < BULLETMAX; i++)
	//{

	//	if (!bullet[i].isFire)continue;
	//	Ellipse(hdc, bullet[i].rc.left, bullet[i].rc.top, bullet[i].rc.right, bullet[i].rc.bottom);
	//}
	UI.render(hdc);
	for (size_t i = 0; i < bullets.size(); i++)
	{
		bullets[i].Render(hdc);
	}
	player.Render(hdc);
	enemy.Render(hdc);
}



//Bullet
void GameManager_Bullet::bulletMove()
{
	for (size_t i = 0; i < BULLETMAX; i++)
	{
		//발사된 총알은 영향을 주지말자
		if (!bullet[i].isFire)continue;

		OffsetRect(&bullet[i].rc, bullet[i].speed, 0);

	}
}

//Player
void GameManager_Bullet::bulletFire()
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


//UI
void GameManager_Bullet::gaugeDraw()
{
	if (m_gaugeFront.right - m_gaugeFront.left <= 200)
	{
		m_red = 200;
	}
	if (m_gaugeFront.right - m_gaugeFront.left <= 80)
	{
		m_red = 255;
		m_green = 0;
	}
}



//engine
void GameManager_Bullet::collision()
{
	
}

//Input
void GameManager_Bullet::playerKeyControl()
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

