#include "DropingBlock.h"

DropingBlock::DropingBlock()
	:RectMonoBehavior()
{
	//RectMonoBehavior::init();
}


DropingBlock::DropingBlock(double x, double y, double width, double height, Vector2 baseSpeed, Vector2 randomSpeed)
	:RectMonoBehavior(x, y, width, height), baseSpeed(baseSpeed), resetPos(x, y), randomSpeed(randomSpeed)
{
	this->moveSpeed.SetRandomVector(baseSpeed, randomSpeed);
	rgb.Random(125);
}

void DropingBlock::Init(double x, double y, double width, double height, Vector2 baseSpeed, Vector2 randomSpeed)
{
	RectMonoBehavior::Init(x, y, width, height);

	this->moveSpeed.SetRandomVector(baseSpeed, randomSpeed);
	this->baseSpeed = baseSpeed;
	this->randomSpeed = randomSpeed;
}

void DropingBlock::Update()
{
	//RectMonoBehavior::update();

	if (rc->y > (double)WINSIZEY)
	{
		SetPos(RND->GetInt(100, WINSIZEX - 100), RND->GetInt(-500, -100));
		this->moveSpeed.SetRandomVector(baseSpeed, randomSpeed);
		//rc->SetPos(Vector2(RND->GetInt(300, WINSIZEX- 300), -RND->GetInt(100, 200)));
		//if ((int)randomSpeed.x == 0)
		//{
		//	moveSpeed.x = baseSpeed.x;
		//}
		//else {
		//	moveSpeed.x = RND->GetInt(baseSpeed.x, randomSpeed.x);
		//}
	}

	previousMove = moveSpeed;
}


