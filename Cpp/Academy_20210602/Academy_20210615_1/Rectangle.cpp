#include "Rectangle.h"

Rectangle::Rectangle()
	: width(0),height(0)
{
	std::cout << "�ڽ� ������ ȣ��" << std::endl;
}

Rectangle::Rectangle(const int x, const int y, const int w, const int h)
//�Ӹ��κ�
	:Shape(x,y),width(w),height(h)
{
	std::cout << "�ڽ� ������ ȣ��(�Ű�����)" << std::endl;
	//Shape(x,y)->Rectangle Ŭ�������� Shape�� ������()�߿��� �Ű������� �ִ� ������ ȣ��

}

Rectangle::~Rectangle()
{
	std::cout << "�ڽ� �Ҹ��� ȣ��" << std::endl;
}
