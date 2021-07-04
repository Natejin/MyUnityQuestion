#pragma once
#include "MonoBehavior.h"

class MoveObj :public MonoBehavior
{
private:




protected:

	double speed;

	MoveObj();
	MoveObj(const MoveObj& obj);
	virtual ~MoveObj();
public:
	void SetSpeed(double speed) { this->speed = speed; }
	double GetSpeed() { return speed; }
public:
	void Translate(double x, double y);
	void Translate(double x, double y, float deltaTime);
	void Translate(const Vector2& vec);
	void Translate(const Vector2& vec, float deltaTime);

	void TranslateX(double x);
	void TranslateX(double x, float deltaTime);


	void TranslateY(double y);
	void TranslateY(double y, float deltaTime);

	void TranslateXInTime(float deltaTime, MOVE_DIR dir);
	void TranslateYInTime(float deltaTime, MOVE_DIR dir);

	void TranslateAngle(); //TODO 회전함수 추후 벡터로 변경
	void TranslateAngle(float deltaTime);

public:
	virtual bool Enable();
	virtual bool Disable();
	virtual bool Init() = 0;
	virtual void Input(float deltaTime);
	virtual int Update(float deltaTime);
	virtual int LateUpdate(float deltaTime);
	virtual void Collision(float deltaTime);
	virtual void Render(HDC hdc, float deltaTime);
	virtual MoveObj* Clone() = 0;
};

