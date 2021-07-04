#include "Projectile.h"

Projectile::Projectile(const Projectile& obj)
	:MoveObj(obj),
	distance(0.f),
	limitDistance(500)
{
}

Projectile::~Projectile()
{
}

Projectile::Projectile()
{
}

bool Projectile::Enable()
{
	return true;
}

bool Projectile::Disable()
{
	return true;
}

bool Projectile::Init()
{
	SetSize(50, 50);
	SetSpeed(400);
	return true;
}

int Projectile::Update(float deltaTime)
{
	MoveObj::Update(deltaTime);
	//TranslateAngle(deltaTime);
	Translate(speed,0,deltaTime);
	if (distance <= limitDistance)
	{
		distance += speed * deltaTime;
	}
	else {
		Destory();
	}

	return 0;
}

int Projectile::LateUpdate(float deltaTime)
{
	MoveObj::LateUpdate(deltaTime);
	return 0;
}

void Projectile::Collision(float deltaTime)
{
	MoveObj::Collision(deltaTime);
}

void Projectile::Render(HDC hdc, float deltaTime)
{
	MoveObj::Render(hdc, deltaTime);
	DrawEllipse(hdc);
}

Projectile* Projectile::Clone()
{
	return new Projectile(*this);
}
