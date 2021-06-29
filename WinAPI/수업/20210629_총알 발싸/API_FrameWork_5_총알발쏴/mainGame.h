#pragma once
#include"gameNode.h"



#define BULLETMAX 30
class mainGame : public gameNode
{
private:
	/*RECT m_body;
	RECT m_bullet;
	bool isFire;*/

private:

	struct  tagBullet
	{
		RECT rc;
		bool isFire;
		float speed;
	};
	tagBullet bullet[BULLETMAX];


	RECT m_player1;
	RECT m_player2;



	//게이지
	RECT m_gaugeFront;
	RECT m_gaugeBack;



	//색상
	int m_red;
	int m_green;

public:
	mainGame();
	~mainGame();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);


	void  bulletFire();
	void bulletMove();
	void gaugeDraw();
	void collision();
	void playerKeyControl();
	
};

