#include "MoveObj.h"

MoveObj::MoveObj()
{
}

MoveObj::MoveObj(const MoveObj& obj)
    :Obj(obj)
{
}

MoveObj::~MoveObj()
{
}

bool MoveObj::Enable()
{
    return true;
}

bool MoveObj::Disable()
{
    return true;
}



void MoveObj::Input(float deltaTime)
{
}

int MoveObj::Update(float deltaTime)
{
    return 0;
}

int MoveObj::LateUpdate(float deltaTime)
{
    return 0;
}

void MoveObj::Collision(float deltaTime)
{
}

void MoveObj::Render(HDC hdc, float deltaTime)
{
}
