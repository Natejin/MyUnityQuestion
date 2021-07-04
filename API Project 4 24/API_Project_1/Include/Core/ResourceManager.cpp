#include "ResourceManager.h"

ResourceManager::ResourceManager()
{
}

ResourceManager::~ResourceManager()
{
	unordered_map<string, class Sprite*> ::iterator iter;
	unordered_map<string, class Sprite*> ::iterator iterEnd = imageMap.end();
	for (iter = imageMap.begin(); iter != iterEnd; ++iter)
	{
		SAFE_RELEASE(iter->second);
	}
	imageMap.clear();
	SAFE_RELEASE(pBackBuffer);
}

bool ResourceManager::Init(HINSTANCE hInst, HDC hdc)
{
	this->hInst = hInst;
	this->hdc = hdc;

	//�׽�Ʈ�� ���� ����۸� �ε���
	pBackBuffer = LoadSprite("BackBuffer", L"BackBuffer.bmp");
	//SetSprite("Player", TEXT("TestPic.bmp")); 
	return true;
}

Sprite* ResourceManager::CreateSprite(const string& strKey, int width, int height)
{
	Sprite*  pSprite = new Sprite;
	if (!pSprite->CreateSprite(hInst, hdc, strKey, width, height))
	{
		//�ҷ����µ� �����ϸ� �������� NULL��ȯ
		SAFE_RELEASE(pSprite);
		return NULL;
	}
	pSprite->AddRef();
	imageMap.insert(make_pair(strKey, pSprite));

	return pSprite;
}

Sprite* ResourceManager::LoadSprite(const string& strKey, const wchar_t* pFileName, const string& strPathKey)
{
	Sprite* pSprite = FindSprite(strKey);
	//�����Ұ��
	if (pSprite)
	{
		return pSprite;
	}


	pSprite = new Sprite;

	if (!pSprite->LoadSprite(hInst, hdc, strKey, pFileName, strPathKey))
	{
		//�ҷ����µ� �����ϸ� �������� NULL��ȯ
		SAFE_RELEASE(pSprite);
		return NULL;
	}

	pSprite->AddRef();
	imageMap.insert(make_pair(strKey, pSprite));

	return pSprite;
}

Sprite* ResourceManager::FindSprite(const string& strKey)
{
	unordered_map<string, class Sprite*> ::iterator iter = imageMap.find(strKey);
	if (iter == imageMap.end())
	{
		return NULL;
	}
	iter->second->AddRef();
	return iter->second;
}

Sprite* ResourceManager::GetBackBuffer() const
{
	pBackBuffer->AddRef();
	return pBackBuffer;
}
