#pragma once
#include "../Player.h"
class BulletPlayer : public Player
{
public:
	BulletPlayer();
	BulletPlayer(double posX, double posY, double sizeX, double sizeY, double speedX, double speedY);
	BulletPlayer(Vector2 pos, Vector2 size, Vector2 speed);
	virtual ~BulletPlayer();
	virtual void Move();
	virtual void Input(int code);
	void bulletFire();
	virtual void Render(HDC hdc);


};

