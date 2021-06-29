#pragma once
#include "MonoBehavior.h"

class RectMonoBehavior : public MonoBehavior
{
public:
	Rect* rc;



	int signal = 0;
	bool isKinetic; //�浹�� �������� �������� Ȯ�ο���
	bool isCollision; //�浹����
	bool isGravity; //�߷¿���
	bool onGround; //������ ����
	//bool onGround1; //������ ����
	
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

