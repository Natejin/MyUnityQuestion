#include "GameManager.h"
#include <Windows.h>

#define str(x) #x
#define xstr(x) str(x)

namespace ShopGame {
	GameManager* GameManager::instance = nullptr;
	GameManager::GameManager()
	{			
		dbItem = new DB_Item();
		invenManager = new InventoryManager();
		player = new Player();
		shopManager = new ShopManager();
		equipManager = new EquipmentManager();
		consoleManager = new ConsoleManager();
	}

	GameManager::~GameManager()
	{
		delete dbItem;
		delete invenManager;
		delete player;
		delete shopManager;
		delete equipManager;
		delete consoleManager;
	}



	void GameManager::CreatePlayer()
	{
		int num = GetInput("������ �����ϼ��� (1: ����, 2: ������, 3:�ü�)", 1, 3);
		player->SetJobs((JOBS)num);
		UnitStatus status = UnitStatus();
		status.race = RACE::HUMAN;
		status.unitType = UNITTYPE::PLAYER;
		status.LVL = 1;
		status.exp = 0;
		status.HP = 100;
		status.MP = 0;
		status.damage = 10;
		status.defence = 5;
		status.attackSpeed = 1;
		status.moveSpeed = 10;
		status.accuracyChance = 50;
		status.dougeChance = 0;
		status.blockingChance = 0;
		status.criticalChance = 3;
		status.isImmortal = false;
		player->SetStatus(status);
	}
	void GameManager::LoadPlayerData()
	{

	}


	void GameManager::Initiate()
	{
		CreatePlayer();
		
		
		
		//instance = this;
		dbItem->InitiateDatabase();

		cout << "check" << endl;
		invenManager->AddItem(CreateItem(ITEM_�����));
		invenManager->AddItem(CreateItem(ITEM_���));
		invenManager->AddItem(CreateItem(ITEM_������ü));
		invenManager->AddItem(CreateItem(ITEM_�罽����));
		invenManager->AddItem(CreateItem(ITEM_�Ķ�����));
		cout << "check" << endl;
		bool displayInventory = true;
		string Text = "";
		while (true)
		{
			system("cls");
			if (displayInventory) Display();
			cout << endl << Text << endl << endl;;
			string a = "�ൿ�� �������ּ���.\n1: �κ��丮����\n2: �κ��丮�����ϱ�\n";
			a += "3: ���� �κ��丮�� ���� �����ϱ�\n4: ������ �����ϱ�\n5: �����ѽ����� �����۹�����\n";
			a += "6: ���Գ��� ������ �ٲٱ�\n 7:���缱���� ������ ����ϱ�";
			int num = GetInput(a, 1,7);
			Inventory* inven = invenManager->GetSelectedInventory();
			ItemSlot* Slot = invenManager->GetSelectedSlot();
			switch (num)
			{
			case 1:
				displayInventory = !displayInventory;
				break;
			case 2:
				num = GetInput("������ �κ��丮�� �����ּ��� (1: ���, 2: �Һ���, 3:�����, 4: �׿�)", 1,4);
				invenManager->SelectInventory(--num);
				break;
			case 3:
				GUI_SelectSlot();
				break;
			case 4:
				GUI_SelectCreateItem();
				break;
			case 5:
				if (Slot->GetIndex() != -1 && !Slot->isEmpty())
				{
					Slot->RemoveFromSlots();
				}
				break;
			case 6:
				GUI_SwapItemsBetweenSlots();
				break;
			case 7:
				UseItem();
				break;
			default:
				break;
			}
		}
	}

	int GameManager::GetInput(string text,int min, int max) {
		while (true)
		{
			cout << text << endl;
			int num;
			cin >> num;
			if (min <= num && num <= max)
			{
				return num;
			}
			else {
				cout << "�ش� ��ȣ�� �����ϴ� �ٽ� �������ּ���" << endl;
			}
		}
		return 0;
	}
	Item* GameManager::CreateItem(unsigned int code)
	{
		return dbItem->GetItem(code);
	}
	void GameManager::Display() {
		DisplayInventory();
		DisplayEquipment();
		DisplayStatus();
		GetConsoleManager()->PrintAll();
	}

	void GameManager::DisplayInventory() {
		int invenType = (int)invenManager->GetInventoryType();
		for (int j = 0; j < invenManager->GetMaxSize(); j++)
		{
			ItemSlot* slot = invenManager->GetSelectedInventory()->GetItemSlot(j);
			if (slot->isEmpty())
			{
				cout << "==================================================" << endl;
				cout << ITEMTYPE_Str[invenType] << " �κ��丮�� " << j + 1 << "��° ������ ����ֽ��ϴ�." << endl;
				cout << "==================================================" << endl << endl;
			}
			else {
				cout << "==================================================" << endl;
				cout << ITEMTYPE_Str[invenType] << " �κ��丮�� " << j + 1 << "��° ���� " << endl;
				cout << slot->GetComponent()->GetName() << endl;
				cout << slot->GetComponent()->GetDescription() << endl;
				cout << ITEMTYPE_Str[(int)slot->GetComponent()->GetItemType()] << endl;
				cout << slot->GetComponent()->GetPrice() << endl;
				cout << "==================================================" << endl << endl;
			}
		}
		
		ItemSlot* slot = invenManager->GetSelectedSlot();
		if (slot!=nullptr)
		{
			cout << "���� ���õ� ����" << endl << endl;
			cout << "==================================================" << endl;
			if (!slot->isEmpty())
			{
				cout << ITEMTYPE_Str[invenType] << " �κ��丮 " << endl;
				cout << slot->GetComponent()->GetName() << endl;
				cout << ITEMTYPE_Str[(int)slot->GetComponent()->GetItemType()] << endl;
				cout << slot->GetComponent()->GetDescription() << endl;
				cout << slot->GetComponent()->GetPrice() << endl;
			}
			cout << "==================================================" << endl << endl;
		}
	}

