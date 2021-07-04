#pragma once
#include "MonoBehavior.h"

class Background : public MonoBehavior
{

protected:

	Background(const Background& obj);
	virtual ~Background();

public:
	Background();

public:
	virtual bool Enable();
	virtual bool Disable();
	virtual bool Init();
	virtual void Input(double deltaTime);
	virtual int Update(double deltaTime);
	virtual int LateUpdate(double deltaTime);
	virtual void Collision(double deltaTime);
	virtual void Render(HDC hdc, double deltaTime);
	virtual Background* Clone();
};

