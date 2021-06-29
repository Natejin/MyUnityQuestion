#include "Unit.h"

Unit::Unit()
{
}

Unit::Unit(double posX, double posY, double sizeX, double sizeY, double speedX, double speedY)
	:MonoBehavior(posX, posY, sizeX, sizeY, speedX, speedY)
{
}

Unit::Unit(Vector2 pos, Vector2 size, Vector2 speed)
	: MonoBehavior(pos, size, speed)
{
}

Unit::~Unit()
{
}

void Unit::Move()
{
}

void Unit::Render()
{
}
