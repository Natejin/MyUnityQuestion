#include "MainGame.h"


#define MAXCARD 16

MainGame::MainGame()
{
}

MainGame::~MainGame()
{
}

HRESULT MainGame::Init()
{
	GameNode::Init();
	currentlyGame = GameManager_Bullet::GetSingleton();
	
	return currentlyGame->Init();
}

void MainGame::Release()
{
	GameNode::Release();
	currentlyGame->Release();
}

void MainGame::Update()
{
	GameNode::Update();
	currentlyGame->Update();
	
}

void MainGame::Render()
{

	PatBlt(GetMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//=================================================
	{
		//SCENE->Render();
	}
	//==================   Debug   ====================
	if (isDebug)
	{

	}
	//=================================================
	FRAME->Render(GetMemDC());
	this->SetBackBuffer()->Render(GetHDC());
	currentlyGame->Render(GetHDC());
}