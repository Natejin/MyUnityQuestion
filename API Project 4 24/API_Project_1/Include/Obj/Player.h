#pragma once
#include "Unit.h"

//#include "../InputManager.h"
class Player : public Unit
{
private:
	//friend class Obj;

protected:
	Player(const Player& obj);
	~Player();

public:
	Player();
	virtual bool Enable();
	virtual bool Disable();
	virtual bool Init();
	virtual void Input(double deltaTime);
	virtual int Update(double deltaTime);
	virtual int LateUpdate(double deltaTime);
	virtual void Collision(double deltaTime);
	virtual void Render(HDC hdc, double deltaTime);
	virtual Player* Clone();

private:
	void Fire();
};

