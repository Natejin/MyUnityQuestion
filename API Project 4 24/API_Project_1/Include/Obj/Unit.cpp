#include "Unit.h"

Unit::Unit(const Unit& obj)
	:MonoBehavior(obj)
{
}

Unit::~Unit()
{
}

Unit::Unit()
{
}

bool Unit::Enable()
{
	return false;
}

bool Unit::Disable()
{

	return false;
}

bool Unit::Init()
{
	return false;
}

void Unit::Input(double deltaTime)
{
	MonoBehavior::Input(deltaTime);
}

int Unit::Update(double deltaTime)
{
	MonoBehavior::Update(deltaTime);
	return 0;
}

int Unit::LateUpdate(double deltaTime)
{
	MonoBehavior::LateUpdate(deltaTime);
	return 0;
}

void Unit::Collision(double deltaTime)
{
	MonoBehavior::Collision(deltaTime);
}

void Unit::Render(HDC hdc, double deltaTime)
{
	MonoBehavior::Render(hdc, deltaTime);
}

Unit* Unit::Clone()
{
	return nullptr;
}
