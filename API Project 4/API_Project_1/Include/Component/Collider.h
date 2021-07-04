#pragma once
#include "../Obj/Component.h"

class Collider : public Component
{
public:
	Collider() {};
	Collider(const Collider& obj);
	virtual ~Collider() {};
};

