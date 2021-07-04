#pragma once
#include "Unit.h"

class Enemy : public Unit
{
private:
	//friend class Obj;

protected:
	Enemy(const Enemy& obj);
	~Enemy();

public:
	Enemy();
	virtual bool Enable();
	virtual bool Disable();
	virtual bool Init();
	virtual int Update(float deltaTime);
	virtual int LateUpdate(float deltaTime);
	virtual void Collision(float deltaTime);
	virtual void Render(HDC hdc, float deltaTime);
	virtual Enemy* Clone();
};

