#include"framework.h"
#include "mainGame.h"
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
	double speed = 3;
	double randomSpeed = 3;
	player = new Player(300, 100, 60,60);
	for (size_t i = 0; i < 4; i++)
	{
		physicalMoveObjects.push_back(new GroundBlock(150 + i * 300, 400, 170, 50, Vector2(-speed, 0), Vector2(0, 0)));
	}

	for (size_t i = 0; i < 4; i++)
	{
		physicalMoveObjects.push_back(new GroundBlock(150 + i * 300, 700, 170, 50, Vector2(-(speed*1.5), 0), Vector2(0, 0)));
	}
	physicalMoveObjects.push_back(new GroundBlock(700, 400, 50, 200, Vector2(-speed, speed), Vector2(randomSpeed, randomSpeed)));
	physicalMoveObjects.push_back(new GroundBlock(700, 400, 50, 200, Vector2(-speed, speed), Vector2(randomSpeed, randomSpeed)));
	physicalMoveObjects.push_back(new GroundBlock(100, 300, 200, 50, Vector2(-speed, speed), Vector2(randomSpeed, randomSpeed)));
	physicalMoveObjects.push_back(new GroundBlock(400, 600, 50, 150, Vector2(-speed, speed), Vector2(randomSpeed, randomSpeed)));
	physicalMoveObjects.push_back(new GroundBlock(400, 600, 50, 150, Vector2(-speed, speed), Vector2(randomSpeed, randomSpeed)));
	physicalMoveObjects.push_back(new GroundBlock(400, 600, 150, 50, Vector2(-speed, speed), Vector2(randomSpeed, randomSpeed)));
	physicalMoveObjects.push_back(new GroundBlock(400, 600, 100, 50, Vector2(-speed, speed), Vector2(randomSpeed, randomSpeed)));
	physicalMoveObjects.push_back(new GroundBlock(400, 600, 200, 200, Vector2(-speed, speed), Vector2(randomSpeed, randomSpeed)));
	return S_OK;
}

void MainGame::release()
{
	GameNode::release();

	for (size_t i = 0; i < physicalMoveObjects.size(); i++)
	{
		physicalMoveObjects[i]->release();
		delete physicalMoveObjects[i];
		physicalMoveObjects[i] = nullptr;
	}
	physicalMoveObjects.clear();
	delete player;
	player = nullptr;
}

//좌표상 이동
void MainGame::update()
{
	GameNode::update();

	player->update();

	for (size_t i = 0; i < physicalMoveObjects.size(); i++)
	{
		physicalMoveObjects[i]->update();
	}
	FixedUpdate();
}

//물리적이동
void MainGame::FixedUpdate() {

	bool collision = false;
	for (size_t i = 0; i < physicalMoveObjects.size(); i++)
	{
		physicalMoveObjects[i]->Translate();
		//충돌체크
		//플레이어는 한번에 한개의 객체와 충돌하는것을 가정
		//두개이상 충돌은 일단보류 ㅎㅎ
		if (!collision)
		{
			if (player->CheckIntersectRect(physicalMoveObjects[i]))
			{

				collision = true;
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
	for (size_t i = 0; i < physicalMoveObjects.size(); i++)
	{

		physicalMoveObjects[i]->render(&hdc);
	}


	//렌더링 플레이어
	player->rc->SetUpLTRBFromXY();

	brush = CreateSolidBrush(RGB(player->rgb.r, player->rgb.g, player->rgb.b));
	oBrush = (HBRUSH)SelectObject(hdc, brush);
	player->render(&hdc);

	//텍스트 출력
	static WCHAR szTitle1[100];
	wsprintf(szTitle1, TEXT("점프 : 스페이스바"));
	TextOut(hdc, 700, 230, szTitle1, lstrlen(szTitle1));

	wsprintf(szTitle1, TEXT("왼쪽방향 : 방향키좌"));
	TextOut(hdc, 700, 250, szTitle1, lstrlen(szTitle1));

	wsprintf(szTitle1, TEXT("왼쪽방향 : 방향키우"));
	TextOut(hdc, 700, 270, szTitle1, lstrlen(szTitle1));

	wsprintf(szTitle1, TEXT("중력저하 : 방향키상"));
	TextOut(hdc, 700, 290, szTitle1, lstrlen(szTitle1));



}
