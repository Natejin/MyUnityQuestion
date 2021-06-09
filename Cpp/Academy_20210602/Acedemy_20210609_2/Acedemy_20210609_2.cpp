// Acedemy_20210609_2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

//구조체 : 하나이상의 변수를 묶어 그룹화 하는 사용자 정의 자료형

//매개변수 타입이 구조체나 클래스면 참조자로 넘겨주기
//c		=> *
//c++	=> &

//클래스 구조체 차이 접근제한 캡슐화
//구조체 접근제한 무조건 public
//클래스 접근제한이 3개로 나뉘어짐
//1. private
//2. internal
//3. public

struct MyStruct {
	enum class COLOR {
		RED, BLACK
	};
	void Print();
	int a;
	int b;
	float c;
	double d;
	char name[20];
	string phoneNumber;


};



struct Point {
	int x;
	int y;
	void Print();
} p1, p2;

int main()
{
	Point p;
	p.Print();

	//구조체를 이용하여 자기 가족관계 만들기
	Family father;
	father.name = "하재호";
	father.age = 57;
	father.isMan = (bool)GENDER::MAN;

	Family mother;
	mother.name = "박미숙";
	mother.age = 57;
	mother.isMan = (bool)GENDER::WOMAN;

	Family me;
	me.name = "하진태";
	me.age = 31;
	me.isMan = (bool)GENDER::MAN;
}

enum class GENDER { WOMAN, MAN };

struct Family {
	string name;
	int age;
	bool isMan;
};

void Point::Print() {
	cout << "point의 구조체" << endl;
}