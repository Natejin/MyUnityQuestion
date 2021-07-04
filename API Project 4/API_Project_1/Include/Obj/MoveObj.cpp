#include "MoveObj.h"

MoveObj::MoveObj()
    :MonoBehavior(),
    speed(DEFAULT_SPEED)
{
}

MoveObj::MoveObj(const MoveObj& obj)
    :MonoBehavior(obj)
{
    angle = obj.angle;
    speed = obj.speed;
}

MoveObj::~MoveObj()
{
}

void MoveObj::Translate(double x, double y)
{
	pos.x += x;
    pos.y += y;
}

void MoveObj::Translate(double x, double y, double deltaTime)
{
    pos.x += x * deltaTime;
    pos.y += y * deltaTime;
}

void MoveObj::Translate(const Vector2& vec)
{
    pos += vec;
}

void MoveObj::Translate(const Vector2& vec, double deltaTime)
{
	pos += vec * deltaTime;
}

void MoveObj::TranslateX(double x)
{
    pos.x += x;
}

void MoveObj::TranslateX(double x, double deltaTime)
{
    pos.x += x * deltaTime;
}

void MoveObj::TranslateY(double y)
{
    pos.y += y;
}

void MoveObj::TranslateY(double y, double deltaTime)
{
    pos.y += y * deltaTime;
}

void MoveObj::TranslateXInTime(double deltaTime, MOVE_DIR dir)
{
    pos.x += speed * deltaTime * (double)dir;
}

void MoveObj::TranslateYInTime(double deltaTime, MOVE_DIR dir)
{
    pos.y += speed * deltaTime * (double)dir;
}

void MoveObj::TranslateAngle()
{
    pos.x += cosf((float)angle) * speed;
    pos.y += sinf((float)angle) * speed;
}

void MoveObj::TranslateAngle(double deltaTime)
{
    pos.x += cosf((float)angle) * speed * deltaTime;
    pos.y += sinf((float)angle) * speed * deltaTime;
}



bool MoveObj::Enable()
{
    return true;
}

bool MoveObj::Disable()
{
    return true;
}



void MoveObj::Input(double deltaTime)
{
    MonoBehavior::Input(deltaTime);
}

int MoveObj::Update(double deltaTime)
{
    MonoBehavior::Update(deltaTime);
    return 0;
}

int MoveObj::LateUpdate(double deltaTime)
{
    MonoBehavior::LateUpdate(deltaTime);
    return 0;
}

void MoveObj::Collision(double deltaTime)
{
    MonoBehavior::Collision( deltaTime);
}

void MoveObj::Render(HDC hdc, double deltaTime)
{
    MonoBehavior::Render(hdc, deltaTime);
}
