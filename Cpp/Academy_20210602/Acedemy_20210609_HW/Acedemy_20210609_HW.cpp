#include <iostream>
#include <time.h>
#include <string>
#include <string.h>
#include <Windows.h>
using namespace std;

//빙고만들기
//숫자 입력시 특수기호로 변경
//빙고 카운트가 3이면 끝

//빙고만들기2
//컴퓨터가 존재

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
	//빙고판 랜덤 구현
	srand((int)time(NULL));
	Bingo player,computer;
	player.RandomNumGen();
	player.name = "player";
	computer.RandomNumGen();
	computer.name = "computer";

	ROUND round1 = ROUND::PLAYER;
	cout << "Game 시작" << endl;
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
			cout << "컴퓨터의 선택은 : " << temp << "입니다." << endl;
			round1 = ROUND::PLAYER;
		}
	}
	cout << "게임 끝" << endl;
}

void PlayerInput(Bingo& player, Bingo& computer) {
	string text = "값을 입력해주세요";
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
				text = "값을 입력해주세요";
				return;
			}
			else {
				text = "해당 입력값은 이미 존재합니다. 다시 입력해주세요";
			}
		}
		else {
			text = "해당 입력값이 지정범위를 벗어났습니다. 다시 입력해주세요";
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
		//true일경우 숫자임
		if (bingo.checkPos[i])
			cout << "|  * ";
		//false일경우 별표
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
	cout << "현재 "<< bingo.name<<"의 빙고 개수 : " << bingo.count << endl;
	cout << "=========================================" << endl;
	cout << endl;
}

int CheckBingo(Bingo bingo) {
	//가로체크
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
		//가로
		//세로라인 horiLine번째가 아직 false일경우 별표인지 체크
		if (isHorizontalLine[horiLine] == false)
		{
			//현재 자리가 별표가 아니므로(true) 현재 라인은 이후 확인하지 않기
			if (!bingo.checkPos[i])
			{
				isHorizontalLine[horiLine] = true;
			}
		}
		//세로
		//세로라인 vertiLine번째가 아직 false일경우 별표인지 체크
		if (isVerticalLine[vertiLine] == false)
		{
			//현재 자리가 별표가 아니므로(true) 현재 라인은 이후 확인하지 않기
			if (!bingo.checkPos[i])
			{
				isVerticalLine[vertiLine] = true;
			}
		}

		//대각선
		//현재 대각선 라인이 트루인지 체크 
		if (!isCrossLine)
		{
			//cout << "대각선 체크 : " << i % 6 << " " << checkPos[i] << endl;
			//현재 자리가 6으로 나눠지면 대각선 자리에 있음
			//현재자리가 트루면 숫자이므로 해당 대각선은 크로스가 아님
			if (i % 6 == 0 && !bingo.checkPos[i])
			{
				isCrossLine = true;
			}
		}

		//맨첫자리와 마지막자리는 필요없음
		if (i > 0 && i < 24)
		{
			//역대각선
			//현재 역대각선 라인이 트루인지 체크 
			if (!isInvertCrossLine)
			{
				//cout << "역대각선 체크 : " << i % 4 << " " << checkPos[i] << endl;
				//현재 자리가 4으로 나눠지면 역대각선 자리에 있음
				//현재자리가 트루면 숫자이므로 해당 역대각선은 크로스가 아님
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