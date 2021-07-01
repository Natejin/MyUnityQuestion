#include "Obj.h"

Obj::Obj()
{
	
}

Obj::Obj(const Obj& obj)
{
	*this = obj;
}

Obj::~Obj()
{
}

bool Obj::Enable()
{
	return false;
}

bool Obj::Disable()
{
	return false;
}



void Obj::Input(float deltaTime)
{
}

int Obj::Update(float deltaTime)
{
	return 0;
}

int Obj::LateUpdate(float deltaTime)
{
	return 0;
}

void Obj::Collision(float deltaTime)
{
}

void Obj::Render(HDC hdc, float deltaTime)
{
}

void Obj::DrawRect(HDC hdc)
{
	Rectangle(hdc, int(pos.x - size.x), int(pos.y - size.y), int(pos.x + size.x), int(pos.y + size.y));
}

void Obj::DrawRect(HDC hdc, Color rgb)
{
	HBRUSH hbr;
	hbr = CreateSolidBrush(RGB(0, 255, 0));
	HBRUSH hbrOld;
	hbrOld = (HBRUSH)SelectObject(hdc, hbr); 	// 기존 브러쉬 선택 
	Rectangle(hdc, int(pos.x - size.x), int(pos.y - size.y), int(pos.x + size.x), int(pos.y + size.y));
	hbr = (HBRUSH)::SelectObject(hdc, hbrOld);
	DeleteObject(hbr); 	// 생성한 브러쉬 삭제
}
