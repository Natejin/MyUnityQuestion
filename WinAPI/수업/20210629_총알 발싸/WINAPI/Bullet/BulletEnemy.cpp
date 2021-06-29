#include "BulletEnemy.h"

BulletEnemy::BulletEnemy()
{
}

BulletEnemy::BulletEnemy(double posX, double posY, double sizeX, double sizeY, double speedX, double speedY)
	:Enemy(posX, posY, sizeX, sizeY, speedX, speedY)
{
}

BulletEnemy::BulletEnemy(Vector2 pos, Vector2 size, Vector2 speed)
	: Enemy(pos, size, speed)
{
}

BulletEnemy::~BulletEnemy()
{
}

void BulletEnemy::Move()
{
}

void BulletEnemy::Render(HDC hdc)
{
	Rectangle(hdc, pos.x - size.x, pos.y - size.y, pos.x + size.x, pos.y + size.y);
}
