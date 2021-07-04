#pragma once
#include "../Obj/Component.h"

class Transform : public Component
{
protected:
	Transform(const Transform& obj);
	virtual ~Transform() {};
public:
	Transform() {};
};

