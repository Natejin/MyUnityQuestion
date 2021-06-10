// Acedemy_20210607_Game.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.
//

#include <iostream>
#include <Windows.h>
using namespace std;

int randNum(int min, int max);

enum monsterStat { HP, MP, Damage };

int lastDungeonIndex = 0;
string boader = "=";
string wall = "|";
bool monsterExist[20] = {};
static const char* Skill[] = { "���̾", "���̽� ������", "��� ��Ʈ����ũ" };

int skillDamage[] = { 10, 10, 10 };
void DungeonMaker();
void DungeonDraw();
int SpecialDamage();
bool randBool(int percent);

struct Unit {
	string name;
	int HP;
	int damage;

	void Initiate(int levelIndex, string monsterName[]) {
		HP = randNum(10 + levelIndex * 10, 20 + levelIndex * 15);
		damage = randNum(5 + levelIndex * 5, 15 + levelIndex * 5);
		name = monsterName[levelIndex];
	}
};

struct PlayerUnit : public Unit
{
	int MP;
	int critical;
	int level;
	int douge;
	int skillPoint;

	void Initiate() {
		HP = 50;
		MP = 30;
		critical = 20;
		level = 1;
		douge = 20;
		skillPoint = 0;
	}
};



int main()
{
	PlayerUnit player;
	player.Initiate();
	string monsterName[5] = { "���", "��ũ", "Ʈ��", "����", "���Ͽ��" };
	Unit monster[5] = {};
	
	cout << "������ �����ߴ�" << endl;
	srand((int)time(NULL));
	int monsterCount = randNum(1, 5);
	for (size_t i = 0; i < monsterCount; i++)
	{
		monster[i].Initiate(i, monsterName);
	}

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

	cout << "�ش� �������� " << monsterCount << "�� ����ŭ�� ���Ͱ� �����Ѵ�" << endl;
	cout << "���� ���� ��� ���͸� óġ �϶�" << endl;
	DungeonMaker();

	int playerIndex = 0;
	int currentlyMonsterIndex = 0;
	wall[playerIndex * 5 + 1] = 'P';
	bool isAlive = true;
	//int skillPoint = 0;
	while (isAlive && monsterCount > 0)
	{
		cout << "�÷��̾��� ���� ü��/������ " << player.HP << "/" << player.MP << "�Դϴ�.." << endl;
		Sleep(1000);
		wall[playerIndex * 5 + 1] = 'P';
		DungeonDraw();
		if (wall[playerIndex * 5 + 4] == 'M')
		{
			cout << "�ش� �濡�� ���Ͱ� �����մϴ�. ������忡 �����ϰڽ��ϴ�." << endl;
			cout << monster[currentlyMonsterIndex].name << "��(��) ������" << endl;
			while (monster[currentlyMonsterIndex].HP > 0 && player.HP > 0)
			{
				cout << "�÷��̾� HP: " << player.HP << " /MP: " << player.MP << endl;
				cout << monster[currentlyMonsterIndex].name << " HP: " << monster[currentlyMonsterIndex].HP << endl;
				int playerInput, computerInput;
				cout << "����� ����� �����ϼ��� (1: " << Skill[0] << ", 2: " << Skill[1] << ", 3 : " << Skill[2] << " 4 : �޺� ������ 5: ����) : ";
				cin >> playerInput;
				computerInput = rand() % 3;
				cout << endl;
				playerInput--;
				if (playerInput < 0 || playerInput > 4)
				{
					cout << "�ش� �Է°��� �����ϴ� ����� �����ϴ� 1 2 3�� �ϳ��� �Է����ּ���." << endl;
					continue;
				}

				if (playerInput == 3)
				{
					if (player.MP >= 20)
					{
						cout << "              �޺� ����Ʈ         " << endl;
						Sleep(500);
						cout << "���� ȿ���� 1" << endl;
						Sleep(500);
						cout << "���� ȿ���� 2" << endl;
						Sleep(500);
						cout << "���� ȿ���� 3" << endl;
						Sleep(1000);
						monster[currentlyMonsterIndex].HP -= SpecialDamage();
						cout << monster[currentlyMonsterIndex].name << "�� ü���� " << SpecialDamage() << "��ŭ �����Ͽ����ϴ�.���� ������ ü���� " 
							<< monster[currentlyMonsterIndex].HP << "�Դϴ�" << endl;
						player.MP -= 20;
						cout << "����� ������ ���� " << player.MP << "�Դϴ�" << endl;
						continue;
					}
					else {
						cout << "������ �����մϴ�" << endl;
					}

				}
				else if (playerInput == 4) {
					cout << Skill[0] << "�� " << Skill[1] << "�� �̱�� " << endl;
					cout << Skill[1] << "�� " << Skill[2] << "�� �̱�� " << endl;
					cout << Skill[2] << "�� " << Skill[0] << "�� �̱�ϴ� " << endl;
					cout << "�޺������ʹ� ��밡 ���� ������� �̱�ϴ� ��� ������ 10 �Һ��մϴ�." << endl;
					continue;
				}
				int result = playerInput - computerInput;

				cout << "����� ����� " << Skill[playerInput] << " �̸� " << monster[currentlyMonsterIndex].name << "�� ����� " << Skill[computerInput] << " �Դϴ� " << endl;
				if (result == 0)
				{
					cout << endl;
					Sleep(500);
					cout << "���� ȿ���� 1" << endl;
					Sleep(1000);
					cout << endl;
					cout << "���� ���Ǿ����ϴ�." << endl;
				}
				else if (result == -1 || result == 2) {
					cout << endl;
					Sleep(500);
					cout << "���� ȿ���� 1" << endl;
					Sleep(1000);
					cout << endl;

					if (randBool(player.douge))
					{
						cout << "����� ���� ������ ȸ���߽��ϴ�." << endl;
					}
					else {
						player.HP -= monster[currentlyMonsterIndex].damage;
						cout << monster[currentlyMonsterIndex].name << "�� �̰���ϴ�. ����� ü���� " << monster[currentlyMonsterIndex].damage << "��ŭ �����Ͽ����ϴ�.���� ü���� " << player.HP << "�Դϴ�" << endl;
					}
				}
				else {
					cout << endl;
					Sleep(500);
					cout << "���� ȿ���� 2" << endl;
					Sleep(1000);
					cout << endl;
					int multiplier = 1;
					if (randBool(player.critical))
					{
						cout << "ũ��Ƽ���� �ߵ��Ǿ����ϴ� ����� �������� �ι�� ����˴ϴ�.." << endl;
						multiplier = 2;
					}
					monster[currentlyMonsterIndex].HP -= skillDamage[playerInput] * multiplier;
					cout << "����� �̰���ϴ�. " << monster[currentlyMonsterIndex].name << "�� ü���� " << skillDamage[playerInput] * multiplier 
						<< "��ŭ �����Ͽ����ϴ�.���� ü���� " << monster[currentlyMonsterIndex].HP << "�Դϴ�" << endl;
				}
			}
			if (player.HP > 0)
			{
				cout << endl;
				Sleep(1000);
				wall[playerIndex * 5 + 4] = ' ';
				cout << "�ش� ���� ���͸� �����߽��ϴ�. �Ϲݸ�忡 �����ϰڽ��ϴ�." << endl;
				Sleep(1000);
				cout << endl;
				player.level++;
				cout << "������ �ö����ϴ�. ��ų����Ʈ�� " << player.level << " ������ϴ�. ��ų�� �÷��ּ���." << endl;
				player.skillPoint += player.level;
				currentlyMonsterIndex++;
			}
			else {
				cout << "����� �׾����ϴ�. ������ �����մϴ�." << endl;
				isAlive = false;
			}

		}
		else {
			cout << "�ش� �濡�� ���Ͱ� ���������ʽ��ϴ�." << endl;
		}

		while (player.skillPoint > 0)
		{
			Sleep(1000);
			cout << endl;
			cout << "��ų����Ʈ�� " << player.skillPoint << "���ҽ��ϴ�. ��ȭ��ų���� ����� �������ּ���" << endl;
			for (size_t i = 0; i < 3; i++)
			{
				cout << i + 1 << ": " << Skill[i] << " : ���� ������ : " << skillDamage[i] << "||" << "���ý� 5����" << endl;
			}

			cout << "4: ũ��Ƽ��Ȯ�� : " << player.critical << " || " << "���ý� 10����" << endl;
			cout << "5: ȸ��Ȯ�� : " << player.douge << " || " << "���ý� 10����" << endl;

			int playerInput;
			cin >> playerInput;

			switch (playerInput)
			{
			case 1:
				skillDamage[0] += 5;
				cout << Skill[0] << " : ���� ������ : " << skillDamage[0] << "�Դϴ�." << endl;
				player.skillPoint--;
				break;
			case 2:
				skillDamage[1] += 5;
				cout << Skill[1] << " : ���� ������ : " << skillDamage[1] << "�Դϴ�." << endl;
				player.skillPoint--;
				break;
			case 3:
				skillDamage[2] += 5;
				cout << Skill[2] << " : ���� ������ : " << skillDamage[2] << "�Դϴ�." << endl;
				player.skillPoint--;
				break;
			case 4:
				player.critical += 10;
				cout << "ũ��Ƽ��Ȯ�� : " << player.critical << "�Դϴ�" << endl;
				player.skillPoint--;
				break;
			case 5:
				player.douge += 10;
				cout << "ȸ��Ȯ�� : " << player.douge << "�Դϴ�" << endl;
				player.skillPoint--;
				break;
			default:
				cout << "�߸��� �Է��Դϴ� �ٽ� �Է��� �ּ���." << endl;
				break;
			}
		}

		if (isAlive)
		{
			cout << "���� �ൿ�� �����ּ��� (1: ���������� �̵� 2: �޽��ϱ� (HPȸ�� 10, MP 5ȸ��)) : ";
			int nextBehavior;
			cin >> nextBehavior;
			if (nextBehavior == 2)
			{
				cout << "���� �ڱ� �����մϴ�" << endl;
				for (size_t i = 0; i < 4; i++)
				{
					Sleep(500);
					cout << "Z ";
				}
				cout << endl;
				player.HP += 10;
				player.MP += 5;
			}
			wall[playerIndex * 5 + 1] = ' ';
			cout << "���������� �̵��ϰڽ��ϴ�." << endl;
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
	if (monsterCount > 0)
	{
		cout << "���� �ص� ....." << endl;
	}
	else {
		cout << "����� �̰���ϴ� ���� ����" << endl;
	}

}

//skill 3��
//baseAttack 1��

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
