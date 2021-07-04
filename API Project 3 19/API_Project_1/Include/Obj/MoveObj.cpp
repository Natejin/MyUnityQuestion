#include "MoveObj.h"

MoveObj::MoveObj()
    :speed(DEFAULT_SPEED)
{
}

MoveObj::MoveObj(const MoveObj& obj)
    :MonoBehavior(obj)
{
}

MoveObj::~MoveObj()
{
}

void MoveObj::Translate(double x, double y)
{
	pos.x += x;
    pos.y += y;
}

void MoveObj::Translate(double x, double y, float deltaTime)
{
    pos.x += x * deltaTime;
    pos.y += y * deltaTime;
}

void MoveObj::Translate(const Vector2& vec)
{
    pos += vec;
}

void MoveObj::Translate(const Vector2& vec, float deltaTime)
{
	pos += vec * deltaTime;
}

void MoveObj::TranslateX(double x)
{
    pos.x += x;
}

void MoveObj::TranslateX(double x, float deltaTime)
{
    pos.x += x * deltaTime;
}

void MoveObj::TranslateY(double y)
{
    pos.y += y;
}

void MoveObj::TranslateY(double y, float deltaTime)
{
    pos.y += y * deltaTime;
}

void MoveObj::TranslateXInTime(float deltaTime, MOVE_DIR dir)
{
    pos.x += speed * deltaTime * (double)dir;
}

void MoveObj::TranslateYInTime(float deltaTime, MOVE_DIR dir)
{
    pos.y += speed * deltaTime * (double)dir;
}

void MoveObj::TranslateAngle()
{
    pos.x += cosf(angle) * speed;
    pos.y += sinf(angle) * speed;
}

void MoveObj::TranslateAngle(float deltaTime)
{
    pos.x += cosf(angle) * speed * deltaTime;
    pos.y += sinf(angle) * speed * deltaTime;
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
