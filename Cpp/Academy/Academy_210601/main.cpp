#include<iostream>
#include<windows.h>
#include<stdlib.h>
using namespace std;
string UserName;
bool isPlay = true;
enum PLAYERJOB
{
	검사 = 1, 궁수, 마법사, 도적, 종료
};
enum MOB
{
	슬라임 = 1, 고블린, 트롤, 오우거
};
enum ACTION
{
	기본공격 = 1, 스킬1, 스킬2, 스킬3, 도망치기
};
struct Unit
{
	int HP{};
	int MP{};
	int ATK{};
	int DEF{};
	int CRI{};
	int DODGE{};
	string SkillName[3]{};
	int SkillDamage[3]{};
	int	SkillUseMP[3]{};
};
struct Player : Unit
{
	string ClassName;
	int LVL{};
	int MINEXP{};
	int MAXEXP{};
};
struct Monster : Unit
{
	string MonsterName;
	int EXP{};
};
void Oger(Monster& monster);
void Swordman(Player& player);
void Archer(Player& player);
void Wizard(Player& player);
void Thief(Player& player);
int JobInfo();

//void Slime(Monster& monster);
//void Goblin(Monster& monster);
//void Troll(Monster& monster);

void MonsterInfo(Monster& monster);
void MonsterPrint(Monster& monster);
//void PlayerFight();
//void MonsterFight();
int main() {
start:
	Player player;
	int selectjob, ask;
	JobInfo();
	cout << "당신의 이름을 입력해주세요." << endl;
	cin >> UserName;
reselect:
	system("cls");
	cout << "직업을 선택해 주세요." << endl;
	cout << "1.검사, 2.궁수, 3.마법사, 4.도적, 5.게임 종료" << endl;
	cin >> selectjob;

	switch ((PLAYERJOB)selectjob)
	{
	case 검사:
		Swordman(player);
		break;
	case 궁수:
		Archer(player);
		break;
	case 마법사:
		Wizard(player);
		break;
	case 도적:
		Thief(player);
		break;
	case 종료:
		exit(0);
	default:
		cout << "잘못 입력하였습니다. 다시 입력해주세요." << endl;
		goto reselect;
		break;
	}
	system("cls");
	cout << "직업 이름 : " << player.ClassName << endl << endl <<
		"체력 : " << player.HP <<
		"  마나 : " << player.MP <<
		"  공격력 : " << player.ATK <<
		"  방어력 : " << player.DEF <<
		"  크리티컬 확률 : " << player.CRI <<
		"  회피율 : " << player.DODGE << endl << endl;
	cout << "::스킬 정보::" << endl << endl;
	cout << "1." << player.SkillName[0] << endl << "데미지 : [" << player.SkillDamage[0] << "]    마나 : [" << player.SkillUseMP[0] << "]" << endl;
	cout << "2." << player.SkillName[1] << endl << "데미지 : [" << player.SkillDamage[1] << "]    마나 : [" << player.SkillUseMP[1] << "]" << endl;
	cout << "3." << player.SkillName[2] << endl << "데미지 : [" << player.SkillDamage[2] << "]    마나 : [" << player.SkillUseMP[2] << "]" << endl;
	cout << "현재 직업을 선택하시겠습니까?" << endl << "1.예, 2.아니오" << endl;
	cin >> ask;
	if (ask == 1);
	else if (ask == 2)
	else { system("cls"); cout << "잘못 입력하였습니다. 다시 입력해주세요" << endl << endl; Sleep(500); goto reselect1; }
togoing:
	//던전을 탐험하고있다는 메세지 띄우는곳
	//몬스터랑 마주쳤다고 메세지 띄우는곳
	Monster monster;
	MonsterInfo(monster); Sleep(500);
	while (isPlay)
	{


		cout << UserName << "님의 직업 : " << player.ClassName << endl << endl <<
			"체력 : " << player.HP <<
			"  마나 : " << player.MP <<
			"  공격력 : " << player.ATK <<
			"  방어력 : " << player.DEF <<
			"  크리티컬 확률 : " << player.CRI <<
			"  회피율 : " << player.DODGE << endl << endl;
		cout << "::스킬 정보::" << endl << endl;
		cout << "1." << player.SkillName[0] << endl << "데미지 : [" << player.SkillDamage[0] << "]    마나 : [" << player.SkillUseMP[0] << "]" << endl;
		cout << "2." << player.SkillName[1] << endl << "데미지 : [" << player.SkillDamage[1] << "]    마나 : [" << player.SkillUseMP[1] << "]" << endl;
		cout << "3." << player.SkillName[2] << endl << "데미지 : [" << player.SkillDamage[2] << "]    마나 : [" << player.SkillUseMP[2] << "]" << endl;
		cout << "======================================VS======================================" << endl;


		cout << "Fight!" << endl;
		int PlayerAction;
		cout << "행동을 선택해주세요" << endl << "1. 기본 공격,  2. 1번 스킬,  3. 2번 스킬,  4. 3번 스킬,  5.도망치기" << endl;
		cin >> PlayerAction;
		system("cls");
		switch ((ACTION)PlayerAction)
		{
		case 기본공격:
			cout << UserName << "님의 공격!" << monster.MonsterName << "에게 " << player.ATK << "의 데미지를 주었다!" << endl;
			monster.HP -= player.ATK;
			break;
		case 스킬1:
			cout << UserName << "님의" << player.SkillName[0] << "!" << monster.MonsterName << "에게 " << player.SkillDamage[0] << "의 데미지를 주었다!" << endl;
			monster.HP -= player.SkillDamage[0];
			player.MP -= player.SkillUseMP[0];
			break;
		case 스킬2:
			break;
		case 스킬3:
			break;
		case 도망치기:
			break;
		default:
			break;
		}
		MonsterPrint(monster);

		//exit(0);
	}
}
void Oger(Monster& monster)
{
	monster.MonsterName = "오우거";
	monster.HP = 125;
	monster.MP = 100;
	monster.ATK = 15;
	monster.DEF = 10;
	monster.CRI = 20;
	monster.DODGE = 30;
	monster.SkillName[0] = "블로우";
	monster.SkillDamage[0] = 35;
	monster.SkillUseMP[0] = 15;
	monster.EXP = 100;
}
void Swordman(Player& player)
{
	player.ClassName = "검사";
	player.HP = 200;
	player.MP = 50;
	player.ATK = 20;
	player.DEF = 20;
	player.CRI = 20;
	player.DODGE = 10;
	player.LVL = 1;
	player.MINEXP = 0;
	player.MAXEXP = 200;
	player.SkillName[0] = "슬래쉬";
	player.SkillName[1] = "파워 배쉬";
	player.SkillName[2] = "파이널 스트라이크";
	player.SkillDamage[0] = 45;
	player.SkillDamage[1] = 75;
	player.SkillDamage[2] = 150;
	player.SkillUseMP[0] = 15;
	player.SkillUseMP[1] = 25;
	player.SkillUseMP[2] = 50;
}

