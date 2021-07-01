#include "BulletPlayer.h"

BulletPlayer::BulletPlayer()
{
}

BulletPlayer::BulletPlayer(double posX, double posY, double sizeX, double sizeY, double speedX, double speedY)
	:Player(posX, posY, sizeX, sizeY,speedX,speedY)
{
}

BulletPlayer::BulletPlayer(Vector2 pos, Vector2 size, Vector2 speed)
	:Player(pos,size,speed)
{
}

BulletPlayer::~BulletPlayer()
{
}

void BulletPlayer::Move()
{
	
}

void BulletPlayer::InputManager(int code)
{
	if (MG_INPUT->isStayKeyDown(VK_UP)){
		pos.y -= speed.y;
	}
	if (MG_INPUT->isStayKeyDown(VK_DOWN)){
		pos.y += speed.y; 
	}
	if (MG_INPUT->isStayKeyDown(VK_LEFT)){
		pos.x -= speed.x;
	}
	if (MG_INPUT->isStayKeyDown(VK_RIGHT)){
		pos.x += speed.x;
	}
}

void BulletPlayer::bulletFire()
{

}

void BulletPlayer::Render(HDC hdc)
{
	DrawRect(hdc);
}
