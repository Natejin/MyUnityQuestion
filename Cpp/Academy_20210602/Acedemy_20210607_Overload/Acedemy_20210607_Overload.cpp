// Acedemy_20210607_Overload.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

//오버로딩 디폴트

void Print();
void Print(int a);
void Print(int a, int b = 19);
void Print(int a, int b, bool isCheck);


int sum(int a, int b);
int sum(int a, int b, int c, int d);
void Test();
void TestPrint();

int main()
{
	//Print();
	//Print(1);
	Print(5, 6);
	Print(10, 20, true);

	//숙제 : 함수에 대해서 조사
	// 디폴트 매개변수
}

void Print() {
	
}

void Print(int a) {

}
void Print(int a, int b) {

}
void Print(int a, int b, bool isCheck) {

}

int sum(int a, int b) {
	return a + b;

}


int sum(int a, int b, int c)
{
	return a + b + c;
}


int sum(int a, int b, int c, int d)
{
	return a + b + c + d;
}

void Test() {
	cout << "테스트 함수" << endl;
}

void TestPrint() {
	cout << "나는 테스트 프린트 함수" << endl;
	Test();
}

