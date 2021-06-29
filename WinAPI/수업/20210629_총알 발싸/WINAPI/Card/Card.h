#pragma once
#include "../framework.h"
class Card : public Obj
{
public:
	Card();
	Card(int x, int y, int w, int h,int ID);
	virtual ~Card();
	int x, y, w, h;

	CARDSTATE cardState;

	void Make();
	void Render(HDC hdc) {

		Rectangle(hdc, x - w, y - h, x + w, y + h);
	}

	RECT* CreateRECT(RECT* rc) {
		rc->left = x - w;
		rc->top = y - h;
		rc->right = x + w;
		rc->bottom = y + h;
		return rc;
	}
};

