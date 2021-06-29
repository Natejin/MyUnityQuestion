#pragma once
#include "../../RectMonoBehavior.h"

class GroundBlock : public RectMonoBehavior
{
public:

	Vector2 baseSpeed;
	Vector2 randomSpeed;
	Vector2 moveSpeed;
	Vector2 resetPos;
public:
	GroundBlock();
	GroundBlock(double x, double y, double width, double height, Vector2 baseSpeed, Vector2 randomSpeed);

	//virtual void init();
	virtual void Init(double x, double y, double width, double height, Vector2 baseSpeed, Vector2 randomSpeed);
	virtual void Update();
	//virtual void release();
	//virtual void render(HDC* hdc);

};

