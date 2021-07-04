#include "Enemy.h"
#include "../Core/Core.h"
#include "Projectile.h"

Enemy::Enemy(const Enemy& obj)
	:Unit(obj)
{
	currentlyDir = obj.currentlyDir;
	fireTime = obj.fireTime;
	fireLimitTime = obj.fireLimitTime;
}

Enemy::~Enemy()
{
}

Enemy::Enemy():
	fireTime(0.f),
	fireLimitTime(3.f)
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


int Enemy::Update(double deltaTime)
{
	Unit::Update(deltaTime);
	TranslateYInTime(deltaTime, currentlyDir);
	if (pos.y < scale.y )
	{
		currentlyDir = MOVE_DIR::FRONT;
	}
	else if(pos.y > Core::GetSingleton()->GetResolution().height - scale.y - 100){
	
		currentlyDir = MOVE_DIR::BACK;
	}
	fireTime -= deltaTime;
	if (fireTime < 0)
	{
		fireTime = fireLimitTime;
		Fire();
	}
	return 0;
}

int Enemy::LateUpdate(double deltaTime)
{
	Unit::LateUpdate(deltaTime);
	return 0;
}

void Enemy::Collision(double deltaTime)
{
	Unit::Collision(deltaTime);
}

void Enemy::Render(HDC hdc, double deltaTime)
{
	Unit::Render(hdc, deltaTime);
	DrawRect(hdc);
}

Enemy* Enemy::Clone()
{
	return new Enemy(*this);
}

void Enemy::Fire()
{
	Projectile* pBullet = (Projectile*)MonoBehavior::CreateClone(TAG::Projectile, TAG::Projectile, m_pLayer);
	pBullet->SetPos(pos);
	pBullet->Init();
	pBullet->SetSpeed(-400);
	SAFE_RELEASE(pBullet);
}
