#include "InGameScene.h"
#include "../Core/ResourceManager.h"
#include "../Obj/Player.h"
#include "../Obj/Enemy.h"
#include "../Obj/Projectile.h"
#include "../Obj/Background.h"

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
	Layer* pLayer = FindLayer(LAYER::DEFAULT);

	//더블 버퍼링용 백그라운드 생성
	ResourceManager::GetSingleton()->CreateSprite("BackBufferTest", WINSIZEX, WINSIZEY);



	Player* pPlayer = MonoBehavior::CreateMono<Player>(TAG::Player,"player", pLayer);
	SAFE_RELEASE(pPlayer);

	Enemy* pEnemy = MonoBehavior::CreateMono<Enemy>(TAG::Enemy,"Enemy", pLayer );
	SAFE_RELEASE(pEnemy);

	Projectile* pProj = Scene::CreatePrefab<Projectile>(TAG::Projectile, "Bullet");
	pProj->SetSize(50.f, 50.f);
	SAFE_RELEASE(pProj);
	
	Layer* pBackgroundLayer = FindLayer(LAYER::BACKGROUND);
	Background* pBackground = MonoBehavior::CreateMono<Background>(TAG::Background, "background", pBackgroundLayer);
	SAFE_RELEASE(pBackground);
	


	return true;
}
