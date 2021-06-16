#include<iostream>
#include<string>
using namespace std;

//��ȯ��  operator������(�Ű�����)
//{
//	
//}

/*

	+			operator+()
	-			operator-()
	/			operator/()
	*			operator*()

*/
class MyVector
{
private:
	double x, y;

public:
	MyVector(const double x = 0.0, const double y = 0.0):x(x),y(y){}

	string Print() {
		return "(" + to_string(x) + ", " + to_string(y) + ")";
	}
		MyVector operator+(const MyVector & v2);
};

MyVector MyVector::operator+(const MyVector& v2)
{
	MyVector v;
	v.x = this->x + v2.x;
	v.y = this->y + v2.y;

	return v;
}


class Time
{
private:
	int hour, min, sec;
public:
	Time(const int h = 0,const int m=0,const int s = 0 ):hour(h),min(m),sec(s){}

	bool operator==(Time& t2);
	bool operator!=(Time& t2);
};
bool Time::operator==(Time& t2)
{
	return (hour==t2.hour && min==t2.min && sec==t2.sec);
}

bool Time::operator!=(Time& t2)
{
	return !(*this==t2);
}

int main() {

	//�ߺ��Ҽ� ���� ������ �� �ȵǴ���?
	//

	MyVector v1(1.0, 2.0);
	MyVector v2(2.0, 4.0);
	MyVector v3 = v1 + v2;
	cout << v1.Print() << " + " << v2.Print() << " = " << v3.Print() << endl;


	Time t1(1, 2, 3);
	Time t2(1, 2, 3);
	cout << (t1 == t2) << endl;
}

