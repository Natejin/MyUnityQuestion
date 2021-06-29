#pragma once
#include "MonoBehavior.h"

class RectMonoBehavior : public MonoBehavior
{
public:
	Rect* rc;



	int signal = 0;
	bool isKinetic; //충돌시 고정인지 유동인지 확인여부
	bool isCollision; //충돌여부
	bool isGravity; //중력여부
	bool onGround; //땅위에 있음
	//bool onGround1; //땅위에 있음
	
	Color rgb;

	Vector2 previousMove;
	Vector2 currentlySpeed;
	Vector2Bool checkCollision;
	RectMonoBehavior* collisionTarget = nullptr;

	RectMonoBehavior();
	RectMonoBehavior(double	x, double y, double width, double height);
	~RectMonoBehavior() {};

	virtual void Update();
	virtual void Release();
	virtual void Init();
	virtual void Init(double x, double y, double width, double height);
	virtual void Render(HDC* hdc);
	bool CheckIntersectAndEdit(RectMonoBehavior* rect);

	bool CheckIntersect(RectMonoBehavior* rect);
	void Translate(Vector2 move);
	void Translate(double x, double y);
	void Translate();
	void SetPos(Vector2 newPos);
	void SetPos(double x, double y);
	void RedoTranslate();
	void Render(HDC hdc);
};