void Archer(Player& player)
{
	player.ClassName = "궁수";
	player.HP = 100;
	player.MP = 75;
	player.ATK = 20;
	player.DEF = 10;
	player.CRI = 30;
	player.DODGE = 20;
	player.LVL = 1;
	player.MINEXP = 0;
	player.MAXEXP = 200;
	player.SkillName[0] = "더블 샷";
	player.SkillName[1] = "트리플 샷";
	player.SkillName[2] = "애로우 레인";
	player.SkillDamage[0] = 40;
	player.SkillDamage[1] = 60;
	player.SkillDamage[2] = 140;
	player.SkillUseMP[0] = 20;
	player.SkillUseMP[1] = 25;
	player.SkillUseMP[2] = 50;
}

void Wizard(Player& player)
{
	player.ClassName = "마법사";
	player.HP = 75;
	player.MP = 200;
	player.ATK = 5;
	player.DEF = 10;
	player.CRI = 30;
	player.DODGE = 20;
	player.LVL = 1;
	player.MINEXP = 0;
	player.MAXEXP = 200;
	player.SkillName[0] = "에너지볼";
	player.SkillName[1] = "체인 라이트닝";
	player.SkillName[2] = "기간트 메테오";
	player.SkillDamage[0] = 45;
	player.SkillDamage[1] = 80;
	player.SkillDamage[2] = 180;
	player.SkillUseMP[0] = 30;
	player.SkillUseMP[1] = 40;
	player.SkillUseMP[2] = 100;

}

