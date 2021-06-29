#include"framework.h"
#include "MainGame.h"
void MainGame::SetUpImage()
{
	//HDC  hdc;
	//hdc = GetDC(g_hWnd);


	//memDC = CreateCompatibleDC(hdc);
	for (size_t i = 141; i < 149; i++)
	{
		bitmaps.push_back(LoadBitmap(m_hInstance, MAKEINTRESOURCE(i)));
	}

	//oldBitmap = (HBITMAP)SelectObject(memDC, myBitmap);

	//ReleaseDC(g_hWnd, hdc);



	//m_nWidth = nWidth;
	//m_nHeight = nHeight;
}
MainGame::MainGame()
{
	player = nullptr;
}
MainGame::~MainGame()
{

}
HRESULT MainGame::init()
{
	GameNode::init();

	//이미지 셋업
	SetUpImage();

	double speed = 5;
	double randomSpeed = 15;
	player = new Player(300, 100, 60,60);
	player->SetHP(100);
	player->Resurrect();

	groundBlocks.push_back(new GroundBlock(WINSIZEX /2, (WINSIZEY - 100), WINSIZEX, 100, Vector2(0,0), Vector2(0,0)));

	for (size_t i = 0; i < 50; i++)
	{
		dropBlocks.push_back(new DropingBlock(RND->GetInt(100, WINSIZEX - 100), RND->GetInt(-500, -100), 20, 20, Vector2(-3, speed), Vector2(3, randomSpeed)));
	}
	return S_OK;
}

void MainGame::release()
{
	GameNode::release();

	for (size_t i = 0; i < groundBlocks.size(); i++)
	{
		groundBlocks[i]->release();
		delete groundBlocks[i];
		groundBlocks[i] = nullptr;
	}
	groundBlocks.clear();
	delete player;
	player = nullptr;
}

//좌표상 이동
void MainGame::update()
{
	GameNode::update();

	player->update();
	for (size_t i = 0; i < groundBlocks.size(); i++)
	{
		groundBlocks[i]->update();
	}

	for (size_t i = 0; i < dropBlocks.size(); i++)
	{
		dropBlocks[i]->update();
	}
	FixedUpdate();
}

//물리적이동
void MainGame::FixedUpdate() {

	bool collision = false;
	player->rc->SetUpLTRBFromXY();

	for (size_t i = 0; i < groundBlocks.size(); i++)
	{
		groundBlocks[i]->Translate();
		//충돌체크
		//플레이어는 한번에 한개의 객체와 충돌하는것을 가정
		//두개이상 충돌은 일단보류 ㅎㅎ
		if (!collision)
		{
			if (player->CheckIntersectAndEdit(groundBlocks[i]))
			{

				collision = true;
			}
		}
	}

	for (size_t i = 0; i < dropBlocks.size(); i++)
	{
		dropBlocks[i]->Translate();
		dropBlocks[i]->rc->SetUpLTRBFromXY();
		if (player->CheckIntersect(dropBlocks[i]))
		{
			
			dropBlocks[i]->Translate(RND->GetInt(100, WINSIZEX - 100), RND->GetInt(-500, -100));
			if (player->GetHP() >= 1)
			{
				
				player->SetHP();
			}
			else {
				player->KillPlayer();
				//player->SetHP();
			}
		}
	}

	//아무것도 충돌하지않았을경우 플레이어속도만큼 이동
	if (collision == false)
	{
		player->onGround = false;
		player->Translate();
	}
}

void MainGame::render(HDC hdc)
{
	HDC memDC;
	HBITMAP myBitmap, oldBitmap;

	//MemDC = CreateCompatibleDC(hdc);
	//MyBitmap = LoadBitmap(m_hInstance, MAKEINTRESOURCE(IDB_BITMAP4));

	//BitBlt(hdc, 0, 0, 400, 600, MemDC, 0, 0, SRCCOPY);



	//Rectangle(hdc, 30, 30, 100, 300);


	memDC = CreateCompatibleDC(hdc);
	myBitmap = LoadBitmap(m_hInstance, MAKEINTRESOURCE(CARD_DRUID));
	oldBitmap = (HBITMAP)SelectObject(memDC, myBitmap);
	GdiTransparentBlt(hdc, 0, 0, 375, 518, memDC, 0, 0, 375, 518, RGB(255, 0, 255));
	SelectObject(memDC, oldBitmap);
	DeleteObject(myBitmap);
	DeleteDC(memDC);


	//for (size_t i = 0; i < groundBlocks.size(); i++)
	//{
	//	groundBlocks[i]->render(&hdc);
	//}

	//for (size_t i = 0; i < dropBlocks.size(); i++)
	//{
	//	dropBlocks[i]->render(&hdc);
	//}


	////렌더링 플레이어
	//if (player->CheckAlive())
	//{
	//	player->rc->SetUpLTRBFromXY();

	//	brush = CreateSolidBrush(RGB(player->rgb.r, player->rgb.g, player->rgb.b));
	//	oBrush = (HBRUSH)SelectObject(hdc, brush);
	//	player->render(&hdc);
	//}
	//

	////텍스트 출력
	//static WCHAR szTitle1[100];
	//wsprintf(szTitle1, TEXT("점프 : 스페이스바"));
	//TextOut(hdc, 700, 230, szTitle1, lstrlen(szTitle1));

	//wsprintf(szTitle1, TEXT("왼쪽방향 : 방향키좌"));
	//TextOut(hdc, 700, 250, szTitle1, lstrlen(szTitle1));

	//wsprintf(szTitle1, TEXT("왼쪽방향 : 방향키우"));
	//TextOut(hdc, 700, 270, szTitle1, lstrlen(szTitle1));

	//wsprintf(szTitle1, TEXT("중력저하 : 방향키상"));
	//TextOut(hdc, 700, 290, szTitle1, lstrlen(szTitle1));

	//wsprintf(szTitle1, TEXT("현재 체력 : %d"), player->GetHP());
	//TextOut(hdc, 700, 100, szTitle1, lstrlen(szTitle1));




	/*for (size_t i = 0; i < 5; i++)
	{
		wsprintf(szTitle1, TEXT("force(x,y) : (%d.%d, %d.%d)"), (int)dropBlocks[i]->moveSpeed.x, (int)(dropBlocks[i]->moveSpeed.x * 100) % 100, (int)dropBlocks[i]->moveSpeed.y, (int)(dropBlocks[i]->moveSpeed.y * 100) % 100);
		TextOut(hdc, 900, 100 + i * 30, szTitle1, lstrlen(szTitle1));

		wsprintf(szTitle1, TEXT("force(x,y) : (%d.%d, %d.%d)"), (int)dropBlocks[i]->rc->x, (int)(dropBlocks[i]->rc->x * 100) % 100, (int)dropBlocks[i]->rc->y, (int)(dropBlocks[i]->rc->y * 100) % 100);
		TextOut(hdc, 300, 100 + i * 30, szTitle1, lstrlen(szTitle1));
	}*/
}
