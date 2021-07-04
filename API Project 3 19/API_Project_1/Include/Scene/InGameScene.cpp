#include "InGameScene.h"

InGameScene::InGameScene()
{
}

InGameScene::~InGameScene()
{
}

bool InGameScene::Init()
{
	//부모 씬클래스의 초기화 함수를 호출해준다.
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
