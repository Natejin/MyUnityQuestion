
#include "GameManager.h"
#include <Windows.h>

namespace WallNamPong {



	void GameManager::GameStart()
	{
		player = new Player(10000);
		computer = new Computer(10000);
		while (totalCard > 0 && *computer > 0 && *player > 0)
		{
			MatchStart();
			totalCard -= 3;
		}
		if (*player > *computer)
		{
			cout << "����� ������ �̰���ϴ�." << endl;

		}
		else {
			cout << "����� ���ӿ��� �й��߽��ϴ�." << endl;
		}

	}

	void GameManager::MatchStart()
	{
		OnGUI_GameState();
		SetBettingMoney();
		DrawCards();
		cout << endl;
		cout << endl;
	}

	void GameManager::DrawCards() {
		//ù��° ī�� ��ο�
		CardData* firstCard = DrawCard();
		//�ι��� ī�� ��ο�
		CardData* secondCard = DrawCard();
		//����° ī�� ��ο�
		CardData* thirdCard = DrawCard();



		if (*firstCard > *secondCard)
		{
			CardData* temp = secondCard;
			secondCard = firstCard;
			firstCard = temp;
		}

		cout << "ù��° ī��� " << firstCard->num + 1 << " �Դϴ�" << endl;
		Sleep(500);
		cout << "�ι�° ī��� " << secondCard->num + 1 << " �Դϴ�" << endl;
		Sleep(500);
		cout << "����° ī��� " << thirdCard->num + 1 << " �Դϴ�" << endl;
		Sleep(500);

		if (*firstCard < *thirdCard && *thirdCard < *secondCard)
		{
			player->Win(betAmount);
		}
		else {

			computer->Win(betAmount);
		}
	}

	void GameManager::SetBettingMoney() {
		int money;
		while (true)
		{
			cout << "���þ��� �������ּ���" << endl;
			cin >> money;
			if (!player->CheckWallet(money))
			{
				cout << "���þ��� ���� ������ �ݾ׺��� �����ϴ�." << endl;
				continue;
			}
			else {
				cout << money << "���� �����߽��ϴ�." << endl;
				player->Betting(money);
				computer->Betting(money);
				betAmount = money * 2;
				break;
			}
		}
	}

	void GameManager::OnGUI_GameState() {

		cout << "�÷��̾��� ������ : " << player->GetMoney() << endl;
		cout << "��ǻ���� ������ : " << computer->GetMoney() << endl;
		cout << "���� ���� ī��� : " << totalCard << endl;
		cout << "���� ���� ī���� ���� " << endl;
		for (size_t i = 0; i < 4; i++)
		{
			cout << symbolStr[i] << " : ";
			for (size_t j = 0; j < 12; j++)
			{
				if (!cardPack[i][j])
				{
					cout << j + 1 << " ";
				}
			}
			cout << endl;
		}
	}

	CardData* GameManager::DrawCard()
	{
		bool isDrawing = true;
		while (isDrawing)
		{
			int symbol = rand() % 4;
			int number = rand() % 12;

			if (!cardPack[symbol][number])
			{
				isDrawing = false;
				cardPack[symbol][number] = true;
				CardData* card = new CardData(symbol, number);
				return card;
			}
		}
	}

	void GameManager::RemoveCard(CardData card)
	{
		cardPack[(int)card.symbol][card.num] = true;
	}

	bool GameManager::CheckCard(CardData card)
	{
		return cardPack[(int)card.symbol][card.num] ? false : true;
	}

}