	void GameManager::DisplayEquipment()
	{
		auto equip = equipManager->GetEquips();
		cout << "==================================================" << endl ;
		cout << "                    ���â " << endl;
		cout << "==================================================" << endl;
		for (int j = 0; j < equip->size(); j++)
		{
			ItemSlot* slot = equip->at(j);

			if (slot->isEmpty())
			{
				cout << "       " << EQUIPMENTPART_Str[j] << " : ������ "<< endl;
			}
			else {
				cout << "       " << EQUIPMENTPART_Str[j] << " : " << slot->GetComponent()->GetName() << endl;

			}
		}
		cout << "==================================================" << endl;
	
	}
	void GameManager::DisplayStatus() {
		auto temp = player->GetStatus();
		cout << "==================================================" << endl;
		cout << "HP\t\t: "  << temp->HP << endl << endl;
		cout << "MP\t\t: " << temp->MP << endl << endl;
		cout << "AttackPoint\t: " << temp->damage << endl << endl;
		cout << "DefencePoint\t: " << temp->defence << endl << endl;
		//cout << "                ������ " << endl << endl;
		cout << "==================================================" << endl << endl;
	
	}

	void GameManager::GUI_SelectSlot() {
		system("cls");
		Display();
		int num = GetInput("������ ������ �����ּ��� (������ü�� ���Ͻø� 0�� �����ּ���)",0, invenManager->GetSelectedInventory()->GetMaxSize());
		if (num == 0)
		{
			invenManager->UnselectSlot();
		}else 
		{
			invenManager->SelectSlot(--num);
		}
	}

	void GameManager::GUI_SelectCreateItem() {
		string text = "";
		map<unsigned int, Item*> db = dbItem->GetItemDB();
		while (true)
		{
			system("cls");
			cout << text << endl;
			for (auto it = db.begin(); it != db.end(); ++it)
				cout << (it->first) << " : " << (it->second)->GetName() << '\n';

			cout << "���� ������ �ڵ带 �Է����ּ��� (-1 �Է½� ����)" << endl;
			int num;
			cin >> num;
			if (num == -1) return;
			if (db.find(num) == db.end())
			{
				text = "�ش� ������ �ڵ�� ���������ʽ��ϴ�.";
			}
			else {
				text = db[num]->GetName() + "�� �����Ͽ� �κ��丮�� �߰��߽��ϴ�.\n";
				invenManager->AddItem(CreateItem(num));
			}
		}
	}

	//GUI : �κ��丮 ���� ���԰��� �������� ��ȯ�մϴ�
	//��ȣ�� �ΰ� �Է¹޽��ϴ�. 
	//�ΰ��� ��ȣ�� ������ �ε����� �ش��մϴ�.
	void GameManager::GUI_SwapItemsBetweenSlots() {
		string text = "";
		//map<unsigned int, Item*> db = dbItem->GetItemDB();
		while (true)
		{
			system("cls");
			Display();
			cout << text << endl;


			cout << "��ȯ�ҷ��� ������ �������ּ��� (-1 �Է½� ����)" << endl;
			int num1,num2;
			cin >> num1;
			if (num1 == -1) return;
			cin >> num2;
			if (num1 == -1) return;
			if (num1 != num2)
			{
				invenManager->SwapItem(num1, num2);
			}
		}
	}

	//���õ� ������ �������� ����մϴ�.
	void GameManager::UseItem()
	{
		//���õ� ������ �ִ���Ȯ�� && ���õȽ��Գ��� �������� �ִ��� Ȯ��
		if (invenManager->GetSelectedSlot() != nullptr && !invenManager->GetSelectedSlot()->isEmpty())
		{
			//���õȽ����� ������ Ÿ��
			switch (invenManager->GetSelectedSlot()->GetComponent()->GetItemType())
			{
			case ITEMTYPE::EQUIP:
				//�ɷ�ġ�� Ȯ�� //TODO ���� ����
				//������ Ȯ��
				if (player->GetJobs() == invenManager->GetSelectedSlot()->GetComponent()->GetJobType())
				{
					//�������� ������
					GetEquipmentManager()->Equip(invenManager->GetSelectedSlot());
				}
				else {
					GetConsoleManager()->ErrorCodePush(ErrorCode::ERROR_Equipment_ClassDoesNotMatch);
				}
				break;
			case ITEMTYPE::CONSUME:
				break;
			case ITEMTYPE::MATERIAL:
				break;
			case ITEMTYPE::ETC:
				break;
			default:
				break;
			}
		}
	}
}

//#include <iostream> 
//#include <vector> 
//using namespace std; 
//void main() { 
//	int ari[] = {0,1,2,3,4};
//	vector<int> vi(&ari[0],&ari[5]); 
//	vector<int>::iterator it; 
//	for (it=vi.begin();it!=vi.end();it++) 	{ 
//		printf("%d\n",*it); 
//	} 
//}
