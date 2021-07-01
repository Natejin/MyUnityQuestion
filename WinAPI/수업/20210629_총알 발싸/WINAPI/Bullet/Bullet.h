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


	//ų��
	virtual void Enable();
	//�����ǰ� ����
	virtual void Start();
	//������Ʈ
	virtual void Update();
	//����
	virtual void Disable();
};

