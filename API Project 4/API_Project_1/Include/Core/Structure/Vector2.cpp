#include "Vector2.h"

void Vector2::SetPos(double _x, double _y)
{
	x = _x;
	y = _y;
}

double Vector2::Length()
{
	return sqrt(x * x + y * y);
}

Vector2 Vector2::Normalize()
{
	double len = Length();
	if (len == 0)
	{
		return Vector2(0, 0);
	}
	return Vector2(x / len, y / len);
}

double Vector2::Dot(Vector2& v1, Vector2& v2)
{
	return (v1.x * v2.x) + (v1.y * v2.y);
}