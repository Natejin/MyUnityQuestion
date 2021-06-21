#pragma once
#include "Unit.h"
#include "Item.h"

namespace ShopGame {
	class Player : public Unit
	{
	private:
		int money;
		JOBS job;


	public:
		Player();
		~Player();
		virtual void Initiate();
		bool UseMoney(int money);
		bool AddMoney(int money);
		bool LoseMoney(int money);

		int GetLvl() { return unitStatus->LVL; }

		void SetJobs(JOBS job) { this->job = job; }
		JOBS GetJobs() { return job; }

		void UnequipItem(Item* item);
		void EquipItem(Item* item);

		UnitStatus* GetStatus() {return unitStatus;}
		void SetStatus(UnitStatus unitStatus);
	};

}


