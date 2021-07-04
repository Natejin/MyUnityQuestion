#pragma once
#include "../Obj/Component.h"

class RigidBody : public Component
{
protected:
	RigidBody(const RigidBody& obj);
	virtual ~RigidBody() {};
public:
	RigidBody() {};

};


//class RigidBody 
//{
//public:
//	//virtual bool Enable();
//	//virtual bool Disable();
//	//virtual bool Init() = 0;
//	//virtual void Input(double deltaTime);
//	//virtual int Update(double deltaTime);
//	//virtual int LateUpdate(double deltaTime);
//	//virtual void Collision(double deltaTime);
//	//virtual void Render(HDC hdc, double deltaTime);
//};
