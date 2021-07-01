#pragma once
#include "Obj.h"

class MoveObj :public Obj
{

protected:
	MoveObj();
	MoveObj(const MoveObj& obj);
	virtual ~MoveObj();
public:
	virtual bool Enable();
	virtual bool Disable();
	virtual bool Init() = 0;
	virtual void Input(float deltaTime);
	virtual int Update(float deltaTime);
	virtual int LateUpdate(float deltaTime);
	virtual void Collision(float deltaTime);
	virtual void Render(HDC hdc, float deltaTime);
};