void Thief(Player& player)
{
	player.ClassName = "도적";
	player.HP = 125;
	player.MP = 100;
	player.ATK = 15;
	player.DEF = 10;
	player.CRI = 20;
	player.DODGE = 30;
	player.LVL = 1;
	player.MINEXP = 0;
	player.MAXEXP = 200;
	player.SkillName[0] = "블로우";
	player.SkillName[1] = "타겟팅 헌트";
	player.SkillName[2] = "데스체인";
	player.SkillDamage[0] = 35;
	player.SkillDamage[1] = 55;
	player.SkillDamage[2] = 95;
	player.SkillUseMP[0] = 15;
	player.SkillUseMP[1] = 25;
	player.SkillUseMP[2] = 75;
}

int JobInfo()
{
	Player player;

	int inputInfo;
	cout << "직업 정보를 확인 하시겠습니까?" << endl << "1.예, 2.아니오" << endl;
	cin >> inputInfo;
	while (inputInfo == 1) {
		int checkjob;
		cout << "확인할 직업을 선택해주세요." << endl << "1.검사, 2.궁수, 3.마법사, 4.도적, 5.정보 확인 종료" << endl;
		cin >> checkjob;
		switch ((PLAYERJOB)checkjob)
		{
		case 검사:
			Swordman(player);
			break;
		case 궁수:
			Archer(player);
			break;
		case 마법사:
			Wizard(player);
			break;
		case 도적:
			Thief(player);
			break;
		default:
			inputInfo = 0;
			break;
		}
		system("cls");
		cout << "직업 이름 : " << player.ClassName << endl << endl <<
			"체력 : " << player.HP <<
			"  마나 : " << player.MP <<
			"  공격력 : " << player.ATK <<
			"  방어력 : " << player.DEF <<
			"  크리티컬 확률 : " << player.CRI <<
			"  회피율 : " << player.DODGE << endl << endl;
		cout << "::스킬 정보::" << endl << endl;
		cout << "1." << player.SkillName[0] << endl << "데미지 : [" << player.SkillDamage[0] << "]    마나 : [" << player.SkillUseMP[0] << "]" << endl;
		cout << "2." << player.SkillName[1] << endl << "데미지 : [" << player.SkillDamage[1] << "]    마나 : [" << player.SkillUseMP[1] << "]" << endl;
		cout << "3." << player.SkillName[2] << endl << "데미지 : [" << player.SkillDamage[2] << "]    마나 : [" << player.SkillUseMP[2] << "]" << endl;


	}
	return(0);
}

void MonsterInfo(Monster& monster)
{

	int RandomSelect = 1;
	switch ((MOB)RandomSelect)
	{
	case 슬라임:
		Oger(monster);
		break;
	case 고블린:
		Oger(monster);
		break;
	case 트롤:
		Oger(monster);
		break;
	case 오우거:
		Oger(monster);
		break;
	default:
		break;
	}
}

void MonsterPrint(Monster& monster) {
	cout << "몬스터 이름 : " << monster.MonsterName << endl << endl <<
		"체력 : " << monster.HP <<
		"  마나 : " << monster.MP <<
		"  공격력 : " << monster.ATK <<
		"  방어력 : " << monster.DEF <<
		"  크리티컬 확률 : " << monster.CRI <<
		"  회피율 : " << monster.DODGE << endl << endl;
	cout << "::스킬 정보::" << endl << endl;
	for (size_t i = 0; i < 3; i++)
	{
		if (monster.SkillName[i] != "")
		{
			cout << "1." << monster.SkillName[i] << endl << "데미지 : [" << monster.SkillDamage[i] << "]    마나 : [" << monster.SkillUseMP[i] << "]" << endl;
		}
	}
}