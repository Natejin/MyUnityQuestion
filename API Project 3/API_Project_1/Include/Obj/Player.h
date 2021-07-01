#pragma once
#include "MoveObj.h"

class Player : public MoveObj
{
private:
	Player();
	Player(const Player& obj);
	~Player();
	  
public:
	virtual bool Enable();
	virtual bool Disable();
	virtual bool Init();
	virtual void Input(float deltaTime);
	virtual int Update(float deltaTime);
	virtual int LateUpdate(float deltaTime);
	virtual void Collision(float deltaTime);
	virtual void Render(HDC hdc, float deltaTime);
};

