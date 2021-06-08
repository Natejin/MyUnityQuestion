// Acedemy_20210608_3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string.h>
using namespace std;

enum Result {S = -3, B, N};

void BaseBallGame();
void SumArray();
void RotationArray();
void RotateMatrix(int** arr);

int main()
{
	bool isPlaying = true;
	while (isPlaying)
	{
		int gameIndex = 0;
		cout << "1: 야구게임, 2: 배열 행 열 총합 구하기, 3: 배열 회전시키기, 4: 프로그램 종료 " << endl;
		cin >> gameIndex;
		switch (gameIndex)
		{
		case 1:
			system("cls");
			BaseBallGame();
			break;
		case 2:
			system("cls");
			SumArray();
	
			break;
		case 3:
			system("cls");
			RotationArray();
	
			break;
		case 4:
			isPlaying = false;
			break;

		default:
			break;
		}
	}



}
void SumArray() {
	int arr1[20]{ 45,60,48,90,77,45,19,89,49,75,65,17,36,27,84,43,71,14,42,81 };
	int total = 0;
	int col[5] = {};
	int row[4] = {};
	for (size_t i = 0; i < 20; i++)
	{
		col[i / 5] += arr1[i];
		row[i % 4] += arr1[i];
		total += arr1[i];
	}

	for (size_t i = 0; i < 5; i++)
	{
		cout << "행 "<< i + 1 << "번쨰의 총합 : " << col[i] << endl;
	}

	for (size_t i = 0; i < 4; i++)
	{
		cout << "열 " << i + 1 << "번쨰의 총합 : " << row[i] << endl;
	}
	cout << "총합 : " << total << endl;
}

