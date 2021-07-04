#include "Player.h"
#include "Projectile.h"

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

	SetPos(Vector2(0, 0));
	SetSize(Vector2(395, 500));
	SetPivot(Vector2(0.5, 1));
	SetSpeed(400);

	SetSprite("Player", TEXT("TestPic.bmp"));
	return true;
}

void Player::Input(double deltaTime)
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

int Player::Update(double deltaTime)
{
	//for (GameObject& attack : components)
	//{
	//	attack.Update(deltaTime);
	//}
	Unit::Update(deltaTime);
	return 0;
}

int Player::LateUpdate(double deltaTime)
{
	Unit::LateUpdate(deltaTime);
	return 0;
}

void Player::Collision(double deltaTime)
{
	Unit::Collision(deltaTime);
}

void Player::Render(HDC hdc, double deltaTime)
{
	Unit::Render(hdc, deltaTime);

	//DrawRect(hdc);

}

Player* Player::Clone()
{
	return new Player(*this);
}
void Player::Fire()
{
	Projectile* pBullet = (Projectile*)MonoBehavior::CreateClone(TAG::Projectile, TAG::Projectile, m_pLayer);
	
	Vector2 posFire = pos;
	posFire.x += scale.x * 0.5f;
	posFire.y -= scale.y * 0.5f;
	pBullet->SetPos(posFire);
	pBullet->Init();
	SAFE_RELEASE(pBullet);
}

