#include "Shape.h"

Shape::Shape()
	:x(0),y(0)
{
	std::cout << "�θ� ������ ȣ��!!!" << std::endl;
}

Shape::Shape(const int xloc, const int yloc)
	:x(xloc),y(yloc)
{
	std::cout << "�θ� ������ ȣ��(�Ű�����)!!!" << std::endl;
}

Shape::~Shape()
{
	std::cout << "�θ� �Ҹ��� ȣ��!!!" << std::endl;
}
