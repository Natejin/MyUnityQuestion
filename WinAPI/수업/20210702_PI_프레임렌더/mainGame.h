#pragma once
#include"gameNode.h"

class mainGame : public gameNode
{
private:
	Sprite* _bgImage;
	Sprite* _rockman;
	RECT rc;


	int m_index;		//�������ε���
	int m_count;		//������ ���� ī��Ʈ
	bool isLeft;		//������?


private:

public:
	mainGame();
	~mainGame();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);


	
	
};

