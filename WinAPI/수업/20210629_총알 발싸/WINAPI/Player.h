#pragma once
#include "Unit.h"
class Player :public Unit
{

public:
	Player();
	Player(double posX, double posY, double sizeX, double sizeY, double speedX, double speedY);
	Player(Vector2 pos, Vector2 size, Vector2 speed);
	virtual ~Player();
	virtual void Move();
	virtual void Render(HDC hdc);
};

