#pragma once
#include "../MonoBehavior.h"

class Bullet : public MonoBehavior
{


public:
	Bullet();
	Bullet(double posX, double posY, double sizeX, double sizeY, double speedX, double speedY);
	Bullet(Vector2 pos, Vector2 size, Vector2 speed);
	~Bullet();
	bool isFire;
	void bulletMove();
	virtual void Render(HDC hdc);

};

