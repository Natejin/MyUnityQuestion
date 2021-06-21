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
		int num = GetInput("직업을 선택하세요 (1: 전사, 2: 격투가, 3:궁수)", 1, 3);
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
		invenManager->AddItem(CreateItem(ITEM_집행검));
		invenManager->AddItem(CreateItem(ITEM_사과));
		invenManager->AddItem(CreateItem(ITEM_검은물체));
		invenManager->AddItem(CreateItem(ITEM_사슬갑옷));
		invenManager->AddItem(CreateItem(ITEM_파랑포션));
		cout << "check" << endl;
		bool displayInventory = true;
		string Text = "";
		while (true)
		{
			system("cls");
			if (displayInventory) Display();
			cout << endl << Text << endl << endl;;
			string a = "행동을 선택해주세요.\n1: 인벤토리보기\n2: 인벤토리선택하기\n";
			a += "3: 현재 인벤토리의 슬롯 선택하기\n4: 아이템 제작하기\n5: 선택한슬롯의 아이템버리기\n";
			a += "6: 슬롯내의 아이템 바꾸기\n 7:현재선택한 아이템 사용하기";
			int num = GetInput(a, 1,7);
			Inventory* inven = invenManager->GetSelectedInventory();
			ItemSlot* Slot = invenManager->GetSelectedSlot();
			switch (num)
			{
			case 1:
				displayInventory = !displayInventory;
				break;
			case 2:
				num = GetInput("선택할 인벤토리를 눌러주세요 (1: 장비, 2: 소비템, 3:재료템, 4: 그외)", 1,4);
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
				cout << "해당 번호는 없습니다 다시 선택해주세요" << endl;
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
				cout << ITEMTYPE_Str[invenType] << " 인벤토리의 " << j + 1 << "번째 슬롯은 비어있습니다." << endl;
				cout << "==================================================" << endl << endl;
			}
			else {
				cout << "==================================================" << endl;
				cout << ITEMTYPE_Str[invenType] << " 인벤토리의 " << j + 1 << "번째 슬롯 " << endl;
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
			cout << "현재 선택된 슬롯" << endl << endl;
			cout << "==================================================" << endl;
			if (!slot->isEmpty())
			{
				cout << ITEMTYPE_Str[invenType] << " 인벤토리 " << endl;
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
		cout << "                    장비창 " << endl;
		cout << "==================================================" << endl;
		for (int j = 0; j < equip->size(); j++)
		{
			ItemSlot* slot = equip->at(j);

			if (slot->isEmpty())
			{
				cout << "       " << EQUIPMENTPART_Str[j] << " : 미착용 "<< endl;
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
		//cout << "                미착용 " << endl << endl;
		cout << "==================================================" << endl << endl;
	
	}

	void GameManager::GUI_SelectSlot() {
		system("cls");
		Display();
		int num = GetInput("선택할 슬롯을 눌러주세요 (선택해체를 원하시면 0를 눌러주세요)",0, invenManager->GetSelectedInventory()->GetMaxSize());
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

			cout << "만들 아이템 코드를 입력해주세요 (-1 입력시 종료)" << endl;
			int num;
			cin >> num;
			if (num == -1) return;
			if (db.find(num) == db.end())
			{
				text = "해당 아이템 코드는 존재하지않습니다.";
			}
			else {
				text = db[num]->GetName() + "을 제작하여 인벤토리에 추가했습니다.\n";
				invenManager->AddItem(CreateItem(num));
			}
		}
	}

	//GUI : 인벤토리 내의 슬롯간의 아이템을 교환합니다
	//번호를 두개 입력받습니다. 
	//두개의 번호는 슬롯의 인덱스에 해당합니다.
	void GameManager::GUI_SwapItemsBetweenSlots() {
		string text = "";
		//map<unsigned int, Item*> db = dbItem->GetItemDB();
		while (true)
		{
			system("cls");
			Display();
			cout << text << endl;


			cout << "교환할려는 슬롯을 선택해주세요 (-1 입력시 종료)" << endl;
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

	//선택된 슬롯의 아이템을 사용합니다.
	void GameManager::UseItem()
	{
		//선택된 슬롯이 있는지확인 && 선택된슬롯내의 아이템이 있는지 확인
		if (invenManager->GetSelectedSlot() != nullptr && !invenManager->GetSelectedSlot()->isEmpty())
		{
			//선택된슬롯의 아이템 타입
			switch (invenManager->GetSelectedSlot()->GetComponent()->GetItemType())
			{
			case ITEMTYPE::EQUIP:
				//능력치를 확인 //TODO 추후 구현
				//직업을 확인
				if (player->GetJobs() == invenManager->GetSelectedSlot()->GetComponent()->GetJobType())
				{
					//아이템을 장착함
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
