// Acedemy_20210608.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
	//int arr[4] = { 10,20,30,40 };
	//cout << arr << endl;
	//cout << &arr[0] << endl;
	//cout << &arr[1] << endl;
	//cout << &arr[2] << endl;
	//cout << &arr[3] << endl;


	////1.A B C -> ABCCBA
	//char source[3] = { 'A', 'B', 'C' };
	//char source1[6] = {};
	//string tempStr = "      ";
	//for (size_t i = 0; i < 6; i++)
	//{
	//	if (i < 3)
	//	{
	//		source1[2 - i] = source[i];
	//		cout << source[i] << " ";
	//	}
	//	else {
	//		cout << source1[i - 3] << " ";
	//	}
	//}

	//for (size_t i = 0; i < 3; i++)	tempStr[i] = tempStr[5 - i] = source[i];
	//cout << tempStr << " ";


	////2. 10���� �л� ������ �Է�,�迭�� �����ϰ� ������ ����� ���غ���
	//int score[10];
	//int sum = 0;
	//int totalStudentCount;
	//cin >> totalStudentCount;
	//for (size_t i = 0; i < totalStudentCount; i++)
	//{
	//	cout << "���� �Է��� �л��� ������? : " << endl;
	//	cout << i + 1 << "���� �л� : ";
	//	cin >> score[i];
	//	sum += score[i];
	//}

	//cout << "���� : " << sum << " ��� : " << sum / totalStudentCount << endl;

	

	//��ǲ�� �޾Ƽ� �Է¹��� ������ ������ ��� ����� �迭�� �����ϰ� ����ض�

	int guguArr[9] = { 0, };
	int inputNum = 0;

	cout << "�������� ����� ���� �Է��ض�!!!" << endl;
	cin >> inputNum;
	for (size_t i = 0; i < 9; i++)
	{
		guguArr[i] = inputNum * (i + 1);
	}

	for (size_t i = 0; i < 9; i++)
	{
		printf("%d * %d = %d\n", inputNum, i + 1, guguArr[i]);
	}

}