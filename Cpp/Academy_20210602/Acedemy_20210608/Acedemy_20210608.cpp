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


	////2. 10명의 학생 성적을 입력,배열에 저장하고 총점과 평균을 구해봐라
	//int score[10];
	//int sum = 0;
	//int totalStudentCount;
	//cin >> totalStudentCount;
	//for (size_t i = 0; i < totalStudentCount; i++)
	//{
	//	cout << "내가 입력한 학생의 점수는? : " << endl;
	//	cout << i + 1 << "번쨰 학생 : ";
	//	cin >> score[i];
	//	sum += score[i];
	//}

	//cout << "총점 : " << sum << " 평균 : " << sum / totalStudentCount << endl;

	

	//인풋을 받아서 입력받은 숫자의 구구단 계산 결과를 배열에 저장하고 출력해라

	int guguArr[9] = { 0, };
	int inputNum = 0;

	cout << "구구단을 계산할 수를 입력해라!!!" << endl;
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