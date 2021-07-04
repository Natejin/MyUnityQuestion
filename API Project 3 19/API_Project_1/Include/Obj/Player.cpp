#include "Player.h"

Player::Player()
{
}

Player::Player(const Player& obj)
:Unit(obj)
{
}

Player::~Player()
{
}

bool Player::Enable()
{
	return true;
}

bool Player::Disable()
{
	return true;
}

bool Player::Init()
{

	SetPos(Vector2(200, 200));
	SetSize(Vector2(25, 25));
	SetSpeed(400);
	return true;
}

void Player::Input(float deltaTime)
{
	Unit::Input(deltaTime);

	if (INPUT->isStayKeyDown('W'))
	{
		TranslateYInTime(deltaTime, MOVE_DIR::BACK);
	}

	if (INPUT->isStayKeyDown('S'))
	{
		TranslateYInTime(deltaTime, MOVE_DIR::FRONT);
	}

	if (INPUT->isStayKeyDown('A'))
	{
		TranslateXInTime(deltaTime, MOVE_DIR::BACK);
	}

	if (INPUT->isStayKeyDown('D'))
	{
		TranslateXInTime(deltaTime, MOVE_DIR::FRONT);
	}

	if (INPUT->isOnceKeyDown(VK_SPACE))
	{
		Fire();
	}

	if (INPUT->isStayKeyDown('K'))
	{
		Fire();
	}
}

int Player::Update(float deltaTime)
{
	//for (GameObject& attack : components)
	//{
	//	attack.Update(deltaTime);
	//}
	Unit::Update(deltaTime);
	return 0;
}

int Player::LateUpdate(float deltaTime)
{
	Unit::LateUpdate(deltaTime);
	return 0;
}

void Player::Collision(float deltaTime)
{
	Unit::Collision(deltaTime);
}

void Player::Render(HDC hdc, float deltaTime)
{
	Unit::Render(hdc, deltaTime);

	DrawRect(hdc);

}

Player* Player::Clone()
{
	return new Player(*this);
}
void Player::Fire()
{
	MonoBehavior* pBullet = MonoBehavior::CreateClone(TAG::Projectile, TAG::Projectile, m_pLayer);
	pBullet->SetPos(pos);
	pBullet->Init();
	//pBullet->Init();
	SAFE_RELEASE(pBullet);
}

