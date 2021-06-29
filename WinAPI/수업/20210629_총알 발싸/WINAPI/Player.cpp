#include "Player.h"

Player::Player()
{
}

Player::Player(double posX, double posY, double sizeX, double sizeY, double speedX, double speedY)
	:Unit(posX, posY, sizeX, sizeY, speedX, speedY)
{
}

Player::Player(Vector2 pos, Vector2 size, Vector2 speed)
	: Unit(pos, size, speed)

{
}

Player::~Player()
{
}

void Player::Move()
{
}

void Player::Render(HDC hdc)
{
}
