// Academy_20210611_1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

int main()
{
	//int num = 20;
	//int *ptr1 = &num;
	//int *ptr2;
	//ptr2 = (int*)malloc(sizeof(int)); //c 스타일 메모리 동적할당
	//free(ptr2); //메모리해제

	////쓰면 반드시 반환하라고!!! 안그러면 메모리 누수현상이 일어난다 오예

	//*ptr2 = 30; //메모리 할당에 실패할경우가 있기 때문에 경고표시
	//cout << *ptr2 << endl;

	////동적할당을하면 반드시 메모리를 반환해야한다.
	//if (ptr2!=NULL) //if문으로 할당했는지 확인
	//{
	//	*ptr2 = 4;
	//	cout << *ptr2 << endl;
	//}

	////c++에서는 new와 delete를 쓴다.
	//int* pNum = new int;

	//delete pNum;
	////delete pNum; //지웠기때문에 경고만 줌 

	char* pChar = new char;
	*pChar = 'a';
	cout << "memory address : " << (void*)pChar << " 값 : " << *pChar << endl;
	cout << "힙에 할당된 크기 : " << sizeof(*pChar) << endl;

	//int** arr = new int[10][5]; //ㄴㄴ
	//int(*arr)[5] = new int[10][5];

	auto arr = new int[10][5];

	cout << "memory address : " << (void*)arr << " 값 : " << *arr << endl;
	cout << "힙에 할당된 크기 : " << sizeof(*arr) << endl;
	cout << "힙에 할당된 크기 : " << sizeof(arr) << endl;

	int* pArrInt = new int[2];
	delete[] pArrInt;

	//new는 연산자
	//meallo 는 함수

	//meallo는 리턴값이 void 라서 자료형을 알아야함
	//new는 return이 타입이기떄문에 별도의 자료 변형이 필요없다.

	//meallo 생성자 호출 기능이없다.
	//meallo 재할당 가능

	//new는 할당된크기에 대한 재할당이 안됨


	//free는 소멸자가 없다.
	//delete 소멸자를 호출

}
