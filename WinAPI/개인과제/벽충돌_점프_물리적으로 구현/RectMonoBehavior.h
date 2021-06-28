#pragma once
#include "MonoBehavior.h"

class RectMonoBehavior : public MonoBehavior
{
public:
	Rect* rc;
	int signal = 0;
	//int x, y;
	bool isKinetic; //충돌시 고정인지 유동인지 확인여부
	bool isCollision; //충돌여부
	bool isGravity; //중력여부
	bool onGround; //땅위에 있음
	bool onGround1; //땅위에 있음
	
	Color rgb;

	Vector2 previousMove;
	Vector2 currentlySpeed;
	Vector2Bool checkCollision;
	RectMonoBehavior* collisionTarget = nullptr;

	RectMonoBehavior();
	RectMonoBehavior(double	x, double y, double width, double height);
	~RectMonoBehavior() {};

	virtual void update();
	virtual void release();
	virtual void init();
	virtual void init(double x, double y, double width, double height);
	virtual void render(HDC* hdc);
	//bool CheckIntersectRect(RECT* rect);
	//bool CheckIntersectRect(Rect* rect);
	bool CheckIntersectRect(RectMonoBehavior* rect);
	void Translate(Vector2 move);
	void Translate(double x, double y);
	void Translate();
	void RedoTranslate();
};

