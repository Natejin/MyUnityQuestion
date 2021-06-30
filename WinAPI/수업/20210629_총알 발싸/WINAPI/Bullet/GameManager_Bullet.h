#pragma once
#include "../DummyNode.h"
#include "Bullet.h"
#include "BulletPlayer.h"
#include "BulletEnemy.h"
#include "BulletUIManager.h"
#include "../ObjectPool.h"

#define BULLETMAX 30
class GameManager_Bullet :public DummyNode<GameManager_Bullet>
{
struct  tagBullet
{
	RECT rc;
	bool isFire;
	float speed;
};
tagBullet bullet[BULLETMAX];

Bullet bullet1;
vector<Bullet> bullets;
ObjectPool<Bullet> bullets2;
BulletUIManager UI;


RECT m_player1;
RECT m_player2;


//게이지
RECT m_gaugeFront;
RECT m_gaugeBack;

//색상
int m_red;
int m_green;

public:
BulletPlayer player;
BulletEnemy* enemy;

public:
	GameManager_Bullet();
	virtual ~GameManager_Bullet();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);
	void FixedUpdate();

	void  bulletFire();
	void bulletMove();
	void gaugeDraw();
	void collision();
	void playerKeyControl();
};