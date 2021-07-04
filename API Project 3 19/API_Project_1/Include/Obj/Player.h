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
	virtual void Input(float deltaTime);
	virtual int Update(float deltaTime);
	virtual int LateUpdate(float deltaTime);
	virtual void Collision(float deltaTime);
	virtual void Render(HDC hdc, float deltaTime);
	virtual Player* Clone();

private:
	void Fire();
};

