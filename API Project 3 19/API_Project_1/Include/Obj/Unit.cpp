#include "Unit.h"

Unit::Unit(const Unit& obj)
	:MoveObj(obj)
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

void Unit::Input(float deltaTime)
{
	MoveObj::Input(deltaTime);
}

int Unit::Update(float deltaTime)
{
	MoveObj::Update(deltaTime);
	return 0;
}

int Unit::LateUpdate(float deltaTime)
{
	MoveObj::LateUpdate(deltaTime);
	return 0;
}

void Unit::Collision(float deltaTime)
{
	MoveObj::Collision(deltaTime);
}

void Unit::Render(HDC hdc, float deltaTime)
{
	MoveObj::Render(hdc, deltaTime);
}

Unit* Unit::Clone()
{
	return nullptr;
}
