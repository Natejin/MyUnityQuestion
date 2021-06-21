#pragma once
#include "Base.h"

namespace ShopGame {

	class UnitStatus
	{
	public:
		//Ÿ�� ����
		RACE race;
		UNITTYPE unitType;

		int LVL;					//����
		int exp;					//����ġ: �����ϰ�� ���� ����ġ��, enemy�ϰ�� ��ɽ� ȹ�����ġ�� ��Ÿ����.

#pragma region Primary Status
		//�⺻���� ����
		int HP; 					//�⺻�����
		int MP;						//�⺻����

		//���ݹ� ������
		int damage;					//�⺻���ݷ�
		int defence;				//�⺻����

		//�ӵ� ����
		double attackSpeed;			//���ݼӵ�: 1�ʴ� �����ϴ� Ƚ��
		double moveSpeed;			//�̵��ӵ�: 1�ʴ� �̵��ϴ� �Ÿ�

		//Ȯ�� ����
		double accuracyChance;		//���� ����Ȯ��
		double dougeChance;			//ȸ�� ����Ȯ��
		double blockingChance;		//��� ����Ȯ��
		double criticalChance;		//ġ��Ÿ ����Ȯ��
#pragma endregion

		//����
		bool isImmortal;			//��������

	};
}