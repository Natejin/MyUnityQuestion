#pragma once
#include "MonoBehavior.h"

class Projectile : public MonoBehavior
{
protected:
	Projectile(const Projectile& obj);
	~Projectile();

	double limitDistance;
	double distance;
	double limitTime;

public:
	void SetDistance(double distance) { limitDistance = distance; }

public:
	Projectile();
	virtual bool Enable();
	virtual bool Disable();
	virtual bool Init();
	virtual int Update(double deltaTime);
	virtual int LateUpdate(double deltaTime);
	virtual void Collision(double deltaTime);
	virtual void Render(HDC hdc, double deltaTime);
	virtual Projectile* Clone();
};

