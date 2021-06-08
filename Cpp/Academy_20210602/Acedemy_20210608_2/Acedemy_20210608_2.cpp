// Acedemy_20210608_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;


int main()
{
	int	arr[4][3];
	arr[0][0] = 1;
	arr[0][1] = 2;
	arr[0][2] = 3;

	arr[1][0] = 4;
	arr[1][1] = 5;
	arr[1][2] = 6;

	arr[2][0] = 7;
	arr[2][1] = 8;
	arr[2][2] = 9;

	arr[3][0] = 10;
	arr[3][1] = 11;
	arr[3][2] = 12;
	for (size_t i = 0; i < 4; i++)
	{
		cout << i << "행 출력결과 : " << arr[i][0] << "," << arr[i][1] << "," << arr[i][2] << endl;
	}
	
	int array1[4][3] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	int array2[4][3] = { 1,2,3,4,5};


	for (size_t i = 0; i < 4; i++)
	{
		cout << endl;
		for (size_t j = 0; j < 3; j++)
		{
			cout << array1[i][j] << " ";
		}
	}
	cout << endl;

	for (size_t i = 0; i < 4; i++)
	{
		cout << endl;
		for (size_t j = 0; j < 3; j++)
		{
			cout << array2[i][j] << " ";
		}
	}
	cout << endl;
	cout << endl;
	int  arr5[3][3];
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			cout << "아파트 " << i + 1 << "층 " << j + 1 << "호 에 살고있는사람 : ";
			cin >> arr5[i][j];
		}
	}

	int totalPeople = 0;
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			totalPeople += arr5[i][j];
		}
	}
	cout << "아파트에 살고있는 사람은 총 " << totalPeople << "명 입니다.";
}
