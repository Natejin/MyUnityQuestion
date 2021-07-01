#include "Vector2.h"

void Vector2::SetPos(double _x, double _y)
{
    x = _x;
    y = _y;
}

float Vector2::Length()
{
	return sqrt(x * x + y * y);

}

Vector2 Vector2::Normalize()
{
	float len = Length();
	return Vector2(x / len, y / len);
}
float Vector2::Dot(Vector2& v1, Vector2& v2)
{
	return (v1.x * v2.x) + (v1.y * v2.y);
}
