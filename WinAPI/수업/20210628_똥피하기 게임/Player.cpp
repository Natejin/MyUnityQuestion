#include "Player.h"

Player::Player()
	:RectMonoBehavior(),isJump(false), jumpPower(jumpPower)
{
	//init();
}

Player::Player(double x, double y, double width, double height, double jumpPower)
	:RectMonoBehavior(x, y, width, height), isJump(false), jumpPower(jumpPower)
{
	isKinetic = false;
	isCollision = true;
	isGravity = true;
	groundCheckPos = Vector2(0, 10);
	groundCheckSize = Vector2(3, 3);
	rgb.Random(125);
	groundChecker = new Rect(groundCheckPos.x, 
		groundCheckPos.y, 
		groundCheckSize.x,
		groundCheckSize.y
		);
	
}

bool Player::CheckOnground(Rect* another) {
	groundChecker->SetPos(Vector2(rc->x + groundCheckPos.x, rc->y + groundCheckPos.y));
	/*if (groundChecker->Collided(another))
	{
		onGround = true;
	}
	else {
		onGround = false;
	}*/
	return onGround;
}


void Player::init()
{
	RectMonoBehavior::init();
}

void Player::init(double x, double y, double width, double height, double jumpPower)
{
	//rc = new Rect(x, y, width, height);
	RectMonoBehavior::init(x, y, width, height);
	this->jumpPower = jumpPower;
}




void Player::update()
{
	RectMonoBehavior::update();

	//if (InputManager->isStayKeyDown(VK_LEFT)) {
	//	previousMove += Vector2(-5, 0);
	//}
	





	if (InputManager->isStayKeyDown(VK_UP)) {
		previousMove += Vector2(0, -speed);
	}

	if (InputManager->isStayKeyDown(VK_DOWN)) {
		previousMove += Vector2(0, speed);
	};

	if (InputManager->isStayKeyDown(VK_RIGHT)) {
		if (input.x + acceclete< speed)
		{
			input.x += acceclete;
		}
		else {
			input.x = speed;
		}
	}else if (InputManager->isStayKeyDown(VK_LEFT)) {
		if (input.x - acceclete> -speed)
		{
			input.x -= acceclete;
		}
		else {
			input.x = -speed;
		}
	}
	else {
		if (input.x > 0.5)
		{
			input.x -= acceclete;
		}
		else if (-0.5 <= input.x && input.x <= 0.5){
			input.x = 0;
		}
		else 
		{
			input.x += acceclete;
		} 
	}

	if (InputManager->isStayKeyDown(VK_SPACE)) {
		if (onGround)
		{
			currentlySpeed.y = -jumpPower;
			onGround = !onGround;
		}
	}

	if (InputManager->isOnceKeyDown(VK_RETURN)) {
		previousMove = Vector2(0, 0);
		isGravity = !isGravity;
		currentlySpeed = Vector2(0, 0);
	}

	previousMove += input;

	if ((int)rc->x <= (int)rc->width)
	{
		rc->SetPos(rc->width, rc->y);
		//rc->x = rc->width;
	}
	else if (rc->x > (double)WINSIZEX - rc->width) {

		//rc->x = (double)WINSIZEX - rc->width;
		rc->SetPos(WINSIZEX - rc->width, rc->y);
	}


}

void Player::release()
{
	delete rc;
	delete groundChecker;
}