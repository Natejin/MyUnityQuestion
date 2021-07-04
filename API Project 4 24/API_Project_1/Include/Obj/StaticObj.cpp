#include "StaticObj.h"

StaticObj::StaticObj()
{
}

StaticObj::StaticObj(const StaticObj& obj)
	:MonoBehavior(obj)
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



void StaticObj::Input(double deltaTime)
{
	MonoBehavior::Input(deltaTime);
}

int StaticObj::Update(double deltaTime)
{
	MonoBehavior::Update(deltaTime);
	return 0;
}
 
int StaticObj::LateUpdate(double deltaTime)
{
	MonoBehavior::LateUpdate(deltaTime);
	return 0;
}

void StaticObj::Collision(double deltaTime)
{
	MonoBehavior::Collision( deltaTime);
}

void StaticObj::Render(HDC hdc, double deltaTime)
{
	MonoBehavior::Render(hdc, deltaTime);
}
