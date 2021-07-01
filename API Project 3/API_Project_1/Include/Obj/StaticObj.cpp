#include "StaticObj.h"

StaticObj::StaticObj()
{
}

StaticObj::StaticObj(const StaticObj& obj)
	:Obj(obj)
{
}

StaticObj::~StaticObj()
{
}

bool StaticObj::Enable()
{
	return true;
}

bool StaticObj::Disable()
{
	return true;
}



void StaticObj::Input(float deltaTime)
{
}

int StaticObj::Update(float deltaTime)
{
	return 0;
}

int StaticObj::LateUpdate(float deltaTime)
{
	return 0;
}

void StaticObj::Collision(float deltaTime)
{
}

void StaticObj::Render(HDC hdc, float deltaTime)
{
}
