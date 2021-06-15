#pragma once

#include "Shape.h"


class Rectangle : public Shape
{
private:
		int width, height;
public:
	Rectangle();
	Rectangle(const int x, const int y, const int w, const int h);
	~Rectangle();
};

