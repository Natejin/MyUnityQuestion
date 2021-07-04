#include "Bullet.h"

Bullet::Bullet()
{

}

Bullet::Bullet(double posX, double posY, double sizeX, double sizeY, double speedX, double speedY, double damage)
	:MonoBehavior( posX,  posY, sizeX,  sizeY,  speedX,  speedY), damage(damage)
{

}

Bullet::Bullet(Vector2 pos, Vector2 size, Vector2 speed, double damage = 0)
	:MonoBehavior(pos,size,speed), damage(damage)
{
	
}

Bullet::~Bullet()
{
}

void Bullet::Initiate(double posX, double posY, double sizeX, double sizeY, double speedX, double speedY, double damage)
{
	pos.x = posX;
	pos.y = posY;
	size.x = sizeX;
	size.y = sizeY;
	speed.x = speedX;
	speed.y = speedY;
	this->damage = damage;
}



void Bullet::bulletMove()
{
	if (isActivate)
	{
		pos += speed;
	}
}

void Bullet::Render(HDC hdc)
{
	//if (isActivate)
	//{
	//
	//	HBRUSH hbr;
	//	hbr = CreateSolidBrush(RGB(0, 255, 0));
	//	HBRUSH hbrOld;
	//	hbrOld = (HBRUSH)SelectObject(hdc, hbr); 	// 기존 브러쉬 선택 
	//	Rectangle(hdc, int(pos.x - size.x), int(pos.y - size.y), int(pos.x + size.x), int(pos.y + size.y ));
	//	Ellipse(hdc, int(pos.x - size.x), (int)(pos.y - size.y), int(pos.x + size.x * 2), int(pos.y + size.y));
	//	hbr = (HBRUSH)::SelectObject(hdc, hbrOld);
	//	DeleteObject(hbr); 	// 생성한 브러쉬 삭제
	//}
	Rectangle(hdc, int(pos.x - size.x), int(pos.y - size.y), int(pos.x + size.x), int(pos.y + size.y));
	//Ellipse(hdc, int(pos.x - size.x), (int)(pos.y - size.y), int(pos.x + size.x * 2), int(pos.y + size.y));
}

void Bullet::Enable()
{
}

void Bullet::Start()
{
}

void Bullet::Update()
{
	MonoBehavior::Update();
}

void Bullet::Disable()
{
}

