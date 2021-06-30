#pragma once
#include "MonoBehavior.h"
class Unit : public MonoBehavior
{
public:
	int maxHP;
	int HP;
public:
	Unit();
	Unit(double posX, double posY, double sizeX, double sizeY, double speedX, double speedY);
	Unit(Vector2 pos, Vector2 size, Vector2 speed);
	virtual ~Unit();
	virtual void Move();
	virtual void Render();
};

