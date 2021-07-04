#include "SceneManager.h"
#include "InGameScene.h"


//Scene* SceneManager::CreateScene(SCENETYPE sceneType)
//{
//	return nullptr;
//}

SceneManager::SceneManager()
	:m_pScene(NULL), pNextScene(NULL)
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
	
	m_pScene = CreateScene<InGameScene>(SCENE_CURRENT);
	m_pScene->Init();
	return true;
}

void SceneManager::Input(float deltaTime)
{
	m_pScene->Input(deltaTime);
}

int SceneManager::Update(float deltaTime)
{
	m_pScene->Update(deltaTime);
	return 0;
}

int SceneManager::LateUpdate(float deltaTime)
{
	m_pScene->LateUpdate(deltaTime);
	return 0;

}

void SceneManager::Collision(float deltaTime)
{
	m_pScene->Collision(deltaTime);
}

void SceneManager::Render(HDC hdc, float deltaTime)
{
	m_pScene->Render(hdc, deltaTime);
}


