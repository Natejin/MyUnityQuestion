#pragma once
#include "Base.h"

namespace ShopGame {

	class UnitStatus
	{
	public:
		//타입 관련
		RACE race;
		UNITTYPE unitType;

		int LVL;					//레벨
		int exp;					//경험치: 유닛일경우 현재 경험치를, enemy일경우 사냥시 획득경험치를 나타낸다.

#pragma region Primary Status
		//기본스탯 관련
		int HP; 					//기본생명력
		int MP;						//기본마나

		//공격및 방어관련
		int damage;					//기본공격력
		int defence;				//기본방어력

		//속도 관련
		double attackSpeed;			//공격속도: 1초당 공격하는 횟수
		double moveSpeed;			//이동속도: 1초당 이동하는 거리

		//확률 관련
		double accuracyChance;		//명중 성공확률
		double dougeChance;			//회피 성공확률
		double blockingChance;		//블록 성공확률
		double criticalChance;		//치명타 성공확률
#pragma endregion

		//상태
		bool isImmortal;			//무적상태

	};
}