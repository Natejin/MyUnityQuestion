#include "mainGame.h"


#define MAXCARD 16

mainGame::mainGame()
{
}

mainGame::~mainGame()
{
}

HRESULT mainGame::init()
{
	gameNode::init();
	currentlyGame = new GameManager_Bullet();
	
	return currentlyGame->init();
}

void mainGame::release()
{
	gameNode::release();
	currentlyGame->release();
}

void mainGame::update()
{
	gameNode::update();
	currentlyGame->update();
	
}

void mainGame::render(HDC hdc)
{
	currentlyGame->render(hdc);
}