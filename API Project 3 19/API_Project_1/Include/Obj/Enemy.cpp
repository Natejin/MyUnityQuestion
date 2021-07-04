#include "Enemy.h"
#include "../Core.h"

Enemy::Enemy(const Enemy& obj)
	:Unit(obj)
{
}

Enemy::~Enemy()
{
}

Enemy::Enemy()
{
}

bool Enemy::Enable()
{
	return true;
}

bool Enemy::Disable()
{
	return true;
}

bool Enemy::Init()
{
	SetPos(Vector2(Core::GetSingleton()->GetResolution().height - 300, 200));
	SetSize(Vector2(50, 50));
	SetSpeed(400.f);
	currentlyDir = MOVE_DIR::FRONT;
	return true;
}


int Enemy::Update(float deltaTime)
{
	MoveObj::Update(deltaTime);
	if (pos.y < scale.y )
	{
		currentlyDir = MOVE_DIR::FRONT;
	}
	else if(pos.y > Core::GetSingleton()->GetResolution().height - scale.y - 100){
	
		currentlyDir = MOVE_DIR::BACK;
	}
	TranslateYInTime(deltaTime, currentlyDir);
	return 0;
}

int Enemy::LateUpdate(float deltaTime)
{
	MoveObj::LateUpdate(deltaTime);
	return 0;
}

void Enemy::Collision(float deltaTime)
{
	MoveObj::Collision(deltaTime);
}

void Enemy::Render(HDC hdc, float deltaTime)
{
	MoveObj::Render(hdc, deltaTime);
	DrawRect(hdc);
}

Enemy* Enemy::Clone()
{
	return new Enemy(*this);
}
