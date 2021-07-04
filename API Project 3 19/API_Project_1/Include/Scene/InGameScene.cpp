#include "InGameScene.h"

InGameScene::InGameScene()
{
}

InGameScene::~InGameScene()
{
}

bool InGameScene::Init()
{
	//�θ� ��Ŭ������ �ʱ�ȭ �Լ��� ȣ�����ش�.
	if (!Scene::Init())
	{
		return false;
	}
	Layer* pLayer = FindLayer(TAG::DEFAULT);

	Player* pPlayer = MonoBehavior::CreateMono<Player>(TAG::Player, pLayer);
	SAFE_RELEASE(pPlayer);

	Enemy* pEnemy = MonoBehavior::CreateMono<Enemy>(TAG::Enemy, pLayer);
	SAFE_RELEASE(pEnemy);

	Projectile* pProj = MonoBehavior::CreatePrefab<Projectile>(TAG::Projectile);
	pProj->SetSize(50.f, 50.f);
	
	SAFE_RELEASE(pProj);

	return true;
}
