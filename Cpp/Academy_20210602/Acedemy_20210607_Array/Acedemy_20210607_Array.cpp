// Acedemy_20210607_Array.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

int main()
{
	int num[10];

	int num1 = 1;
	
	cout << num << endl; // 배열에서의 이름은 해당 배열의 시작 주소
	cout << num1 << endl;

	int arr2[5] = { 1 }; // 첫번째 인덱스만 초기화 해도 나머지 인덱스는 0으로 초기화

	for (size_t i = 0; i < 5; i++)
	{
		cout << arr2[i] << endl;
	}

	int arr3[] = { 1,2,3,4,5 };

	char name[2] = "1"; //문자열을 인식할떄 항상 +1 을 해야한다 이유 : 마지막에 NULL문자가 존재

	for (size_t i = 0; i < 10; i++)
	{
		cout << num[i]<< endl;
	}
	cout << "num의 크기 : " << sizeof(num) << "바이트" << endl;

	int intArrLen = sizeof(num) / sizeof(int);
	cout << "intArrLen 의 길이 : " << intArrLen << endl;

	int numArr[10];
	for (size_t i = 0; i < 10; i++)
	{
		numArr[i] = i + 1;
	}
	for (size_t i = 0; i < 10; i++)
	{
		cout << "numArr[" << i << "] : " << numArr[i] << endl;
	}
}
