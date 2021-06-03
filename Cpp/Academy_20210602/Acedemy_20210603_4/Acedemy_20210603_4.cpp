#include<iostream>
using namespace std;
static const char* RockPaperScissors[] = { "����", "����", "��" };

int main() {
	int player, computer;
	int match = 1;
	int playerWinCount = 0, computerWinCount = 0, drawCount = 0;
	srand((int)time(NULL));
	while (match < 11)
	{
		cout << "========================================================" << endl;
		cout << "��ġ �ѹ� : " << match << endl;
		cout << endl;
		cout << "����� ������������ �����ϼ��� (1: ����, 2: ����, 3: ��) : ";
		cin >> player;
		computer = rand() % 3;
		cout << endl;
		player--;
		if (player < 0 || player > 2)
		{
			cout << "�ش� �Է°��� �����ϴ� �ո���� �����ϴ� 1 2 3�� �ϳ��� �Է����ּ���." << endl;
			continue;
		}
		int result = player - computer;
		
		cout << "����� �ո���� " << RockPaperScissors[player] << " �̸� ��ǻ���� �ո���� " << RockPaperScissors[computer] << " �̹Ƿ� ";
		if (result == 0)
		{
			cout << "����� �����ϴ�." << endl;
			drawCount++;
		}
		else if (result == -1 || result == 2) {
			cout << "��ǻ�Ͱ� �̰���ϴ�." << endl;
			computerWinCount++;
		}
		else {
			cout << "����� �̰���ϴ�." << endl;
			playerWinCount++;
		}
		match++;
	}
	cout << "���� �¼�		: " << playerWinCount << endl;
	cout << "��ǻ���� �¼�		: " << computerWinCount << endl;
	cout << "��� Ƚ��		: " << drawCount << endl;
	cout << "�·�			: " << playerWinCount * 10 << "%" << endl;
}