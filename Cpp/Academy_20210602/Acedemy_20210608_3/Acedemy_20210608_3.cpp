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
		cout << "1: �߱�����, 2: �迭 �� �� ���� ���ϱ�, 3: �迭 ȸ����Ű��, 4: ���α׷� ���� " << endl;
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
		cout << "�� "<< i + 1 << "������ ���� : " << col[i] << endl;
	}

	for (size_t i = 0; i < 4; i++)
	{
		cout << "�� " << i + 1 << "������ ���� : " << row[i] << endl;
	}
	cout << "���� : " << total << endl;
}

void RotationArray() {
	bool isPlaying = true;
	while (isPlaying)
	{
		cout << endl;
		cout << "==========================================" << endl;
		cout << endl;
		int col, row;
		cout << "���ϴ� ���� ���̸� �����ּ��� : ";
		cin >> row;
		cout << "���ϴ� ���� ���̸� �����ּ��� : ";
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
		cout << "���� ��Ʈ������ ������ ������ �����ּ��� (1: �ð���� 90�� 2: �ð�ݴ���� 90�� 3: ���� 4: ����) : ";
		cin >> index1;
		cout << endl;
		int** arr1 = new int* [col];
		for (size_t i = 0; i < row; i++)
		{
			arr1[i] = new int[row];
		}
		cout << row << "x" << col << "==>" << col << "x" << row << endl;
		cout << endl;
		cout << "���� ��Ʈ����" << endl;
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
			cout << "�ð�������� 90�� ȸ�� �ϰڽ��ϴ�." << endl;
			cout << endl;
			cout << "90�� ȸ���� ��Ʈ����" << endl;
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
			cout << "�ð� �ݴ�������� 90�� ȸ�� �ϰڽ��ϴ�." << endl;
			cout << endl;
			cout << "90�� ȸ���� ��Ʈ����" << endl;
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
			cout << "��Ʈ������ ���� �ϰڽ��ϴ�." << endl;
			cout << endl;
			cout << "������ ��Ʈ����" << endl;
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
			cout << "�Էµ� ���� ���⿡ ���������ʽ��ϴ�. �ٽ� �Է��� �ּ���" << endl;
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
	//0~8 �������
		//3���� �޴´�

		//��ǻ�Ͱ� ���� ������ ���ڸ� 3��
		//����ڰ� 3���� �Է� �޴´�.
		// �ڸ��ϰ� ���ڰ� ���� 1s
		// ���ڸ� �����ϴٸ� 1b

		//���������� ��Ʈ����ũ�� 3�̸� ����
		//������� ���Ƴ�?

	int playerPos[3], comPos[3], result[3];
	bool playerNumUsed[9];
	bool comNumUsed[9];
	int strike = 0;
	int ball = 0;
	int match = 1;
	srand(time(NULL));
	while (strike < 3)
	{
		cout << match << " ��ġ" << endl;
		//���� ������� ������ Ȯ���ϴ� �迭 �ʱ�ȭ
		for (size_t i = 0; i < 9; i++)
		{
			playerNumUsed[i] = false;
			comNumUsed[i] = false;
		}

		//��ǻ�� ���� �� ���ϱ�
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
		cout << "��ǻ�Ͱ�" << comPos[0] << " , " << comPos[1] << " , " << comPos[2] << endl;
		for (size_t i = 0; i < 3; i++)
		{
			bool isInputing = true;

			while (isInputing)
			{
				cout << "0���� 8�������� �ϳ��� �Է����ּ��� : " << i + 1 << "��° �� : ";
				cin >> playerPos[i];
				if (0 <= playerPos[i] && playerPos[i] < 9)
				{
					if (playerNumUsed[playerPos[i]] == false)
					{
						playerNumUsed[playerPos[i]] = true;
						isInputing = false;
					}
					else {
						cout << "�Է��Ѱ��� �̹� �����մϴ�. �ٽ� �Է����ּ���" << endl;
					}
				}
				else {
					cout << "�Է��Ѱ��� ���������� ������ϴ�. �ٽ� �Է����ּ���" << endl;
				}
				cout << endl;
			}
		}

		for (size_t i = 0; i < 3; i++)
		{
			cout << i + 1 << "���� ����" << endl;
			cout << "�÷��̾� �� " << playerPos[i] << " �̹Ƿ� ";
			if (comPos[i] == playerPos[i])
			{
				strike++;
				cout << strike << "��Ʈ����ũ" << endl;
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
						cout << ball << "��" << endl;
						isBall = true;
						break;
					}
				}
				if (!isBall)
				{
					cout << "�ƹ��͵� �ƴ�" << endl;
				}
			}
			cout << endl;
		}
		match++;
		cout << endl;
	}

	cout << "3 ��Ʈ����ũ ���ӿ��� �ƿ�~~~~~" << endl;
	cout << "=============================" << endl;
	cout << "���� �� " << match << "��ġ (" << ball << "�� 3��Ʈ����ũ)";
}