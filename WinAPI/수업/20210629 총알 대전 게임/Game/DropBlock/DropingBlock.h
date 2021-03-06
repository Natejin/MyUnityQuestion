#pragma once
#include "../../RectMonoBehavior.h"

class DropingBlock : public RectMonoBehavior
{
public:

	Vector2 baseSpeed;
	Vector2 randomSpeed;
	Vector2 moveSpeed;
	Vector2 resetPos;
public:
	DropingBlock();
	DropingBlock(double x, double y, double width, double height, Vector2 baseSpeed, Vector2 randomSpeed);

	virtual void Init(double x, double y, double width, double height, Vector2 baseSpeed, Vector2 randomSpeed);
	virtual void Update();

};