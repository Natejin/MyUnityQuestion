#include "UsefulFunction.h"


template<typename T>
std::vector<T>* UsefulFunction::Shuffle(std::vector<T>* vec, int size)
{
	std::vector<T>* Shuffle(std::vector<T>*vec, int size);
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
}

void UsefulFunction::DrawRect(HDC hdc, RECT rc)
{
	Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom);
}

void UsefulFunction::DrawRect(HDC hdc, RECT rc, Color rgb)
{
	HBRUSH brush = CreateSolidBrush(RGB(rgb.r, rgb.g, rgb.b));
	Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom);
	FillRect(hdc, &rc, brush);
	DeleteObject(brush);
}

