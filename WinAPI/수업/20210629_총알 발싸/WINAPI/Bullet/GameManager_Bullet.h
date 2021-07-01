#pragma once
#include "../DummyNode.h"
#include "Bullet.h"
#include "BulletPlayer.h"
#include "BulletEnemy.h"
#include "BulletUIManager.h"

#define BULLETMAX 30
class GameManager_Bullet :public DummyNode<GameManager_Bullet>
{



vector<Bullet> bullets;
ObjectPool<Bullet> poolBullet;

//vector<Bullet> bullets2;
//ObjectPool<Bullet> poolBullet2;


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
BulletEnemy enemy;

public:
	GameManager_Bullet();
	virtual ~GameManager_Bullet();

	virtual HRESULT Init();
	virtual void Release();
	virtual void Update();
	virtual void Render(HDC hdc);
	void FixedUpdate();

	void bulletFire();
	void bulletMove();
	void gaugeDraw();
	void collision();
	void playerKeyControl();
};