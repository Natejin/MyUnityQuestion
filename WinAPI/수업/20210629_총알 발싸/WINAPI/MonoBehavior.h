#pragma once
#include "PoolableObject.h"
#include "framework.h"

class MonoBehavior : public PoolableObject
{
public:
	Vector2 pos;
	Vector2 size;
	Vector2 speed;

	bool isActivate = true;


	MonoBehavior() {};
	MonoBehavior(int instanceID, int classID) :PoolableObject(instanceID, classID) {  }
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


	//ų��
	virtual void Enable() ;
	//�����ǰ� ����
	virtual void Start() ;
	//������Ʈ
	virtual void Update() ;
	//������Ʈ
	virtual void LateUpdate();
	//����
	virtual void Disable() ;




	virtual void Render(HDC hdc) {};


};


