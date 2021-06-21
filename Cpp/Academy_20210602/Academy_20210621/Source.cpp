#include <iostream>
#include <vector>

using namespace std;


enum class ItemType {
	Equip_Weapon,
	Equip_Armor,
	Consume

};

class Item {
private:

protected:
	ItemType itemType;
	Item() { };
	string name;
	int code;
public:
	string GetName() { return name; }
	int GetCode() { return code; }
	Item(string name, int code, ItemType itemType) :name(name), code(code), itemType(itemType) {  };
	~Item() {  }
	virtual Item* GetComponent() { return this; }
	virtual Item GetComponent1() { return *this; }
	ItemType GetItemType() { return itemType; }
};

class ItemEquip :public Item {
private:

protected:
	ItemEquip() {};
	int weight;
public:
	int GetWeight() { return weight; }
	ItemEquip(string name, int code, ItemType itemType, int weight) :Item(name,code, itemType), weight(weight) {};
	~ItemEquip() {  }

	virtual ItemEquip* GetComponent() { return this; }
	//virtual ItemEquip GetComponent1() { return *this; }
};


class ItemConsume : public Item {
private:

protected:
	ItemConsume() {};
	int amount;
public:
	int GetAmount() { return amount; }
	ItemConsume(string name, int code, ItemType itemType, int amount) :Item(name, code, itemType), amount(amount) {};
	~ItemConsume() {  }

	virtual ItemConsume* GetComponent() { return this; }
};



class ItemEquipWeapon :public ItemEquip {
private:

protected:
	ItemEquipWeapon() {};
	int damage;
public:
	int GetDamage() { return damage; }
	ItemEquipWeapon(string name, int code, ItemType itemType, int weight, int damage) :ItemEquip(name, code, itemType, weight), damage(damage) {};
	~ItemEquipWeapon() { }

	virtual ItemEquipWeapon* GetComponent() { return this; }
};

class ItemEquipArmor :public ItemEquip {
private:

protected:
	ItemEquipArmor() {};
	int armor;
public:
	int GetArmor() { return armor; }
	ItemEquipArmor(string name, int code, ItemType itemType, int weight, int armor) :ItemEquip(name, code, itemType, weight), armor(armor) {};
	~ItemEquipArmor() { }

	virtual ItemEquipArmor* GetComponent() { return this; }
};


int main() {
	cout << endl << endl <<endl<< endl;

	ItemEquipWeapon weapon = ItemEquipWeapon("무기", 2000, ItemType::Equip_Weapon, 20, 22);
	ItemEquipWeapon* weapon1 = &weapon;


	ItemEquipArmor armor = ItemEquipArmor("갑옷", 1000, ItemType::Equip_Armor, 10, 11);
	ItemEquipArmor* armor1 = &armor;


	ItemConsume consume = ItemConsume("소비템", 3000, ItemType::Consume, 30);
	ItemConsume* consume1 = &consume;



	cout << "&무기구:\t"<<		& weapon << endl;
	cout << "무기구*:\t" <<		weapon1 << endl;
	cout << "&(무기구*):\t" <<	&weapon1 << endl <<endl;

	cout << "&방어구:\t" << &armor << endl;
	cout << "방어구*:\t" << armor1 << endl;
	cout << "&(방어구*):\t" << &armor1 << endl;

	cout << "&소비템:\t" << &consume << endl;
	cout << "소비템*:\t" << consume1 << endl;
	cout << "&(소비템*):\t" << &consume1 << endl;



	vector<Item*> inventory1;
	//Item* a = new Item("s", 1);
	inventory1.push_back(weapon1);
	inventory1.push_back(armor1);
	inventory1.push_back(consume1);


	cout << "================" << endl;
	for (size_t i = 0; i < inventory1.size(); i++)
	{
		cout << "아이템코드 :\t" << inventory1.at(i)->GetCode() << endl;
		cout << "아이템이름 :\t" << inventory1.at(i)->GetName() << endl;
		cout << "아이템포인터 :\t" << inventory1.at(i) << endl;
		cout << "포인터의주소 :\t" << &inventory1.at(i) << endl << endl;

		switch (inventory1.at(i)->GetItemType())
		{
		case ItemType::Equip_Weapon:
			{
				ItemEquipWeapon* item = (ItemEquipWeapon*)inventory1.at(0)->GetComponent();
				cout << "무기 포인터 :\t"<< item << endl;
				cout << "포인터의 주소 :\t"<< &item << endl;
				cout << "무게   :\t"<< item->GetWeight() << endl;
				cout << "공격력 :\t"<< item->GetDamage() << endl;
			}
			break;
		case ItemType::Equip_Armor: 
			{
				ItemEquipArmor* item = (ItemEquipArmor*)inventory1.at(0)->GetComponent();
				cout << item << endl;
				cout << &item << endl;
				cout << item->GetWeight() << endl;
				cout << item->GetArmor() << endl;
			}
			break;
		case ItemType::Consume:
			{
				ItemConsume* item = (ItemConsume*)inventory1.at(0)->GetComponent();
				cout << item << endl;
				cout << &item << endl;
				cout << item->GetAmount() << endl;
			}
			break;
		default:

			break;
		}
		cout << "================" << endl;
	}
}