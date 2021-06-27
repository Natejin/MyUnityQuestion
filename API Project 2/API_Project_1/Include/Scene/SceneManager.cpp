#include "SceneManager.h"
#include "InGameScene.h"


//Scene* SceneManager::CreateScene(SCENETYPE sceneType)
//{
//	return nullptr;
//}

SceneManager::SceneManager()
	:m_pScene(nullptr), m_pNextScene(nullptr)
{

}

SceneManager::~SceneManager()
{
	//Singleton::~Singleton();
	//if (pScene) { 
	//	delete pScene; 
	//	pScene = nullptr; 
	//}
	SAFE_DELETE(m_pScene);
}

bool SceneManager::Init()
{
	CreateScene<InGameScene>(SCENE_CURRENT);

	return true;
}