void RotationArray() {
	bool isPlaying = true;
	while (isPlaying)
	{
		cout << endl;
		cout << "==========================================" << endl;
		cout << endl;
		int col, row;
		cout << "원하는 행의 길이를 적어주세요 : ";
		cin >> row;
		cout << "원하는 열의 길이를 적어주세요 : ";
		cin >> col;
		int** arr = new int* [row];
		for (size_t i = 0; i < col; i++)
		{
			arr[i] = new int[col];
		}
		int index = 1;
		for (size_t i = 0; i < col; i++)
		{
			for (size_t j = 0; j < row; j++)
			{
				arr[i][j] = index;
				index++;
			}
		}
		system("cls");
		int index1;
		cout << "현재 매트릭스의 돌리는 방향을 정해주세요 (1: 시계방향 90도 2: 시계반대방향 90도 3: 반전 4: 종료) : ";
		cin >> index1;
		cout << endl;
		int** arr1 = new int* [col];
		for (size_t i = 0; i < row; i++)
		{
			arr1[i] = new int[row];
		}
		cout << row << "x" << col << "==>" << col << "x" << row << endl;
		cout << endl;
		cout << "현재 매트릭스" << endl;
		switch (index1)
		{
		case 1:
			for (size_t i = 0; i < col; i++)
			{
				for (size_t j = 0; j < row; j++)
				{
					arr1[j][col - 1 - i] = arr[i][j];
					cout << arr[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl;
			cout << "시계방향으로 90도 회전 하겠습니다." << endl;
			cout << endl;
			cout << "90도 회전된 매트릭스" << endl;
			for (size_t i = 0; i < row; i++)
			{
				for (size_t j = 0; j < col; j++)
				{
					cout << arr1[i][j] << " ";
				}
				cout << endl;
			}
			break;
		case 2:
			for (size_t i = 0; i < col; i++)
			{
				for (size_t j = 0; j < row; j++)
				{
					arr1[row - 1 - j][i] = arr[i][j];
					cout << arr[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl;
			cout << "시계 반대방향으로 90도 회전 하겠습니다." << endl;
			cout << endl;
			cout << "90도 회전된 매트릭스" << endl;
			for (size_t i = 0; i < row; i++)
			{
				for (size_t j = 0; j < col; j++)
				{
					cout << arr1[i][j] << " ";
				}
				cout << endl;
			}
			break;
		case 3:
			for (size_t i = 0; i < col; i++)
			{
				for (size_t j = 0; j < row; j++)
				{
					arr1[j][i] = arr[i][j];
					cout << arr[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl;
			cout << "매트릭스를 반전 하겠습니다." << endl;
			cout << endl;
			cout << "반전된 매트릭스" << endl;
			for (size_t i = 0; i < row; i++)
			{
				for (size_t j = 0; j < col; j++)
				{
					cout << arr1[i][j] << " ";
				}
				cout << endl;
			}
			break;
		case 4:
			isPlaying = false;
			break;
		default:
			cout << "입력된 값이 보기에 존재하지않습니다. 다시 입력해 주세요" << endl;
			break;
		}
	}

}

void RotateMatrix(int** arr) {
	int col = sizeof(arr[0]) / sizeof(int);
	int row = sizeof(arr) / sizeof(arr[0]);
	int** arr1 = new int*[row];
	for (size_t i = 0; i < col; i++)
	{
		arr1[i] = new int[col];
	}
	cout << col << "x" << row << "==>" << row << "x" << col << endl;
	cout << endl;
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			arr1[j][(i + row - 1) % row] = arr[i][j];
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	for (size_t i = 0; i < col; i++)
	{
		for (size_t j = 0; j < row; j++)
		{
			cout << arr1[i][j] << " ";
		}
		cout << endl;
	}
}


void BaseBallGame() {
	//0~8 숫자허용
		//3개만 받는다

		//컴퓨터가 먼저 랜덤한 숫자를 3개
		//사용자가 3개만 입력 받는다.
		// 자리하고 숫자가 동일 1s
		// 숫자만 동일하다면 1b

		//종료조건은 스트라이크가 3이면 종료
		//몇번만에 마쳤냐?

	int playerPos[3], comPos[3], result[3];
	bool playerNumUsed[9];
	bool comNumUsed[9];
	int strike = 0;
	int ball = 0;
	int match = 1;
	srand(time(NULL));
	while (strike < 3)
	{
		cout << match << " 매치" << endl;
		//숫자 사용한지 안한지 확인하는 배열 초기화
		for (size_t i = 0; i < 9; i++)
		{
			playerNumUsed[i] = false;
			comNumUsed[i] = false;
		}

		//컴퓨터 랜덤 값 구하기
		int computerRandomPos = 0;
		while (computerRandomPos < 3)
		{
			int randNum = rand() % 8;
			if (comNumUsed[randNum] == false)
			{
				comPos[computerRandomPos] = randNum;
				comNumUsed[randNum] = true;
				computerRandomPos++;
			}
		}
		cout << "컴퓨터값" << comPos[0] << " , " << comPos[1] << " , " << comPos[2] << endl;
		for (size_t i = 0; i < 3; i++)
		{
			bool isInputing = true;

			while (isInputing)
			{
				cout << "0부터 8까지수중 하나를 입력해주세요 : " << i + 1 << "번째 수 : ";
				cin >> playerPos[i];
				if (0 <= playerPos[i] && playerPos[i] < 9)
				{
					if (playerNumUsed[playerPos[i]] == false)
					{
						playerNumUsed[playerPos[i]] = true;
						isInputing = false;
					}
					else {
						cout << "입력한값이 이미 존재합니다. 다시 입력해주세요" << endl;
					}
				}
				else {
					cout << "입력한값이 설정범위를 벗어났습니다. 다시 입력해주세요" << endl;
				}
				cout << endl;
			}
		}

		for (size_t i = 0; i < 3; i++)
		{
			cout << i + 1 << "번쨰 라운드" << endl;
			cout << "플레이어 공 " << playerPos[i] << " 이므로 ";
			if (comPos[i] == playerPos[i])
			{
				strike++;
				cout << strike << "스트라이크" << endl;
				if (strike > 2)
				{
					break;
				}
			}
			else {
				bool isBall = false;
				for (size_t j = 0; j < 3; j++)
				{
					if (comPos[j] == playerPos[i])
					{
						ball++;
						cout << ball << "볼" << endl;
						isBall = true;
						break;
					}
				}
				if (!isBall)
				{
					cout << "아무것도 아님" << endl;
				}
			}
			cout << endl;
		}
		match++;
		cout << endl;
	}

	cout << "3 스트라이크 게임오버 아웃~~~~~" << endl;
	cout << "=============================" << endl;
	cout << "전적 총 " << match << "매치 (" << ball << "볼 3스트라이크)";
}