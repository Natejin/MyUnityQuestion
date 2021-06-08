//야구 게임 만들기

#include<iostream>
#include<Windows.h>
using namespace std;

int ballcount = 0;//볼 카운트
int strikecount = 0;//스트라이크 카운트
int playcount = 1;//게임 횟수
int inputNum[3];//플레이어의 숫자
int inputcom[3];//컴퓨터의 숫자

void banner();//배너 애니메이션
void playerNum();//플레이어 번호 입력 및 출력
void computerNum();//컴퓨터 번호 출력

int main()
{
	banner();
	std::cout << endl << endl;
	while (true)
	{
		std::cout << "제 " << playcount << "번째 판!" << endl;
		computerNum();
		playerNum();
		std::cout << "번"; Sleep(100); std::cout << "호"; Sleep(100); std::cout << "를"; Sleep(100); std::cout << "출"; Sleep(100); std::cout << "력"; Sleep(100); std::cout << "중"; Sleep(100);
		std::cout << "입"; Sleep(100); std::cout << "니"; Sleep(100); std::cout << "다"; Sleep(100); std::cout << "."; Sleep(500); std::cout << "."; Sleep(500); std::cout << "."; Sleep(rand() % 5000); std::cout << endl;
		system("cls");

		for (int i = 0; i < 3; i++)
		{
			for (size_t j = 0; j < 3; j++)
			{
				if (inputNum[i] == inputcom[i]) { strikecount++; break; }
				else if (inputNum[i] == inputcom[j])ballcount++;
			}
		}

		std::cout << "플레이어가 입력한 번호는 : [" << inputNum[0] << "] [" << inputNum[1] << "] [" << inputNum[2] << "] 입니다!" << endl;
		std::cout << "컴퓨터가 입력한 번호는 :   [" << inputcom[0] << "] [" << inputcom[1] << "] [" << inputcom[2] << "] 입니다!" << endl;
		std::cout << endl;
		std::cout << "+=========================+" << endl;
		std::cout << "|      [" << strikecount << "]스트라이크!     |" << endl;
		std::cout << "|      [" << ballcount << "]볼!             |" << endl;
		std::cout << "+=========================+" << endl;
		std::cout << endl << endl;
		if (strikecount == 3)break;
		playcount++;
		strikecount -= strikecount;
		ballcount -= ballcount;

	}
	std::cout << playcount << "판 만에 승리하였습니다! 축하합니다!" << endl;
}

void banner()
{
	std::cout << "+--------------------+" << endl;
	std::cout << "|                    |" << endl;
	std::cout << "+--------------------+" << endl; Sleep(2000);
	system("cls");
	std::cout << "+--------------------+" << endl;
	std::cout << "|!                   |" << endl;
	std::cout << "+--------------------+" << endl; Sleep(20);
	system("cls");
	std::cout << "+--------------------+" << endl;
	std::cout << "|L!                  |" << endl;
	std::cout << "+--------------------+" << endl; Sleep(20);
	system("cls");
	std::cout << "+--------------------+" << endl;
	std::cout << "|LL!                 |" << endl;
	std::cout << "+--------------------+" << endl; Sleep(20);
	system("cls");
	std::cout << "+--------------------+" << endl;
	std::cout << "|ALL!                |" << endl;
	std::cout << "+--------------------+" << endl; Sleep(20);
	system("cls");
	std::cout << "+--------------------+" << endl;
	std::cout << "|BALL!               |" << endl;
	std::cout << "+--------------------+" << endl; Sleep(20);
	system("cls");
	std::cout << "+--------------------+" << endl;
	std::cout << "| BALL!              |" << endl;
	std::cout << "+--------------------+" << endl; Sleep(20);
	system("cls");
	std::cout << "+--------------------+" << endl;
	std::cout << "|Y BALL!             |" << endl;
	std::cout << "+--------------------+" << endl; Sleep(20);
	system("cls");
	std::cout << "+--------------------+" << endl;
	std::cout << "|AY BALL!            |" << endl;
	std::cout << "+--------------------+" << endl; Sleep(20);
	system("cls");
	std::cout << "+--------------------+" << endl;
	std::cout << "|LAY BALL!           |" << endl;
	std::cout << "+--------------------+" << endl; Sleep(20);
	system("cls");
	std::cout << "+--------------------+" << endl;
	std::cout << "|PLAY BALL!          |" << endl;
	std::cout << "+--------------------+" << endl; Sleep(20);
	system("cls");
	std::cout << "+--------------------+" << endl;
	std::cout << "| PLAY BALL!         |" << endl;
	std::cout << "+--------------------+" << endl; Sleep(20);
	system("cls");
	std::cout << "+--------------------+" << endl;
	std::cout << "|  PLAY BALL!        |" << endl;
	std::cout << "+--------------------+" << endl; Sleep(20);
	system("cls");
	std::cout << "+--------------------+" << endl;
	std::cout << "|   PLAY BALL!       |" << endl;
	std::cout << "+--------------------+" << endl; Sleep(20);
	system("cls");
	std::cout << "+--------------------+" << endl;
	std::cout << "|    PLAY BALL!      |" << endl;
	std::cout << "+--------------------+" << endl; Sleep(20);
	system("cls");
	std::cout << "+--------------------+" << endl;
	std::cout << "|     PLAY BALL!     |" << endl;
	std::cout << "+--------------------+" << endl; Sleep(1000);
}

void playerNum()
{
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 1; j++)
		{
		reselect:
			std::cout << "0~8까지의 숫자를 입력해주세요!  " << i + 1 << "번째 숫자!" << endl;
			cin >> inputNum[i];
			if (inputNum[i] > 8 || inputNum[i] < 0) {
				std::cout << "잘못 입력하였습니다. 0~8까지의 숫자만 입력해주세요." << endl << endl << endl;
				goto reselect;
			}
		}
	}
	std::cout << "입력이 끝났습니다." << endl;
}

void computerNum()
{
	srand((int)time(NULL));
	int numarr[9];
	int dest, sour, temp;

	for (size_t i = 0; i < 9; i++)
	{
		numarr[i] = i;
		/*cout << "array " << i << " 는 : " << numarr[i] << "이다." << endl;;*/
	}

	//번호 셔플
	for (size_t i = 0; i < 777; i++)
	{
		dest = rand() % 9;
		sour = rand() % 9;
		temp = numarr[dest];
		numarr[dest] = numarr[sour];
		numarr[sour] = temp;
	}

	//번호 입력
	for (size_t i = 0; i < 3; i++)
	{
		inputcom[i] = numarr[i];
	}
}
