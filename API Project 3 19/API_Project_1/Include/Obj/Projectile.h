#pragma once
#include "MoveObj.h"

class Projectile : public MoveObj
{
protected:
	Projectile(const Projectile& obj);
	~Projectile();

	float limitDistance;
	float distance;
	float limitTime;

public:
	Projectile();
	virtual bool Enable();
	virtual bool Disable();
	virtual bool Init();
	virtual int Update(float deltaTime);
	virtual int LateUpdate(float deltaTime);
	virtual void Collision(float deltaTime);
	virtual void Render(HDC hdc, float deltaTime);
	virtual Projectile* Clone();
};

