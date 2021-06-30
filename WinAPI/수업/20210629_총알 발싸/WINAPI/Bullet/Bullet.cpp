#include "Bullet.h"

Bullet::Bullet()
{

}

Bullet::Bullet(double posX, double posY, double sizeX, double sizeY, double speedX, double speedY)
	:MonoBehavior( posX,  posY, sizeX,  sizeY,  speedX,  speedY)
{

}

Bullet::Bullet(Vector2 pos, Vector2 size, Vector2 speed)
	:MonoBehavior(pos,size,speed)
{
	
}

Bullet::~Bullet()
{
}

void Bullet::bulletMove()
{
	pos += speed;
}

void Bullet::Render(HDC hdc)
{
	if (isRender)
	{
	
		HBRUSH hbr;
		hbr = CreateSolidBrush(RGB(0, 255, 0));
		HBRUSH hbrOld;
		hbrOld = (HBRUSH)SelectObject(hdc, hbr); 	// 기존 브러쉬 선택 
		Rectangle(hdc, int(pos.x - size.x), int(pos.y - size.y), int(pos.x + size.x), int(pos.y + size.y ));
		Ellipse(hdc, int(pos.x - size.x), (int)(pos.y - size.y), int(pos.x + size.x * 2), int(pos.y + size.y));
		hbr = (HBRUSH)::SelectObject(hdc, hbrOld);
		DeleteObject(hbr); 	// 생성한 브러쉬 삭제
	}

}

