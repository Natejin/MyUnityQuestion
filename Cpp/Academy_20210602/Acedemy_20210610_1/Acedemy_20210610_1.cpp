#include<iostream>

using namespace std;

int main() {
	/*
	요론게 잇다는 것만 알아둬라
	보이드 포인터파고들면 매우어렵 책한권나옴
	요론게 있다는것만 간단하게 찍먹 해보자
	*/

	//void //공허행 아무것도 없어

	//int* p;
	//자료형이 없는 포인터 변수다.
	//자료형에 제약을 받지않고 아무런 자료형의 주소를 저장가능




	int num = 10;

	////int형 포인터 변수
	//int* pNum = &num;

	////int형 포인터 변수
	//int** ppNum = &pNum;

	//cout << "num :\t" << num << endl;
	//cout << "pNum :\t" << pNum << endl;
	//cout << "ppNum :\t" << ppNum << endl;



	//int a = 3;
	//int* pa = &a;
	//int** ppa = &pa;

	//cout << "a :\t" << a << endl;
	//cout << "&a :\t" << &a << endl;
	//cout << "pa :\t" << pa << endl;
	//cout << "&pa :\t" << &pa << endl;
	//cout << "*pa :\t" << *pa << endl;
	//cout << "*ppa :\t" << *ppa << endl;
	//cout << "&ppa :\t" << &ppa << endl;
	//cout << "ppa :\t" << ppa << endl;
	//cout << "**ppa :\t" << **ppa << endl;



	int a = 10;
	int* pa = &a;

	int A = 10;
	void* pA = &A;

	cout << *(int*)pA << endl;





	int c = 3;
	double d = 3.1;

	void* vp = nullptr;
	vp = &c;//c의 주소값을 대입
	cout << "vp의 주소값 : " << vp << endl;


	//*vp = 1; 오류뜸 주소만 저장이가능해서
	//역참조를 때려도 값을 저장하거나 변경할수없다.
	//하지만 ....ㅋ
	//int a = 1;
	//int* p = &a;//*p = 3;
	//cout << *p << endl;

	//cout <<*vp<<endl; 이건오류남
	cout << *(int*)vp << endl;//ㅋㅋㅋㅋㅋㅋ 이건됌
	//3이나옴 vp에 대해서 강제 형변환했음
	//1.(int*)vp->vp의 주소를 int형 주소로 강제 형변환
	//2. 앞에 *-> 강제 형변환된 주소에 저장된 값을 참조

	*(int*)vp = 5;
	//강제형변환후 대입

	cout << *(int*)vp << endl;
	//우앙되넹

	//모든 자료형의 주소를 저장할수잇는 자유로운 포인터 변수
	//보이드형 포인터를 통해 주소가 아닌 값을 참조할수는 없지만 참조하려면 강제 형변환을 해야한다.


}