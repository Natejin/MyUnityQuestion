
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
			cout << "당신은 게임을 이겼습니다." << endl;

		}
		else {
			cout << "당신은 게임에서 패배했습니다." << endl;
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
		//첫번째 카드 드로우
		CardData* firstCard = DrawCard();
		//두번쨰 카드 드로우
		CardData* secondCard = DrawCard();
		//세번째 카드 드로우
		CardData* thirdCard = DrawCard();



		if (*firstCard > *secondCard)
		{
			CardData* temp = secondCard;
			secondCard = firstCard;
			firstCard = temp;
		}

		cout << "첫번째 카드는 " << firstCard->num + 1 << " 입니다" << endl;
		Sleep(500);
		cout << "두번째 카드는 " << secondCard->num + 1 << " 입니다" << endl;
		Sleep(500);
		cout << "세번째 카드는 " << thirdCard->num + 1 << " 입니다" << endl;
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
			cout << "배팅액을 설정해주세요" << endl;
			cin >> money;
			if (!player->CheckWallet(money))
			{
				cout << "배팅액이 현재 보유한 금액보다 많습니다." << endl;
				continue;
			}
			else {
				cout << money << "원을 배팅했습니다." << endl;
				player->Betting(money);
				computer->Betting(money);
				betAmount = money * 2;
				break;
			}
		}
	}

	void GameManager::OnGUI_GameState() {

		cout << "플레이어의 소유금 : " << player->GetMoney() << endl;
		cout << "컴퓨터의 소유금 : " << computer->GetMoney() << endl;
		cout << "현재 남은 카드수 : " << totalCard << endl;
		cout << "현재 남은 카드의 종류 " << endl;
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