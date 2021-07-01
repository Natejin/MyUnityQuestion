#include "MonoBehavior.h"


void MonoBehavior::DrawRect(HDC hdc)
{
	if (isActivate)
	{
		Rectangle(hdc, int(pos.x - size.x), int(pos.y - size.y), int(pos.x + size.x), int(pos.y + size.y));
	}
}

void MonoBehavior::DrawRect(HDC hdc, Color rgb)
{
	if (isActivate)
	{
		HBRUSH hbr;
		hbr = CreateSolidBrush(RGB(0, 255, 0));
		HBRUSH hbrOld;
		hbrOld = (HBRUSH)SelectObject(hdc, hbr); 	// 기존 브러쉬 선택 
		Rectangle(hdc, int(pos.x - size.x), int(pos.y - size.y), int(pos.x + size.x), int(pos.y + size.y));
		hbr = (HBRUSH)::SelectObject(hdc, hbrOld);
		DeleteObject(hbr); 	// 생성한 브러쉬 삭제
	}

}



//충돌 체크
bool MonoBehavior::CheckCollision(MonoBehavior t2) {
	bool x;
	bool y;
	if (pos.x - size.x <= t2.pos.x + t2.size.x &&
		t2.pos.x - t2.size.x <= pos.x + size.x)
	{
		x = true;
	}
	else {
		x = false;
	}

	if (pos.y - size.y <= t2.pos.y + t2.size.y &&
		t2.pos.y - t2.size.y <= pos.y + size.y)
	{
		y = true;
	}
	else {
		y = false;
	}
	return x && y;
}

void MonoBehavior::Enable()
{

}

void MonoBehavior::Start()
{

}

void MonoBehavior::Update()
{
	if (!isActivate) return;
}

void MonoBehavior::LateUpdate()
{

}

void MonoBehavior::Disable()
{

}
