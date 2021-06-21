#include "Player.h"
namespace ShopGame {
	Player::Player()
	{
		unitStatus = new UnitStatus();
	}
	Player::~Player()
	{
		delete unitStatus;
	}
	void Player::Initiate()
	{
		
	}
	void Player::UnequipItem(Item* item)
	{
		unitStatus->damage -= item->baseDamage;
		unitStatus->defence -= item->baseDefence;
	}
	void Player::EquipItem(Item* item)
	{
		unitStatus->damage += item->baseDamage;
		unitStatus->defence += item->baseDefence;
	}
	void Player::SetStatus(UnitStatus unitStatus)
	{
		this->unitStatus->race	= unitStatus.race;
		this->unitStatus->unitType = unitStatus.unitType;
		this->unitStatus->LVL = unitStatus.LVL;
		this->unitStatus->exp = unitStatus.exp;
		this->unitStatus->HP = unitStatus.HP;
		this->unitStatus->MP = unitStatus.MP;
		this->unitStatus->damage = unitStatus.damage;
		this->unitStatus->defence = unitStatus.defence;
		this->unitStatus->attackSpeed = unitStatus.attackSpeed;
		this->unitStatus->moveSpeed = unitStatus.moveSpeed;
		this->unitStatus->accuracyChance = unitStatus.accuracyChance;
		this->unitStatus->dougeChance = unitStatus.dougeChance;
		this->unitStatus->blockingChance = unitStatus.blockingChance;
		this->unitStatus->criticalChance = unitStatus.criticalChance;
		this->unitStatus->isImmortal = unitStatus.isImmortal;
	}
}