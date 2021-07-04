#include "Projectile.h"

Projectile::Projectile(const Projectile& obj)
	:MonoBehavior(obj),
	distance(0.f),
	limitDistance(500)
{
}

Projectile::~Projectile()
{
}

Projectile::Projectile()
	:MonoBehavior()
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

int Projectile::Update(double	deltaTime)
{
	MonoBehavior::Update(deltaTime);
	//TranslateAngle(deltaTime);
	Translate(speed,0,deltaTime);
	//if (distance <= limitDistance)
	//{
	//	distance += speed * deltaTime;
	//}
	//else {
	//	Destory();
	//}
	distance += speed * deltaTime;
	if (distance >= limitDistance)
	{
		Destory();
	}
	return 0;
}

int Projectile::LateUpdate(double deltaTime)
{
	MonoBehavior::LateUpdate(deltaTime);
	return 0;
}

void Projectile::Collision(double deltaTime)
{
	MonoBehavior::Collision(deltaTime);
}

void Projectile::Render(HDC hdc, double deltaTime)
{
	MonoBehavior::Render(hdc, deltaTime);
	DrawEllipse(hdc);
}

Projectile* Projectile::Clone()
{
	return new Projectile(*this);
}
