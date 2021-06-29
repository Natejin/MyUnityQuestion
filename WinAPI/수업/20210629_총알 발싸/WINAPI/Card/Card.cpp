#include "Card.h"

Card::Card()
{
}

Card::Card(int x, int y, int w, int h,int ID)
{
	this->x = x;
	this->y = y;
	this->w = w/2;
	this->h = h/2;
	this->ID = ID;
	cardState = CARDSTATE::CLOSE;
}

Card::~Card()
{
}

void Card::Make()
{
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	RectMakeCenter(x, y, w, h);
}


