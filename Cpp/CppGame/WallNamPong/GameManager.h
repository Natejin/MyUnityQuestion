#include "Player.h"
#include "Computer.h"
#include <iostream>
#include "CardData.h"
using namespace std;


namespace WallNamPong {
	class GameManager
	{
	private:
		bool cardPack[4][12];
		int totalCard = 52;
		Unit* player;
		Unit* computer;
		int betAmount;
	public:
		CardData* DrawCard();
		void RemoveCard(CardData card);
		bool CheckCard(CardData card);
		void GameStart();
		void MatchStart();
		void DrawCards();
		void SetBettingMoney();
		void OnGUI_GameState();
	};

}