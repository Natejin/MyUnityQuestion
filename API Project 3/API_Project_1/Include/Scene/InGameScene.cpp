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

	return true;
}
