#include "GroundBlock.h"

GroundBlock::GroundBlock()
	:RectMonoBehavior()
{
	//RectMonoBehavior::init();
}


GroundBlock::GroundBlock(double x, double y, double width, double height, Vector2 baseSpeed, Vector2 randomSpeed)
	:RectMonoBehavior(x, y, width, height), baseSpeed(baseSpeed), resetPos(x,y), randomSpeed(randomSpeed)
{
	this->moveSpeed.SetRandomVector(baseSpeed, randomSpeed);
	rgb.Random(125);
}

void GroundBlock::init(double x, double y, double width, double height, Vector2 baseSpeed, Vector2 randomSpeed)
{
	RectMonoBehavior::init(x, y, width, height);

	this->moveSpeed.SetRandomVector(baseSpeed, randomSpeed);
	this->baseSpeed = baseSpeed;
	this->randomSpeed = randomSpeed;
}

void GroundBlock::update()
{
	RectMonoBehavior::update();
	if (rc->x < 0)
	{
		rc->SetPos(Vector2((double)WINSIZEX, rc->y));
		if ((int)randomSpeed.x == 0)
		{
			moveSpeed.x = (baseSpeed.x);
		}
		else {
			moveSpeed.x = (baseSpeed.x + rand() % (int)randomSpeed.x);
		}
	}

	if (rc->y  > (double)WINSIZEY || rc->y  < 0)
	{

		int randNum = rand() % 2;
		if (randNum == 1)
		{
			moveSpeed.y = -(baseSpeed.y + rand() % (int)randomSpeed.y);
			rc->SetPos(Vector2(rc->x, (double)WINSIZEY));
		}
		else {
			moveSpeed.y = baseSpeed.y + rand() % (int)randomSpeed.y;
			rc->SetPos(Vector2(rc->x, 0));
		}
		rgb.Random(125);
	}
	previousMove = previousMove + moveSpeed;
}
