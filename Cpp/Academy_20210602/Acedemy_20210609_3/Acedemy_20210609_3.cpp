// Acedemy_20210609_3.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

//포인터변수 메모리주소를 저장했다가 해당주소를 간접적으로 접근하게 허락함
//포인터변수에는 일반적인 상수 저장불가


int main()
{
	system("cls");

	int num = 10;
	int* pnum = &num;
	//pnum = num의 주소값
	//&pnum = pnum의 주소값
	//*pnum 역참조 = num
	cout << "pnum  :" << pnum << endl;
	cout << "&pnum :" << &pnum << endl;
	cout << "*pnum :" << *pnum << endl;
	cout << "num   :" << num << endl;
	cout << "&num  :" << &num << endl;
	cout << endl;
	cout << endl;

	*pnum = 15;
	cout << "pnum  :" << pnum << endl;
	cout << "&pnum :" << &pnum << endl;
	cout << "*pnum :" << *pnum << endl;
	cout << "num   :" << num << endl;
	cout << "&num  :" << &num << endl;
	cout << endl;
	cout << endl;

	int** ppnum;
	ppnum = &pnum;

	cout << "ppNum  :" << ppnum << endl;
	cout << "*ppNum	:" << *ppnum << endl;




	//포인터변수 초기화
	int* ptr1 = nullptr;

	//뱅글러포인터;

	//int numArr[5] = { 1,2,3,4,5 };
	//int* pnumArr = &numArr[0];
	//cout << "pnumArr		:" << pnumArr << endl;
	//cout << "&pnumArr	:" << &pnumArr << endl;
	//cout << "*pnumArr	:" << *pnumArr << endl;
	//cout << "numArr		:" << numArr << endl;
	//cout << "&numArr		:" << &numArr << endl;
	//for (size_t i = 0; i < 5; i++)
	//{
	//	cout << "numArr["<< i <<"]	:" << numArr[i] << endl;
	//	cout << "&numArr["<< i <<"]	:" << &numArr[i] << endl;
	//}
	//cout << endl;
	//cout << endl;
	//*pnumArr << 1;
	//cout << "pnumArr		:" << pnumArr << endl;
}
