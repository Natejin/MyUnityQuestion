#pragma once
#include <iostream>
using namespace std;
class Unit
{
protected:
	int money;
public:
	Unit(const int money) :money(money) {};
	bool operator==(Unit& unit) {
		return money == unit.money ? true : false;
	}
	bool operator>=(Unit& unit) {
		return money >= unit.money ? true : false;
	}
	bool operator<=(Unit& unit) {
		return money <= unit.money ? true : false;
	}
	bool operator<(Unit& unit) {
		return money < unit.money ? true : false;
	}
	bool operator>(Unit& unit) {
		return money > unit.money ? true : false;
	}

	bool operator==(int unit) {
		return money == unit ? true : false;
	}
	bool operator>=(int unit) {
		return money >= unit ? true : false;
	}
	bool operator<=(int unit) {
		return money <= unit ? true : false;
	}
	bool operator<(int unit) {
		return money < unit ? true : false;
	}
	bool operator>(int unit) {
		return money > unit ? true : false;
	}

	bool CheckWallet(int unit) {
		return this->money >= unit ? true : false;
	}

	void Betting(int money) {
		this->money -= money;
	}

	virtual void Win(int money) = 0;

	int GetMoney() {
		return money;
	}
};

