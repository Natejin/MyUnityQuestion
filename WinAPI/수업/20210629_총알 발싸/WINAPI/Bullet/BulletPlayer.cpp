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

void BulletPlayer::Input(int code)
{
	if (InputManager->isStayKeyDown(VK_UP)){
		pos.y -= speed.y;
	}
	if (InputManager->isStayKeyDown(VK_DOWN)){
		pos.y += speed.y; 
	}
	if (InputManager->isStayKeyDown(VK_LEFT)){
		pos.x -= speed.x;
	}
	if (InputManager->isStayKeyDown(VK_RIGHT)){
		pos.x += speed.x;
	}
}

void BulletPlayer::bulletFire()
{

}

void BulletPlayer::Render(HDC hdc)
{
	Rectangle(hdc, pos.x - size.x, pos.y - size.y, pos.x + size.x, pos.y + size.y);
}
