// Acedemy_20210607_Game.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <Windows.h>
using namespace std;

int randNum(int min, int max);

enum monsterStat {HP, MP, Damage};

int lastDungeonIndex = 0;
string boader = "=";
string wall = "|";
bool monsterExist[20] = {};
static const char* Skill[] = { "파이어볼", "아이스 블래스터", "썬더 스트라이크" };

int skillDamage[] = { 10, 10, 10 };
void DungeonMaker();
void DungeonDraw();
int SpecialDamage();
bool randBool(int percent);
int main()
{
	int playerHP = 50;
	int playerMP = 30;
	int EXP = 0;
	int critical = 20;
	int level = 1;
	int douge = 20;

	int monster[5][3];
	string monsterName[5] = { "고블린", "오크", "트롤", "엘프", "헬하운드"};

	cout << "던전에 입장했다" << endl;
	srand((int)time(NULL));
	int monsterCount = randNum(3, 5);
	

	int tempMonsterCount = monsterCount;

	for (size_t i = 0; i < 20; i++)
	{
		if (tempMonsterCount == 0)
		{
			lastDungeonIndex = i;
			break;
		}
		if (rand() % 2 == 0)
		{
			monsterExist[i] = true;
			tempMonsterCount--;

		}
	}

	cout << "해당 던전에는 " << monsterCount << "의 수만큼의 몬스터가 존재한다" << endl;
	cout << "방을 돌아 모든 몬스터를 처치 하라" << endl;
	//cout << lastDungeonIndex << endl;

	DungeonMaker();


	



	int playerIndex = 0;
	int currentlyMonsterIndex = 0;
	wall[playerIndex * 5 + 1] = 'P';
	bool isAlive = true;
	int skillPoint = 0;
	int currentlyRoom = 0;
	while (isAlive || monsterCount > 0)
	{
		cout << "플레이어의 현재 체력/마력은 " << playerHP << "/" << playerMP << "입니다.." << endl;
		Sleep(1000);
		wall[playerIndex * 5 + 1] = 'P';
		DungeonDraw();
		if (wall[playerIndex * 5 + 4] == 'M')
		{
			cout << "해당 방에는 몬스터가 존재합니다. 전투모드에 진입하겠습니다." << endl;
			monster[currentlyMonsterIndex][HP] = randNum(10 + currentlyMonsterIndex * 10, 20 + currentlyMonsterIndex * 15);
			monster[currentlyMonsterIndex][Damage] = randNum(5 + currentlyMonsterIndex * 5, 15 + currentlyMonsterIndex * 5);
			cout << monsterName[currentlyMonsterIndex] << "를(을) 만났다" << endl;

			while (monster[currentlyMonsterIndex][HP] > 0 && playerHP > 0)
			{
				cout << "플레이어 HP: " << playerHP << " /MP: " << playerMP << endl;
				cout << monsterName[currentlyMonsterIndex] << " HP: " << monster[currentlyMonsterIndex][HP] << endl;
				int playerInput;
				int computerInput;
				cout << "당신의 기술을 선택하세요 (1: "<< Skill[0] << ", 2: "<< Skill[1] <<", 3 : " << Skill[2] << " 4 : 콤보 블러스터 5: 설명) : ";
				cin >> playerInput;
				computerInput = rand() % 3;
				cout << endl;
				playerInput--;
				if (playerInput < 0 || playerInput > 4)
				{
					cout << "해당 입력값에 대응하는 기술이 없습니다 1 2 3중 하나를 입력해주세요." << endl;
					continue;
				}

				if (playerInput == 3)
				{
					if (playerMP >= 20)
					{
						cout << "              콤보 블러스트         " << endl;
						Sleep(500);
						cout << "대충 효과음 1" << endl;
						Sleep(500);
						cout << "대충 효과음 2" << endl;
						Sleep(500);
						cout << "대충 효과음 3" << endl;
						Sleep(1000);
						monster[currentlyMonsterIndex][HP] -= SpecialDamage();
						cout << monsterName[currentlyMonsterIndex] << "의 체력은 " << SpecialDamage() << "만큼 감소하였습니다.현재 몬스터의 체력은 " << monster[currentlyMonsterIndex][HP] << "입니다" << endl;
						playerMP -= 20;
						cout << "당신의 마나는 현재 " << playerMP << "입니다" << endl;
						continue;
					}
					else {
						cout << "마나가 부족합니다" << endl;
					}

				}
				else if (playerInput == 4){
					cout << Skill[0] << "은 " << Skill[1] << "을 이기고 " << endl;
					cout << Skill[1] << "은 " << Skill[2] << "을 이기고 "  << endl;
					cout << Skill[2] << "은 " << Skill[0] << "을 이깁니다 " << endl;
					cout << "콤보블러스터는 상대가 뭐든 상관없이 이깁니다 대신 마나를 10 소비합니다." << endl;
					continue;
				}
				int result = playerInput - computerInput;

				cout << "당신의 기술은 " << Skill[playerInput] << " 이며 " << monsterName[currentlyMonsterIndex] << "의 기술은 " << Skill[computerInput] << " 입니다 " << endl;
				if (result == 0)
				{
					cout << endl;
					Sleep(500);
					cout << "대충 효과음 1" << endl;
					Sleep(1000);
					cout << endl;
					cout << "서로 상쇄되었습니다." << endl;
				}
				else if (result == -1 || result == 2) {
					cout << endl;
					Sleep(500);
					cout << "대충 효과음 1" << endl;
					Sleep(1000);
					cout << endl;
					
					if (randBool(douge))
					{
						
						cout << "당신은 적의 공격을 회피했습니다." << endl;
					}
					else {
						playerHP -= monster[currentlyMonsterIndex][Damage];
						cout << monsterName[currentlyMonsterIndex] << "가 이겼습니다. 당신의 체력은 " << monster[currentlyMonsterIndex][Damage] << "만큼 감소하였습니다.현재 체력은 " << playerHP << "입니다" << endl;
					}
					
		
				}
				else {
					cout << endl;
					Sleep(500);
					cout << "대충 효과음 2" << endl;
					Sleep(1000);
					cout << endl;
					int multiplier = 1;
					if (randBool(critical))
					{
						cout << "크리티컬이 발동되었습니다 당신의 데미지가 두배로 적용됩니다.." << endl;
						multiplier = 2;
					}
					monster[currentlyMonsterIndex][HP] -= skillDamage[playerInput] * multiplier;
					cout << "당신이 이겼습니다. " << monsterName[currentlyMonsterIndex] << "의 체력은 " << skillDamage[playerInput] * multiplier << "만큼 감소하였습니다.현재 체력은 " << monster[currentlyMonsterIndex][HP] << "입니다" << endl;
				}
			}
			if (playerHP > 0)
			{
				cout << endl;
				Sleep(1000);
				wall[playerIndex * 5 + 4] = ' ';
				cout << "해당 방의 몬스터를 제거했습니다. 일반모드에 진입하겠습니다." << endl;
				Sleep(1000);
				cout << endl;
				level++;
				cout << "레벨이 올랐습니다. 스킬포인트를 " << level << " 얻었습니다. 스킬을 올려주세요." << endl;
				skillPoint += level;
				currentlyMonsterIndex++;
			}
			else {
				cout << "당신은 죽었습니다. 게임을 종료합니다." << endl;
				isAlive = false;
			}
		
		}
		else {
			cout << "해당 방에는 몬스터가 존재하지않습니다." << endl;
		}

		while (skillPoint > 0)
		{
			Sleep(1000);
			cout << endl;
			cout << "스킬포인트가 " << skillPoint << "남았습니다. 강화시킬려는 기술을 선택해주세요" << endl;
			for (size_t i = 0; i < 3; i++)
			{
				cout << i + 1 << ": " << Skill[i] << " : 현재 데미지 : " << skillDamage[i] << "||" << "선택시 5증가" << endl;
			}
			
			cout << "4: 크리티컬확률 : " << critical << " || " << "선택시 10증가" << endl;
			cout << "5: 회피확률 : " << douge << " || " << "선택시 10증가" << endl;

			int playerInput;
			cin >> playerInput;

			switch (playerInput)
			{
			case 1:
				skillDamage[0] += 5;
				cout << Skill[0] << " : 현재 데미지 : " << skillDamage[0] << "입니다." << endl;
				skillPoint--;
				break;
			case 2:
				skillDamage[1] += 5;
				cout << Skill[1] << " : 현재 데미지 : " << skillDamage[1] << "입니다." << endl;
				skillPoint--;
				break;
			case 3:
				skillDamage[2] += 5;
				cout << Skill[2] << " : 현재 데미지 : " << skillDamage[2] << "입니다." << endl;
				skillPoint--;
				break;
			case 4:
				critical += 10;
				cout << "크리티컬확률 : " << critical << "입니다" << endl;
				skillPoint--;
				break;
			case 5:
				douge += 10;
				cout << "회피확률 : " << douge << "입니다" << endl;
				skillPoint--;
				break;
				cout << "잘못된 입력입니다 다시 입력해 주세요." << endl;
			default:
				break;
			}
		}

		if (isAlive)
		{
			cout << "다음 행동을 정해주세요 (1: 다음방으로 이동 2: 휴식하기 (HP회복 10, MP 5회복)) : ";
			int nextBehavior;
			cin >> nextBehavior;
			if (nextBehavior == 2)
			{
				cout << "잠을 자기 시작합니다" << endl;
				Sleep(1000);
				cout << "Z ";
				Sleep(1000);
				cout << "Z ";
				Sleep(1000);
				cout << "Z ";
				Sleep(1000);
				cout << "Z ";
				Sleep(1000);
				cout << "Z ";
				Sleep(1000);
				cout << endl;
				playerHP += 10;
				playerMP += 5;
	

			}
			wall[playerIndex * 5 + 1] = ' ';
			cout << "다음방으로 이동하겠습니다." << endl;
			cout << endl;
			Sleep(200);
			cout << endl;
			Sleep(200);
			cout << endl;
			Sleep(200);
			cout << "======================================================================================" << endl;
			cout << endl;
			playerIndex++;
		}
		system("cls");
	}
	currentlyRoom++;
	if (monsterCount > 0)
	{
		cout << "데드 앤드 ....." << endl;
	}
	else {
		cout << "당신은 이겼습니다 축하 축하" << endl;
	}

}

//skill 3개
//baseAttack 1개

void DungeonMaker() {

	for (size_t i = 0; i < lastDungeonIndex; i++)
	{
		if (monsterExist[i] == true)
		{
			wall += "   M";
		}
		else {
			wall += "    ";
		}
		wall += "|";
		boader += "=====";
	}
}

int SpecialDamage() {
	return skillDamage[0] + skillDamage[1] + skillDamage[2];
}

void DungeonDraw() {
	cout << boader << endl;
	cout << wall << endl;
	cout << boader << endl;
}


int randNum(int min, int max)
{
	int x = max - rand() % min;
	return x;
}

bool randBool(int percent) {
	int x = rand() % 100;
	return x <= percent ? true : false;
}
