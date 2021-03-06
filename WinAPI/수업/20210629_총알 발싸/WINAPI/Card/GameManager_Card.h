

#pragma once
#include "../DummyNode.h"
#include "Card.h"

class GameManager_Card : public DummyNode<GameManager_Card>
{
private:
	RECT callRect;
	Card card;
	vector<Card>v_cards;
	int number;
	int pair;
	int first, second;
public:
	GameManager_Card();
	virtual ~GameManager_Card();

	virtual HRESULT Init();
	virtual void Release();
	virtual void Update();
	virtual void Render(HDC hdc);
	void shuffle();

};


