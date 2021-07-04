#pragma once
#include "MonoBehavior.h"
class Unit : public MonoBehavior
{
protected:
	//friend class Obj;
	MOVE_DIR currentlyDir;
protected:
	Unit(const Unit& obj);
	~Unit();


public:
	Unit();
	virtual bool Enable();
	virtual bool Disable();
	virtual bool Init();
	virtual void Input(double deltaTime);
	virtual int Update(double deltaTime);
	virtual int LateUpdate(double deltaTime);
	virtual void Collision(double deltaTime);
	virtual void Render(HDC hdc, double deltaTime);
	virtual Unit* Clone();
};

