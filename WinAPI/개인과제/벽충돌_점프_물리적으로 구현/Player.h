#pragma once
#include "RectMonoBehavior.h"

class Player : public RectMonoBehavior
{

public:
	double  jumpPower = 10;
	bool isJump;
	//bool isHighlight;
	double speed = 5;
	double acceclete = 1;
	//bool onGround;

	Vector2 groundCheckSize;
	Vector2 groundCheckPos;
	Vector2 input;
	Rect* groundChecker;

public:
	Player();
	Player(double x, double y, double width, double height, double jumpPower = 10);
	~Player() {};

	bool CheckOnground(Rect* another);
	virtual void init();
	virtual void init(double x, double y, double width, double height, double jumpPower = 10);
	virtual void update();
	virtual void release();
	//virtual void render(HDC* hdc);
};



