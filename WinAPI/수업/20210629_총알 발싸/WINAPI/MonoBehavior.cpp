#include "MonoBehavior.h"


void MonoBehavior::DrawRect(HDC hdc)
{
	Rectangle(hdc, int(pos.x - size.x), int(pos.y - size.y), int(pos.x + size.x), int(pos.y + size.y));
}




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