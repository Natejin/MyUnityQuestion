#pragma once
#include "Unit.h"

class Enemy : public Unit
{
private:
	//friend class Obj;

protected:
	Enemy(const Enemy& obj);
	~Enemy();
	double fireLimitTime;
	double fireTime;
public:
	Enemy();
	virtual bool Enable();
	virtual bool Disable();
	virtual bool Init();
	virtual int Update(double deltaTime);
	virtual int LateUpdate(double deltaTime);
	virtual void Collision(double deltaTime);
	virtual void Render(HDC hdc, double deltaTime);
	virtual Enemy* Clone();

private:
	void Fire();
};

