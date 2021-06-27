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

//��ǥ�� �̵�
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

//�������̵�
void MainGame::FixedUpdate() {

	bool collision = false;
	for (size_t i = 0; i < physicalMoveObjects.size(); i++)
	{
		physicalMoveObjects[i]->Translate();
		//�浹üũ
		//�÷��̾�� �ѹ��� �Ѱ��� ��ü�� �浹�ϴ°��� ����
		//�ΰ��̻� �浹�� �ϴܺ��� ����
		if (!collision)
		{
			if (player->CheckIntersectRect(physicalMoveObjects[i]))
			{

				collision = true;
			}
		}
	}

	//�ƹ��͵� �浹�����ʾ������ �÷��̾�ӵ���ŭ �̵�
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


	//������ �÷��̾�
	player->rc->SetUpLTRBFromXY();

	brush = CreateSolidBrush(RGB(player->rgb.r, player->rgb.g, player->rgb.b));
	oBrush = (HBRUSH)SelectObject(hdc, brush);
	player->render(&hdc);

	//�ؽ�Ʈ ���
	static WCHAR szTitle1[100];
	wsprintf(szTitle1, TEXT("���� : �����̽���"));
	TextOut(hdc, 700, 230, szTitle1, lstrlen(szTitle1));

	wsprintf(szTitle1, TEXT("���ʹ��� : ����Ű��"));
	TextOut(hdc, 700, 250, szTitle1, lstrlen(szTitle1));

	wsprintf(szTitle1, TEXT("���ʹ��� : ����Ű��"));
	TextOut(hdc, 700, 270, szTitle1, lstrlen(szTitle1));

	wsprintf(szTitle1, TEXT("�߷����� : ����Ű��"));
	TextOut(hdc, 700, 290, szTitle1, lstrlen(szTitle1));



}
