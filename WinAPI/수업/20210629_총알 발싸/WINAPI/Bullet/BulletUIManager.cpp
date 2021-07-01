#include "BulletUIManager.h"
#include "GameManager_Bullet.h"


HRESULT BulletUIManager::Init()
{

	//m_gaugeFront = RectMakeCenter(WINSIZEX / 2, 100, hp, 50);
	m_gaugeFront = MonoBehavior(WINSIZEX / 2, 100, GameManager_Bullet::GetSingleton()->enemy.HP, 50, 0, 0);
	m_gaugeBack = RectMakeCenter(WINSIZEX / 2, 100, 100, 50);

	m_red = 0;
	m_green = 255;
	return S_OK;
}

void BulletUIManager::Release()
{
}

void BulletUIManager::Update()
{
	GaugeDraw();
}

void BulletUIManager::Render(HDC hdc)
{
	m_gaugeFront.DrawRect(hdc);
}

void BulletUIManager::GaugeDraw()
{
	int temp= GameManager_Bullet::GetSingleton()->enemy.HP;

	//m_gaugeFront.left = ((m_gaugeFront.right - m_gaugeFront.left) / enemy.maxHP * enemy.HP);
	//float ratio = enemy.HP / (float)enemy.maxHP;
	//if (ratio >= 0.8)
	//{
	//	m_red = 200;
	//}else if (ratio >= 0.4)
	//{
	//	m_red = 255;
	//	m_green = 0;
	//}
}
