#pragma once
#include "Unit.h"

class Enemy : public Unit
{
public:
	Enemy();
	Enemy(double posX, double posY, double sizeX, double sizeY, double speedX, double speedY);
	Enemy(Vector2 pos, Vector2 size, Vector2 speed);
	virtual ~Enemy();
	virtual void Move();
	virtual void Render(HDC hdc);
};

