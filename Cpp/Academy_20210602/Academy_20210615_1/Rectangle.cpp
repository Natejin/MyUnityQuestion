#include "Rectangle.h"

Rectangle::Rectangle()
	: width(0),height(0)
{
	std::cout << "자식 생성자 호출" << std::endl;
}

Rectangle::Rectangle(const int x, const int y, const int w, const int h)
//머리부분
	:Shape(x,y),width(w),height(h)
{
	std::cout << "자식 생성자 호출(매개변수)" << std::endl;
	//Shape(x,y)->Rectangle 클래스에서 Shape의 생성자()중에서 매개변수가 있는 생성자 호출

}

Rectangle::~Rectangle()
{
	std::cout << "자식 소멸자 호출" << std::endl;
}
