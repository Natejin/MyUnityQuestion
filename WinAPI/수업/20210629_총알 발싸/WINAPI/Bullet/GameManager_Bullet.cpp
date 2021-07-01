#include "GameManager_Bullet.h"

GameManager_Bullet::GameManager_Bullet()
{

}

GameManager_Bullet::~GameManager_Bullet()
{
}

HRESULT GameManager_Bullet::Init()
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
	enemy =  BulletEnemy(800,WINSIZEY/2, 40, 20, 0, 5);
	enemy.HP = 100;
	UI.Init();
	//총알 생성
	//for (size_t i = 0; i < 5; i++)
	//{
	//	bullets.push_back(Bullet(100,100+i*50, 5, 5, 10, 5));
	//}
	return S_OK;
}

void GameManager_Bullet::Release()
{
	
}

void GameManager_Bullet::Update()
{
	UI.Update();

	if (MG_INPUT->isStayKeyDown('Q')) {
		for (int i = 0; i < 5; i++)
		{
			Bullet* bullet = poolBullet.PopObject();
			bullet->Initiate(player.pos.x + 50, player.pos.y, 5, 5, 10, (double)(-10 + i * 5), 5);
			bullet->damage = 3;
			bullets.push_back(*bullet);
		}
	}

	if (MG_INPUT->isStayKeyDown('W')) {
		Bullet* bullet = poolBullet.PopObject();
		bullet->Initiate(player.pos.x + 50, player.pos.y, 5, 5, 10, 0, 5);
		bullet->damage = 5;
		bullets.push_back(*bullet);
	}

	if (MG_INPUT->isStayKeyDown('E')) {
		Bullet* bullet = poolBullet.PopObject();
		bullet->Initiate(player.pos.x + 50, player.pos.y, 10, 10, 10, 0, 10);
		bullet->damage = 5;
		bullets.push_back(*bullet);
	}
	
	for (int i = 0; i < bullets.size(); i++)
	{
		bullets[i].bulletMove();

	}

	/*for (int i = 0; i < bullets2.size(); i++)
	{
		bullets2[i].bulletMove();

	}*/
	player.InputManager(1);
	FixedUpdate();
}

void GameManager_Bullet::FixedUpdate()
{
	int index = 0;
	vector<int> removeIndex;
	for (Bullet& attack : bullets) // access by reference to avoid copying
	{
		if (attack.CheckCollision(enemy))
		{
			poolBullet.ReturnObject(&attack);
			
			enemy.HP -= 5;
			removeIndex.push_back(bullets[index].GetInstanceID());
			bullets[index].pos.x = WINSIZEX + 100;
			bullets.erase(bullets.begin() + index);
			//UI.m_gaugeFront.size.x = enemy.HP;
		}
		else if (bullets[index].pos.x > WINSIZEX) {
			bullets[index].pos.x = WINSIZEX + 100;
			poolBullet.ReturnObject(&attack);
			removeIndex.push_back(bullets[index].GetInstanceID());
			bullets.erase(bullets.begin() + index);
			
		}
		else {
			index++;
		}

	}
	//int count = vector.size();
	
	//for (size_t i = 0; i < removeIndex.size(); i++)
	//{
	//	for (size_t j = 0; j < bullets.size(); j++)
	//	{
	//		if (bullets[j].GetInstanceID() == removeIndex[i])
	//		{
	//			bullets.erase(bullets.begin() + j);
	//			break;
	//		}
	//	}
	//}
	//index = 0;
	//for (Bullet& attack : bullets2) // access by reference to avoid copying
	//{
	//	if (attack.CheckCollision(player))
	//	{
	//		poolBullet.ReturnObject(&attack);
	//		bullets2.erase(bullets2.begin() + index);
	//		player.HP -= 5;
	//		//UI.m_gaugeFront.size.x = player.HP;
	//	}
	//	else if (bullets2[index].pos.x < 0) {
	//		poolBullet.ReturnObject(&attack);
	//		bullets2.erase(bullets2.begin() + index);
	//	} {
	//		index++;
	//	}
	//}
}

void GameManager_Bullet::bulletFire()
{
}

void GameManager_Bullet::bulletMove()
{
}

void GameManager_Bullet::gaugeDraw()
{
}

void GameManager_Bullet::collision()
{
}

void GameManager_Bullet::playerKeyControl()
{
}


void GameManager_Bullet::Render(HDC hdc)
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
	UI.Render(hdc);
	for (size_t i = 0; i < bullets.size(); i++)
	{
		bullets[i].Render(hdc);
	}

	//for (size_t i = 0; i < bullets2.size(); i++)
	//{
	//	bullets2[i].Render(hdc);
	//}
	player.Render(hdc);
	enemy.Render(hdc);
	static TCHAR strMouse[64] = {};
	wsprintf(strMouse, TEXT("player HP : %d "), player.HP);
	TextOut(hdc, 600, 55, strMouse, lstrlen(strMouse));

	wsprintf(strMouse, TEXT("Enemy HP : %d "), enemy.HP);
	TextOut(hdc, 600, 75, strMouse, lstrlen(strMouse));

	if (MG_INPUT->isToggleKey(VK_TAB)) {

		wsprintf(strMouse, TEXT("objectPoolSize : %d "), poolBullet.GetObjectPoolSize());
		TextOut(hdc, 600, 95, strMouse, lstrlen(strMouse));

		wsprintf(strMouse, TEXT("StockSize : %d "), poolBullet.GetStockSize());
		TextOut(hdc, 600, 115, strMouse, lstrlen(strMouse));

		wsprintf(strMouse, TEXT("player bullet on Map : %d "), (int)bullets.size());
		TextOut(hdc, 600, 135, strMouse, lstrlen(strMouse));

		//wsprintf(strMouse, TEXT("enemy bullet on Map  : %d "), (int)bullets2.size());
		//TextOut(hdc, 600, 155, strMouse, lstrlen(strMouse));
	}
	
}







