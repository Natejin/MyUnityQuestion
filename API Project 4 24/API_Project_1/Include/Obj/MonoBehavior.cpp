#include "MonoBehavior.h"
#include "../Scene/Layer.h"
#include "../Scene/SceneManager.h"
#include "../Scene/Scene.h"

list<MonoBehavior*> MonoBehavior::m_Monolist;
//unordered_map<TAG, MonoBehavior*> MonoBehavior::m_Prefabmap;

MonoBehavior::MonoBehavior()
	:Component()
{

}

MonoBehavior::MonoBehavior(const MonoBehavior& monoBehavilour)
	: Component(monoBehavilour)
{
	*this = monoBehavilour;


}

MonoBehavior::~MonoBehavior()
{

}



//������ �����߰� �� ��ü�� static list�� �߰�
void MonoBehavior::AddMono(MonoBehavior* pMono)
{
	pMono->AddRef();
	m_Monolist.push_back(pMono);
}

MonoBehavior* MonoBehavior::FindObject(const TAG& tag)
{
	list<MonoBehavior*>::iterator iter;
	list<MonoBehavior*>::iterator iterEnd = m_Monolist.end();

	for (iter = m_Monolist.begin(); iter != iterEnd; ++iter)
	{
		//�ش� ������Ʈ�� ��Ȱ��ȭ�ϰ�� �ѱ�
		if ((*iter)->GetTag() == tag)
		{
			(*iter)->AddRef();
			return *iter;
		}
	}
	return NULL;
}

void MonoBehavior::EraseMono(MonoBehavior* pMono)
{
	list<MonoBehavior*>::iterator iter;
	list<MonoBehavior*>::iterator iterEnd = m_Monolist.end();

	for (iter = m_Monolist.begin(); iter != iterEnd; ++iter)
	{
		
		if ((*iter) == pMono)
		{
			SAFE_RELEASE((*iter));
			iter = m_Monolist.erase(iter);
			return;
		}
	}
}

void MonoBehavior::EraseMono()
{
	//SAFE_RELEASE_VECLIST(list<MonoBehavior*>, m_Monolist);
	list<MonoBehavior*>::iterator iter;
	list<MonoBehavior*>::iterator iterEnd = m_Monolist.end();

	for (iter = m_Monolist.begin(); iter != iterEnd; ++iter)
	{

		SAFE_RELEASE((*iter));
		iter = m_Monolist.erase(iter);
	}

}

void MonoBehavior::EraseMono(const TAG& tag)
{
	list<MonoBehavior*>::iterator iter;
	list<MonoBehavior*>::iterator iterEnd = m_Monolist.end();

	for (iter = m_Monolist.begin(); iter != iterEnd; ++iter)
	{

		if ((*iter)->GetTag() == tag)
		{
			SAFE_RELEASE((*iter));
			iter = m_Monolist.erase(iter);
			return;
		}
	}
	
}




bool MonoBehavior::Enable()
{
	return false;
}

bool MonoBehavior::Disable()
{
	return false;
}



void MonoBehavior::Input(double deltaTime)
{

}

int MonoBehavior::Update(double deltaTime)
{
	return 0;
}

int MonoBehavior::LateUpdate(double deltaTime)
{
	return 0;
}

void MonoBehavior::Collision(double deltaTime)
{
}

void MonoBehavior::Render(HDC hdc, double deltaTime)
{
	Component::Render(hdc, deltaTime);
}



//void MonoBehavior::ErasePrefab()
//{
//	unordered_map<TAG, MonoBehavior*> ::iterator iter;
//	unordered_map<TAG, MonoBehavior*> ::iterator iterEnd = m_Prefabmap.end();
//	for (iter = m_Prefabmap.begin(); iter != iterEnd; ++iter)
//	{
//		SAFE_RELEASE(iter->second);
//	}
//	m_Prefabmap.clear();
//}
//
//void MonoBehavior::ErasePrefab(const TAG& tag)
//{
//	unordered_map<TAG, MonoBehavior*> ::iterator iter = m_Prefabmap.find(tag);
//
//	if (!iter->second)
//	{
//		return;
//	}
//
//	SAFE_RELEASE(iter->second);
//	m_Prefabmap.erase(iter);
//}


MonoBehavior* MonoBehavior::CreateClone(const TAG& tagKey, const TAG& tag, class Layer* pLayer)
{

	MonoBehavior* pPrefab = Scene::FindPrefab(tag);

	if (!pPrefab) 
	{
		return NULL;
	}  
	 

	MonoBehavior* pMono = (MonoBehavior*)pPrefab->Clone();

	//pMono->SetLayer(tag);
	pMono->SetTag(tag);


	if (pLayer)
	{
		pLayer->AddMono(pMono);
	}


	//������ GameObject�� �߰�
	AddMono(pMono);
	return pMono;
}

void MonoBehavior::DrawRect(HDC hdc)
{
	Rectangle(hdc, int(pos.x - scale.x), int(pos.y - scale.y), int(pos.x + scale.x), int(pos.y + scale.y));
}

void MonoBehavior::DrawRect(HDC hdc, Color rgb)
{
	HBRUSH hbr;
	hbr = CreateSolidBrush(RGB(0, 255, 0));
	HBRUSH hbrOld;
	hbrOld = (HBRUSH)SelectObject(hdc, hbr); 	// ���� �귯�� ���� 
	Rectangle(hdc, int(pos.x - scale.x), int(pos.y - scale.y), int(pos.x + scale.x), int(pos.y + scale.y));
	hbr = (HBRUSH)::SelectObject(hdc, hbrOld);
	DeleteObject(hbr); 	// ������ �귯�� ����
}

void MonoBehavior::DrawEllipse(HDC hdc) {
	Ellipse(hdc, int(pos.x - scale.x), int(pos.y - scale.y), int(pos.x + scale.x), int(pos.y + scale.y));
}

void MonoBehavior::DrawEllipse(HDC hdc, Color rgb) {
	HBRUSH hbr;
	hbr = CreateSolidBrush(RGB(0, 255, 0));
	HBRUSH hbrOld;
	hbrOld = (HBRUSH)SelectObject(hdc, hbr); 	// ���� �귯�� ���� 
	Ellipse(hdc, int(pos.x - scale.x), int(pos.y - scale.y), int(pos.x + scale.x), int(pos.y + scale.y));
	hbr = (HBRUSH)::SelectObject(hdc, hbrOld);
	DeleteObject(hbr); 	// ������ �귯�� ����
}


