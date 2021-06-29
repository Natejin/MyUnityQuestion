#include "Bullet.h"

Bullet::Bullet()
{

}

Bullet::Bullet(double posX, double posY, double sizeX, double sizeY, double speedX, double speedY)
	:MonoBehavior( posX,  posY, sizeX,  sizeY,  speedX,  speedY)
{

}

Bullet::Bullet(Vector2 pos, Vector2 size, Vector2 speed)
	:MonoBehavior(pos,size,speed)
{

}

Bullet::~Bullet()
{
}

void Bullet::bulletMove()
{
	pos += speed;
	//pos.x += speed.x;
}

void Bullet::Render(HDC hdc)
{
	Rectangle(hdc, int(pos.x - size.x), int(pos.y - size.y), int(pos.x + size.x), int(pos.y + size.y));
	Ellipse(hdc, int(pos.x - size.x), (int)(pos.y - size.y), int(pos.x + size.x * 2), int(pos.y + size.y));
}

