
#include "MainGame.h"
void MainGame::SetUpImage()
{
	//HDC  hdc;
	//hdc = GetDC(g_hWnd);


	//memDC = CreateCompatibleDC(hdc);
	/*for (size_t i = 141; i < 149; i++)
	{
		bitmaps.push_back(LoadBitmap(m_hInstance, MAKEINTRESOURCE(i)));
	}*/

	//oldBitmap = (HBITMAP)SelectObject(memDC, myBitmap);

	//ReleaseDC(g_hWnd, hdc);



	//m_nWidth = nWidth;
	//m_nHeight = nHeight;
}
MainGame::MainGame()
{
	//player = nullptr;
}
MainGame::~MainGame()
{

}
HRESULT MainGame::Init()
{
	GameNode::Init();

	bulletFightManager = BulletFightManager();
	bulletFightManager.Init();
	return S_OK;
}

void MainGame::Release()
{
	GameNode::Release();
	bulletFightManager.Release();
}

//��ǥ�� �̵�
void MainGame::Update()
{
	GameNode::Update();
	bulletFightManager.Update();
	//player->update();
	//for (size_t i = 0; i < groundBlocks.size(); i++)
	//{
	//	groundBlocks[i]->update();
	//}

	//for (size_t i = 0; i < dropBlocks.size(); i++)
	//{
	//	dropBlocks[i]->update();
	//}
	FixedUpdate();
}

//�������̵�
void MainGame::FixedUpdate() {
	bulletFightManager.FixedUpdate();
	//bool collision = false;
	//player->rc->SetUpLTRBFromXY();

	//for (size_t i = 0; i < groundBlocks.size(); i++)
	//{
	//	groundBlocks[i]->Translate();
	//	//�浹üũ
	//	//�÷��̾�� �ѹ��� �Ѱ��� ��ü�� �浹�ϴ°��� ����
	//	//�ΰ��̻� �浹�� �ϴܺ��� ����
	//	if (!collision)
	//	{
	//		if (player->CheckIntersectAndEdit(groundBlocks[i]))
	//		{

	//			collision = true;
	//		}
	//	}
	//}

	//for (size_t i = 0; i < dropBlocks.size(); i++)
	//{
	//	dropBlocks[i]->Translate();
	//	dropBlocks[i]->rc->SetUpLTRBFromXY();
	//	if (player->CheckIntersect(dropBlocks[i]))
	//	{
	//		
	//		dropBlocks[i]->Translate(RND->GetInt(100, WINSIZEX - 100), RND->GetInt(-500, -100));
	//		if (player->GetHP() >= 1)
	//		{
	//			
	//			player->SetHP();
	//		}
	//		else {
	//			player->KillPlayer();
	//			//player->SetHP();
	//		}
	//	}
	//}

	////�ƹ��͵� �浹�����ʾ������ �÷��̾�ӵ���ŭ �̵�
	//if (collision == false)
	//{
	//	player->onGround = false;
	//	player->Translate();
	//}
}

void MainGame::Render(HDC hdc)
{
	bulletFightManager.Render(hdc);
	//HDC memDC;
	//HBITMAP myBitmap, oldBitmap;

	////MemDC = CreateCompatibleDC(hdc);
	////MyBitmap = LoadBitmap(m_hInstance, MAKEINTRESOURCE(IDB_BITMAP4));

	////BitBlt(hdc, 0, 0, 400, 600, MemDC, 0, 0, SRCCOPY);



	////Rectangle(hdc, 30, 30, 100, 300);


	//memDC = CreateCompatibleDC(hdc);
	//myBitmap = LoadBitmap(m_hInstance, MAKEINTRESOURCE(CARD_DRUID));
	//oldBitmap = (HBITMAP)SelectObject(memDC, myBitmap);
	//GdiTransparentBlt(hdc, 0, 0, 375, 518, memDC, 0, 0, 375, 518, RGB(255, 0, 255));
	//SelectObject(memDC, oldBitmap);
	//DeleteObject(myBitmap);
	//DeleteDC(memDC);


	//for (size_t i = 0; i < groundBlocks.size(); i++)
	//{
	//	groundBlocks[i]->render(&hdc);
	//}

	//for (size_t i = 0; i < dropBlocks.size(); i++)
	//{
	//	dropBlocks[i]->render(&hdc);
	//}


	////������ �÷��̾�
	//if (player->CheckAlive())
	//{
	//	player->rc->SetUpLTRBFromXY();

	//	brush = CreateSolidBrush(RGB(player->rgb.r, player->rgb.g, player->rgb.b));
	//	oBrush = (HBRUSH)SelectObject(hdc, brush);
	//	player->render(&hdc);
	//}
	//

	////�ؽ�Ʈ ���
	//static WCHAR szTitle1[100];
	//wsprintf(szTitle1, TEXT("���� : �����̽���"));
	//TextOut(hdc, 700, 230, szTitle1, lstrlen(szTitle1));

	//wsprintf(szTitle1, TEXT("���ʹ��� : ����Ű��"));
	//TextOut(hdc, 700, 250, szTitle1, lstrlen(szTitle1));

	//wsprintf(szTitle1, TEXT("���ʹ��� : ����Ű��"));
	//TextOut(hdc, 700, 270, szTitle1, lstrlen(szTitle1));

	//wsprintf(szTitle1, TEXT("�߷����� : ����Ű��"));
	//TextOut(hdc, 700, 290, szTitle1, lstrlen(szTitle1));

	//wsprintf(szTitle1, TEXT("���� ü�� : %d"), player->GetHP());
	//TextOut(hdc, 700, 100, szTitle1, lstrlen(szTitle1));




	/*for (size_t i = 0; i < 5; i++)
	{
		wsprintf(szTitle1, TEXT("force(x,y) : (%d.%d, %d.%d)"), (int)dropBlocks[i]->moveSpeed.x, (int)(dropBlocks[i]->moveSpeed.x * 100) % 100, (int)dropBlocks[i]->moveSpeed.y, (int)(dropBlocks[i]->moveSpeed.y * 100) % 100);
		TextOut(hdc, 900, 100 + i * 30, szTitle1, lstrlen(szTitle1));

		wsprintf(szTitle1, TEXT("force(x,y) : (%d.%d, %d.%d)"), (int)dropBlocks[i]->rc->x, (int)(dropBlocks[i]->rc->x * 100) % 100, (int)dropBlocks[i]->rc->y, (int)(dropBlocks[i]->rc->y * 100) % 100);
		TextOut(hdc, 300, 100 + i * 30, szTitle1, lstrlen(szTitle1));
	}*/
}
