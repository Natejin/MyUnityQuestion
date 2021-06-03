#include<iostream>
using namespace std;
static const char* RockPaperScissors[] = { "가위", "바위", "보" };

int main() {
	int player, computer;
	int match = 1;
	int playerWinCount = 0, computerWinCount = 0, drawCount = 0;
	srand((int)time(NULL));
	while (match < 11)
	{
		cout << "========================================================" << endl;
		cout << "매치 넘버 : " << match << endl;
		cout << endl;
		cout << "당신의 가위바위보를 선택하세요 (1: 가위, 2: 바위, 3: 보) : ";
		cin >> player;
		computer = rand() % 3;
		cout << endl;
		player--;
		if (player < 0 || player > 2)
		{
			cout << "해당 입력값에 대응하는 손모양이 없습니다 1 2 3중 하나를 입력해주세요." << endl;
			continue;
		}
		int result = player - computer;
		
		cout << "당신의 손모양은 " << RockPaperScissors[player] << " 이며 컴퓨터의 손모양은 " << RockPaperScissors[computer] << " 이므로 ";
		if (result == 0)
		{
			cout << "당신은 비겼습니다." << endl;
			drawCount++;
		}
		else if (result == -1 || result == 2) {
			cout << "컴퓨터가 이겼습니다." << endl;
			computerWinCount++;
		}
		else {
			cout << "당신이 이겼습니다." << endl;
			playerWinCount++;
		}
		match++;
	}
	cout << "나의 승수		: " << playerWinCount << endl;
	cout << "컴퓨터의 승수		: " << computerWinCount << endl;
	cout << "비긴 횟수		: " << drawCount << endl;
	cout << "승률			: " << playerWinCount * 10 << "%" << endl;
}