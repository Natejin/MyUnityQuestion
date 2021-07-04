#pragma once
#include "MoveObj.h"
class Unit : public MoveObj
{
protected:
	//friend class Obj;
	MOVE_DIR currentlyDir;
protected:
	Unit(const Unit& obj);
	~Unit();
	Unit();

public:
	virtual bool Enable();
	virtual bool Disable();
	virtual bool Init();
	virtual void Input(float deltaTime);
	virtual int Update(float deltaTime);
	virtual int LateUpdate(float deltaTime);
	virtual void Collision(float deltaTime);
	virtual void Render(HDC hdc, float deltaTime);
	virtual Unit* Clone();
};

