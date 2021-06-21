#include "..\Academy_20210614_1\Student.h"
// Academy_20210611_2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;


//struct의 default는 private
struct Circle1 {

	int radius;
	string color;

	double calculationArea() {
		return 3.14 * radius * radius;
	}

	Circle1() {}; //생성자 : 클래스가 메모리에 할당이 될때 자동 호출
	~Circle1() {}; //소멸자 : 클래스가 메모리에서 할당해제될때 자동 호출
};


//class의 default는 private
class Circle {
private:
	int radius;
	string color;

public:
	//사용자가 정의 하지않으면 컴파일 할때 자동으로 내용이 없는 빈 생성자를 제공한다(디폴트 생성자)
	//반환값이 없고 클래스 이름이랑 동일해야한다
	//반드시 public이여야한다 그이유는 외부에서 참조해야 하기때문에 ..
	//보통 멤버 변수를 초기화 할때 사용
	//생성자도 함수이기때문에 오버로딩이 가능하다.

	Circle() {}; //생성자 : 클래스가 메모리에 할당이 될때 자동 호출
	~Circle() {}; //소멸자 : 클래스가 메모리에서 동적할당해제될때 자동 호출
};

/*
private : 클래스 내부에서만 참조 가능한 지정자 (정보 은닉성)
-숨겨야할 멤버 변수등을 이곳에 사용한다.
-클래스의 디폴트

public : 외부에서 자유롭게 참조할수있다.
-외부에서 직접적으로 멤버를 조작할수있기떄문에 공개할 기능들은 이곳에 사용한다.

protected : 클래스내부와 상속관계에 있는 클래스에서만 접근이 가능하다.

접근제어			클래스내부		클래스외부		상속클래스
private				O				x				x
protected			O				X				O
public				O				O				O

*/


class Student {
	int a;
	int b;
	int age;

public: 

	void printOn() { cout << "스튜던트 클래스의 프린트 함수" << endl; };
	void printOff() { cout << "스튜던트 클래스의 프린트 함수" << endl; };
	void print(int _a, int _b) {
		a = _a;
		b = _b;
		cout << a << "," << b << endl;
	};
	void print(string str) { cout << str << endl; };

	
	int sum();
	int sum(int a, int b);
};


int Student::sum()
{
	return a + b;
}

int Student::sum(int a, int b) {
	return a + b;
}


//class Parent
//{
//public:
//	void Print() {
//		cout << "나는 부모" << endl;
//	}
//private:
//	int a;
//	int b;
//};
//
//class Child : public Parent
//{ 
//private:
//	int c;
//public:
//	void AnotherPrint() { 
//		cout << "나는 자식" << endl;
//	}
//};
//
//int main() {
//	Parent parent;
//	Child child;
//
//	child.Print(); //사용가능
//
//	parent.AnotherPrint(); //사용불가
//}

#include <iostream>
using namespace std;

class Parent {
private:
	int a;
protected:
	int b;
public:
	int c;
};

class Child : private Parent { //b,c맴버 변수는 private 맴버로 접근 범위 졻혀짐

};

class AnotherChild : protected Parent { //b,c맴버 변수는 public 맴버로 접근 범위 졻혀짐

};

class AnotherAnotherChild : public Parent { //b,c맴버 변수는 public 맴버로 접근 범위 졻혀짐

};


int main() {
	Child child;
	//a = private, b = private, c = private
	child.a; //사용불가
	child.b; //사용불가
	child.c; //사용불가

	AnotherChild anotherChild;
	//a = protected, b = protected, c = protected
	anotherChild.a;	//사용불가
	anotherChild.b;	//사용불가
	anotherChild.c;	//사용불가

	AnotherAnotherChild anotherAnotherChild;
	//a = public, b = public, c = public
	anotherAnotherChild.a;	//사용불가
	anotherAnotherChild.b;	//사용불가
	anotherAnotherChild.c;	//사용가능
}


//
//int main()
//{
//	Student s;
//	s.print(1, 2);
//	s.print("안녕");
//	cout << s.sum(3, 5) << endl;
//	cout << s.sum() << endl;
//
//	Student* s1 = new Student;
//
//	s1->print(1, 2);
//
//}
