#pragma once
#include"singleton.h"
#include "Obj.h"
#include <vector>

struct Color;
class MonoBehavior;
class UsefulFunction :public SingleTon<UsefulFunction>
{
public:
	UsefulFunction() {};
	~UsefulFunction() {};
	
	template <typename T = Obj>
	std::vector<T>* Shuffle(std::vector<T>* vec, int size)
	{
		int dest, sour;
		for (size_t i = 0; i < 100; i++)
		{
			dest = RandomFunction::GetSingleTon()->GetInt(size);
			sour = RandomFunction::GetSingleTon()->GetInt(size);

			auto temp = vec[dest];
			vec[dest] = vec[sour];
			vec[sour] = temp;
		}
		return  vec;
	}

	static void DrawRect(HDC hdc, RECT rc)
	{
		Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom);
	}

	static void DrawRect(HDC hdc, RECT rc, Color rgb)
	{
		HBRUSH brush = CreateSolidBrush(RGB(rgb.r, rgb.g, rgb.b));
		Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom);
		FillRect(hdc, &rc, brush);
		DeleteObject(brush);
	}

	//static bool CheckCollision(MonoBehavior t1, MonoBehavior t2) {
	//	bool x;
	//	bool y;
	//	if (t1.pos.x left <= t2.right &&
	//		t2.left <= right)
	//	{
	//		x = true;
	//	}
	//	else {
	//		x = false;
	//	}

	//	if (t1.top <= t2->bottom &&
	//		t2->top <= t1.bottom)
	//	{
	//		y = true;
	//	}
	//	else {
	//		y = false;
	//	}
	//	return x && y;
	//}
};