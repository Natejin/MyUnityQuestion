#pragma once
#include "../Enemy.h"
class BulletEnemy:public Enemy
{
public:
	BulletEnemy();
	BulletEnemy(double posX, double posY, double sizeX, double sizeY, double speedX, double speedY);
	BulletEnemy(Vector2 pos, Vector2 size, Vector2 speed);
	virtual ~BulletEnemy();
	virtual void Move();
	virtual void Render(HDC hdc);
};

