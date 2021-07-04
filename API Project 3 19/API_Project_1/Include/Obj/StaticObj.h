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
	virtual void Input(float deltaTime);
	virtual int Update(float deltaTime);
	virtual int LateUpdate(float deltaTime);
	virtual void Collision(float deltaTime);
	virtual void Render(HDC hdc, float deltaTime);
	virtual StaticObj* Clone() = 0;
};

