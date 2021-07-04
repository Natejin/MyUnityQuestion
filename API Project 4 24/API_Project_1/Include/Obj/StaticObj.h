#pragma once
#include "MonoBehavior.h"

class StaticObj :public MonoBehavior
{

protected:
	StaticObj();
	StaticObj(const StaticObj& obj);
	virtual ~StaticObj();
public:
	virtual bool Enable();
	virtual bool Disable();
	virtual bool Init() = 0;
	virtual void Input(double deltaTime);
	virtual int Update(double deltaTime);
	virtual int LateUpdate(double deltaTime);
	virtual void Collision(double deltaTime);
	virtual void Render(HDC hdc, double deltaTime);
	virtual StaticObj* Clone() = 0;
};

