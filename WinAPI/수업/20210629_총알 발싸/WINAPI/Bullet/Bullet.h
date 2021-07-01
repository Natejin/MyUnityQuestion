#pragma once
#include "../MonoBehavior.h"

class Bullet : public MonoBehavior
{
public:
	double damage;
	bool Hitted;

public:
	Bullet();
	Bullet(int instanceID, int classID) :MonoBehavior(instanceID, classID){  }
	Bullet(double posX, double posY, double sizeX, double sizeY, double speedX, double speedY, double damage);
	Bullet(Vector2 pos, Vector2 size, Vector2 speed, double damage);
	~Bullet();


	

	void Initiate(double posX, double posY, double sizeX, double sizeY, double speedX, double speedY, double damage);
	bool isFire;
	void bulletMove();
	virtual void Render(HDC hdc);


	//킬때
	virtual void Enable();
	//생성되고 난후
	virtual void Start();
	//업데이트
	virtual void Update();
	//끌때
	virtual void Disable();
};

