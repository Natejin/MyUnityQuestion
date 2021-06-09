// Acedemy_20210609_Pointer_2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

//값에 의한 전달 -> call by value
int Sum(int a, int b) {
	return a + b;
}
//
//
//int pSum(int* a, int* b) {
//	return a + b;
//}

void Print(int n) {
	cout << "====Print함수====" << endl;
	n = 10;
	cout << "n의 값		: " << n << endl;
	cout << "n의 주소값	: " << &n << endl;
	cout << endl;

}
//참조에 의한 전달 -> call by reference
//c스타일
void Address(int* n) {
	*n = 10;
	cout << "====Adress함수====" << endl;
	cout << "*n의 값		: " << *n << endl;
	cout << " n의 값	: " << n << endl;
	cout << "&n의 값	: " << &n << endl;
	cout << endl;
}

//참조에 의한 전달 -> call by reference
//c++ 스타일
void Reference(int& n) {
	n = 10;
	cout << "====Reference함수====" << endl;
	cout << "n의 값		: " << n << endl;
	cout << "&n의 값	: " << &n << endl;
	cout << endl;
}

//참조방식
//&는 주소를 반환하는 연산자가 아님
//참조는 변수의 별명 -> 스왑하려는 메모리를 공유한다.
//즉 별명이 바뀌면 (참조자) 참조하는 변수의 값이 변경된다.
void SwapReference(int& a, int& b) {
	int pa = a;
	a = b;
	b = pa;
}

//주소방식
void SwapAddress(int* a, int* b) {
	int pa = *a;
	*a = *b;
	*b = pa;
}
int main()
{
	int n = 30; 
	Print(n); //n = num 형태를 복사
	cout << "====메인함수====" << endl;
	cout << "n의 값		: " << n << endl;
	cout << "n의 주소값	: " << &n << endl<<endl;

	Address(&n); //n = num 형태를 복사
	cout << "====메인함수====" << endl;
	cout << "n의 값		: " << n << endl;
	cout << "n의 주소값	: " << &n << endl << endl;

	Reference(n); //n = num 형태를 복사
	cout << "====메인함수====" << endl;
	cout << "n의 값		: " << n << endl;
	cout << "n의 주소값	: " << &n << endl << endl;

	int a = 3;
	int b = 5;

	cout << "Swap 하기전 값" << endl;
	cout << "a, b => " << a << "," <<b << endl << endl;
	SwapAddress(&a, &b);
	cout << "Swap 하고난이후 값" << endl;
	cout << "a, b => " << a << "," << b << endl << endl;
	SwapReference(a, b);
	cout << "Swap 하고난이후 값" << endl;
	cout << "a, b => " << a << "," << b << endl << endl;


	//1.	call by value, call by reference 차이점
	//2.	빙고 만들기


}

