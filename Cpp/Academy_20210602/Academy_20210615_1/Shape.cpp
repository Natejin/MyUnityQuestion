#include "Shape.h"

Shape::Shape()
	:x(0),y(0)
{
	std::cout << "부모 생성자 호출!!!" << std::endl;
}

Shape::Shape(const int xloc, const int yloc)
	:x(xloc),y(yloc)
{
	std::cout << "부모 생성자 호출(매개변수)!!!" << std::endl;
}

Shape::~Shape()
{
	std::cout << "부모 소멸자 호출!!!" << std::endl;
}
