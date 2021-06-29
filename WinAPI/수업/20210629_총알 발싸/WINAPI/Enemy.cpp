#include "Enemy.h"

Enemy::Enemy()
{
}

Enemy::Enemy(double posX, double posY, double sizeX, double sizeY, double speedX, double speedY)
	:Unit(posX, posY, sizeX, sizeY, speedX, speedY)
{
}

Enemy::Enemy(Vector2 pos, Vector2 size, Vector2 speed)
	: Unit(pos, size, speed)
{
}

Enemy::~Enemy()
{
}

void Enemy::Move()
{
}

void Enemy::Render(HDC hdc)
{
}
