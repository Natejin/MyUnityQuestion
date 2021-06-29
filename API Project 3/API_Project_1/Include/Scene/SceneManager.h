#pragma once
#include "../Singleton.h"
#include "Scene.h"

class SceneManager : public Singleton<SceneManager>
{
private:
	class Scene* m_pScene;
	class Scene* m_pNextScene;

public:
	bool Init();
	SceneManager();
	~SceneManager();

	template <typename T> 
	T* CreateScene(SCENE_CREATE sceneType) {
		T* pScene = new T;
		if (!pScene->Init())
		{
			SAFE_DELETE(pScene);
			return nullptr;
		}

		switch (sceneType)
		{
		case SCENE_CURRENT:
			SAFE_DELETE(m_pScene);
			m_pScene = pScene;
			break;
		case SCENE_NEXT:
			SAFE_DELETE(m_pNextScene);
			m_pNextScene = pScene;
			break;
		}
		return pScene;
	}

	//class Scene* CreateScene(SCENE_CREATE sceneType);

	

};

