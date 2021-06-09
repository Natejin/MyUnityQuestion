#include <iostream>
#include <time.h>
#include <string>
#include <string.h>
#include <Windows.h>
using namespace std;

//�������
//���� �Է½� Ư����ȣ�� ����
//���� ī��Ʈ�� 3�̸� ��

//�������2
//��ǻ�Ͱ� ����

enum class ROUND {PLAYER, COMPUTER};

bool checkNum[25] = {};

#define Max 25
struct Bingo
{
	string name = "";
	int bingo[25] = {};
	int count = 0;
	bool checkPos[25] = {};

	void RandomNumGen() {
		bool checkNum1[25] = {};
		for (size_t i = 0; i < Max; i++)
		{
			bool isCheck = true;

			while (isCheck)
			{
				int randNum = rand() % 25;

				if (checkNum1[randNum] == false)
				{
					bingo[i] = randNum + 1;
					checkNum1[randNum] = true;
					isCheck = false;
				}
			}
		}
	}
};


void DrawBingo(Bingo& bingo);
int CheckBingo(Bingo bingo);
void PlayerInput(Bingo& player, Bingo& computer);
int ComputerInput(Bingo& player, Bingo& computer);
//int playerCrossCount = 0;
//int computerCrossCount = 0;




int main(){
	//������ ���� ����
	srand((int)time(NULL));
	Bingo player,computer;
	player.RandomNumGen();
	player.name = "player";
	computer.RandomNumGen();
	computer.name = "computer";

	ROUND round1 = ROUND::PLAYER;
	cout << "Game ����" << endl;
	while (player.count < 3 && computer.count < 3)
	{
		int input;
		system("cls");
		for (size_t i = 0; i < 25; i++)
		{
			if (checkNum[i])
			{
				cout << i+1 << " ";
			}
	

		}
		cout << endl;
		cout<< player.count << "," << computer.count << endl;
		DrawBingo( player);
		DrawBingo( computer);
		if (round1 == ROUND::PLAYER)
		{
			PlayerInput(player, computer);
			round1 = ROUND::COMPUTER;
		}
		else {
			Sleep(1000);

			int temp = ComputerInput(player, computer);
			cout << "��ǻ���� ������ : " << temp << "�Դϴ�." << endl;
			round1 = ROUND::PLAYER;
		}
	}
	cout << "���� ��" << endl;
}

void PlayerInput(Bingo& player, Bingo& computer) {
	string text = "���� �Է����ּ���";
	int input;
	while (true)
	{
		cout << text << " : ";
		cin >> input;
		if (input > 0 && input < 26)
		{
			if (checkNum[input - 1] == false)
			{
				checkNum[input - 1] = true;
				for (size_t i = 0; i < 25; i++)
				{
					if (player.bingo[i] == input)
					{
						player.checkPos[i] = true;
					}
					if (computer.bingo[i] == input)
					{
						computer.checkPos[i] = true;
					}
				}
				text = "���� �Է����ּ���";
				return;
			}
			else {
				text = "�ش� �Է°��� �̹� �����մϴ�. �ٽ� �Է����ּ���";
			}
		}
		else {
			text = "�ش� �Է°��� ���������� ������ϴ�. �ٽ� �Է����ּ���";
		}
	}
	
}

int ComputerInput(Bingo& player, Bingo& computer) {
	while (true)
	{
		int randNum = rand() % 25;

		if (checkNum[randNum] == false)
		{
			for (size_t i = 0; i < 25; i++)
			{
				if (player.bingo[i] == randNum + 1)
				{
					player.checkPos[i] = true;
				}

				if (computer.bingo[i] == randNum + 1)
				{
					computer.checkPos[i] = true;
				}
			}
			checkNum[randNum] = true;
			return randNum;
		}
	}
}



void DrawBingo(Bingo& bingo) {
	cout << "+----+----+----+----+----+" << endl;
	for (size_t i = 0; i < Max; i++)
	{
		//true�ϰ�� ������
		if (bingo.checkPos[i])
			cout << "|  * ";
		//false�ϰ�� ��ǥ
		else
			if (bingo.bingo[i] > 9)
				cout << "| "<< bingo.bingo[i] << " ";
			else
				cout << "|  " << bingo.bingo[i] << " ";
		
		if (i % 5 == 4) {
			cout << "|" << endl;
			cout << "+----+----+----+----+----+" << endl;
		}
	}
	bingo.count = CheckBingo(bingo);
	cout << "=========================================" << endl;
	cout << "���� "<< bingo.name<<"�� ���� ���� : " << bingo.count << endl;
	cout << "=========================================" << endl;
	cout << endl;
}

int CheckBingo(Bingo bingo) {
	//����üũ
	bool isHorizontalLine[5] = {};
	bool isVerticalLine[5] = {};
	bool isCrossLine = false;
	bool isInvertCrossLine = false;
	int answer = 0;
	for (size_t i = 0; i < 25; i++)
	{
		int horiLine = i / 5;
		int vertiLine = i % 5;
		//cout << horiLine << "," << vertiLine << " || " << hori[horiLine] << "||" << verti[vertiLine] << endl;
		//����
		//���ζ��� horiLine��°�� ���� false�ϰ�� ��ǥ���� üũ
		if (isHorizontalLine[horiLine] == false)
		{
			//���� �ڸ��� ��ǥ�� �ƴϹǷ�(true) ���� ������ ���� Ȯ������ �ʱ�
			if (!bingo.checkPos[i])
			{
				isHorizontalLine[horiLine] = true;
			}
		}
		//����
		//���ζ��� vertiLine��°�� ���� false�ϰ�� ��ǥ���� üũ
		if (isVerticalLine[vertiLine] == false)
		{
			//���� �ڸ��� ��ǥ�� �ƴϹǷ�(true) ���� ������ ���� Ȯ������ �ʱ�
			if (!bingo.checkPos[i])
			{
				isVerticalLine[vertiLine] = true;
			}
		}

		//�밢��
		//���� �밢�� ������ Ʈ������ üũ 
		if (!isCrossLine)
		{
			//cout << "�밢�� üũ : " << i % 6 << " " << checkPos[i] << endl;
			//���� �ڸ��� 6���� �������� �밢�� �ڸ��� ����
			//�����ڸ��� Ʈ��� �����̹Ƿ� �ش� �밢���� ũ�ν��� �ƴ�
			if (i % 6 == 0 && !bingo.checkPos[i])
			{
				isCrossLine = true;
			}
		}

		//��ù�ڸ��� �������ڸ��� �ʿ����
		if (i > 0 && i < 24)
		{
			//���밢��
			//���� ���밢�� ������ Ʈ������ üũ 
			if (!isInvertCrossLine)
			{
				//cout << "���밢�� üũ : " << i % 4 << " " << checkPos[i] << endl;
				//���� �ڸ��� 4���� �������� ���밢�� �ڸ��� ����
				//�����ڸ��� Ʈ��� �����̹Ƿ� �ش� ���밢���� ũ�ν��� �ƴ�
				if (i % 4 == 0 && !bingo.checkPos[i])
				{
					isInvertCrossLine = true;
				}
			}
		}
	}
	if (!isCrossLine) answer++;
	if (!isInvertCrossLine) answer++;
	for (size_t i = 0; i < 5; i++)
	{
		if (!isHorizontalLine[i]) answer++;
		if (!isVerticalLine[i]) answer++;
	}
	return answer;
}