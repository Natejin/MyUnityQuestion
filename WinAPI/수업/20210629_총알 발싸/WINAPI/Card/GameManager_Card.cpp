#include "GameManager_Card.h"


#define MAXCARD 16

GameManager_Card::GameManager_Card()
{
}

GameManager_Card::~GameManager_Card()
{
}

HRESULT GameManager_Card::init()
{
	int id = 0;
	callRect = RECT();
	for (int j = 0; j < MAXCARD / 4; j++)
	{
		for (int i = 0; i < MAXCARD / 4; i++)
		{
			Card newCard = Card(100 + i * 150, 100 + j * 190, 100, 140, id);
			v_cards.push_back(newCard);
			id++;
		}
	}
	shuffle();
	//UFUNC->Shuffle(v_cards);
	return S_OK;
}

void GameManager_Card::release()
{

}

void GameManager_Card::update()
{


	//마우스 누를시
	if (InputManager->isOnceKeyDown(VK_LBUTTON))
	{
		for (size_t i = 0; i < v_cards.size(); i++)
		{
			if (v_cards[i].cardState == CARDSTATE::OPEN)continue;

			//처음카드 클릭
			if (PtInRect(v_cards[i].CreateRECT(&callRect), m_ptMouse) && number == 0)
			{
				v_cards[i].cardState = CARDSTATE::OPEN;
				first = v_cards[i].ID;
				number++;
				break;
			}
			//두번째카드 클릭
			else if (PtInRect(v_cards[i].CreateRECT(&callRect), m_ptMouse) && number == 1)
			{
				v_cards[i].cardState = CARDSTATE::OPEN;
				second = v_cards[i].ID;
				number++;
				pair++;
				break;
			}
			//카드비교
			else if (number == 2)
			{
				if (first % 8 == second % 8)
				{
					number = 0;
					break;
				}
				else
				{
					v_cards[first].cardState = CARDSTATE::CLOSE;
					v_cards[second].cardState = CARDSTATE::CLOSE;
					number = 0;
					pair--;
					break;
				}
			}
		}
	}
}

void GameManager_Card::render(HDC hdc)
{

	for (int i = 0; i < v_cards.size(); i++)
	{
		if (v_cards[i].cardState == CARDSTATE::CLOSE) {
			HBRUSH brush = CreateSolidBrush(RGB(0, 0, 0));
			FillRect(hdc, v_cards[i].CreateRECT(&callRect), brush);
			DeleteObject(brush);
		}
		else {
			if (v_cards[i].ID % 8 == 0) {
				HBRUSH brush = CreateSolidBrush(RGB(200, 30, 30));
				FillRect(hdc, v_cards[i].CreateRECT(&callRect), brush);
				DeleteObject(brush);
			}
			if (v_cards[i].ID % 8 == 1) {
				HBRUSH brush = CreateSolidBrush(RGB(30, 200, 30));
				FillRect(hdc, v_cards[i].CreateRECT(&callRect), brush);
				DeleteObject(brush);
			}
			if (v_cards[i].ID % 8 == 2) {
				HBRUSH brush = CreateSolidBrush(RGB(30, 30, 200));
				FillRect(hdc, v_cards[i].CreateRECT(&callRect), brush);
				DeleteObject(brush);
			}
			if (v_cards[i].ID % 8 == 3) {
				HBRUSH brush = CreateSolidBrush(RGB(200, 200, 0));
				FillRect(hdc, v_cards[i].CreateRECT(&callRect), brush);
				DeleteObject(brush);
			}
			if (v_cards[i].ID % 8 == 4) {
				HBRUSH brush = CreateSolidBrush(RGB(150, 150, 0));
				FillRect(hdc, v_cards[i].CreateRECT(&callRect), brush);
				DeleteObject(brush);
			}
			if (v_cards[i].ID % 8 == 5) {
				HBRUSH brush = CreateSolidBrush(RGB(200, 30, 200));
				FillRect(hdc, v_cards[i].CreateRECT(&callRect), brush);
				DeleteObject(brush);
			}
			if (v_cards[i].ID % 8 == 6) {
				HBRUSH brush = CreateSolidBrush(RGB(200, 100, 30));
				FillRect(hdc, v_cards[i].CreateRECT(&callRect), brush);
				DeleteObject(brush);
			}
			if (v_cards[i].ID % 8 == 7) {
				HBRUSH brush = CreateSolidBrush(RGB(30, 255, 255));
				FillRect(hdc, v_cards[i].CreateRECT(&callRect), brush);
				DeleteObject(brush);
			}
		}
	}
}
void GameManager_Card::shuffle()
{

	int dest, sour;

	for (int i = 0; i < 25; i++)
	{
		dest = RND->GetInt(int(v_cards.size()));
		sour = RND->GetInt(int(v_cards.size()));

		auto temp = v_cards[dest];
		v_cards[dest] = v_cards[sour];
		v_cards[sour] = temp;
	}
	for (int i = 0; i < v_cards.size(); i++)
	{
		v_cards[i].ID = i;
	}


}

