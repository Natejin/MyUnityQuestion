#include "Player.h"

Player::Player()
{
}

Player::Player(const Player& obj)
:MoveObj(obj)
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
	return true;
}

void Player::Input(float deltaTime)
{
}

int Player::Update(float deltaTime)
{
	return 0;
}

int Player::LateUpdate(float deltaTime)
{
	return 0;
}

void Player::Collision(float deltaTime)
{
}

void Player::Render(HDC hdc, float deltaTime)
{
	DrawRect(hdc);
}
