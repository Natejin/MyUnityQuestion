#pragma once
#include "Obj.h"


class MonoBehavior : public Obj
{
public:
	Vector2 pos;
	Vector2 size;
	Vector2 speed;

	bool isRender = true;

	virtual void Render(HDC hdc) {};
	MonoBehavior() {};
	MonoBehavior(double posX, double posY, double sizeX, double sizeY, double speedX, double speedY) 
		:pos(Vector2(posX, posY)),size(Vector2(sizeX,sizeY)),speed(Vector2(speedX,speedY))
	{
	
	};
	MonoBehavior(Vector2 pos, Vector2 size, Vector2 speed) 
		:pos(pos), size(size), speed(speed)
	{
	
	};



	void DrawRect(HDC hdc);
	void DrawRect(HDC hdc, Color rgb);
	bool CheckCollision(MonoBehavior t2);
};


