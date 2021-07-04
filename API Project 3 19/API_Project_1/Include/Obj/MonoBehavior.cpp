#include "MonoBehavior.h"

list<MonoBehavior*> MonoBehavior::m_Monolist;
unordered_map<TAG, MonoBehavior*> MonoBehavior::m_Prefabmap;

MonoBehavior::MonoBehavior()
:angle(DEFAULT_ANGLE)
{

}

MonoBehavior::MonoBehavior(const MonoBehavior& monoBehavilour)
{
	*this = monoBehavilour;
}

MonoBehavior::~MonoBehavior()
{
}


//참조에 개수추가 및 객체를 static list에 추가
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
		//해당 오브젝트가 비활성화일경우 넘김
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



void MonoBehavior::Input(float deltaTime)
{
}

int MonoBehavior::Update(float deltaTime)
{
	return 0;
}

int MonoBehavior::LateUpdate(float deltaTime)
{
	return 0;
}

void MonoBehavior::Collision(float deltaTime)
{
}

void MonoBehavior::Render(HDC hdc, float deltaTime)
{
}

MonoBehavior* MonoBehavior::FindPrefab(const TAG& tag)
{
	unordered_map<TAG, MonoBehavior*>::iterator iter = m_Prefabmap.find(tag);
	if (iter == m_Prefabmap.end()) return NULL;
	return 	iter->second;
}

void MonoBehavior::ErasePrefab()
{
	unordered_map<TAG, MonoBehavior*> ::iterator iter;
	unordered_map<TAG, MonoBehavior*> ::iterator iterEnd = m_Prefabmap.end();
	for (iter = m_Prefabmap.begin(); iter != iterEnd; ++iter)
	{
		SAFE_RELEASE(iter->second);
	}
	m_Prefabmap.clear();
}

void MonoBehavior::ErasePrefab(const TAG& tag)
{
	unordered_map<TAG, MonoBehavior*> ::iterator iter = m_Prefabmap.find(tag);

	if (!iter->second)
	{
		return;
	}

	SAFE_RELEASE(iter->second);
	m_Prefabmap.erase(iter);
}


MonoBehavior* MonoBehavior::CreateClone(const TAG& tagKey, const TAG& tag, class Layer* pLayer)
{

	MonoBehavior* pPrefab = MonoBehavior::FindPrefab(tag);

	if (!pPrefab) 
	{
		return NULL;
	}  
	 

	MonoBehavior* pMono = pPrefab->Clone();

	pMono->SetTag(tag);


	if (pLayer)
	{
		pLayer->AddMono(pMono);
	}

	//생성된 GameObject를 추가
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
	hbrOld = (HBRUSH)SelectObject(hdc, hbr); 	// 기존 브러쉬 선택 
	Rectangle(hdc, int(pos.x - scale.x), int(pos.y - scale.y), int(pos.x + scale.x), int(pos.y + scale.y));
	hbr = (HBRUSH)::SelectObject(hdc, hbrOld);
	DeleteObject(hbr); 	// 생성한 브러쉬 삭제
}

void MonoBehavior::DrawEllipse(HDC hdc) {
	Ellipse(hdc, int(pos.x - scale.x), int(pos.y - scale.y), int(pos.x + scale.x), int(pos.y + scale.y));
}

void MonoBehavior::DrawEllipse(HDC hdc, Color rgb) {
	HBRUSH hbr;
	hbr = CreateSolidBrush(RGB(0, 255, 0));
	HBRUSH hbrOld;
	hbrOld = (HBRUSH)SelectObject(hdc, hbr); 	// 기존 브러쉬 선택 
	Ellipse(hdc, int(pos.x - scale.x), int(pos.y - scale.y), int(pos.x + scale.x), int(pos.y + scale.y));
	hbr = (HBRUSH)::SelectObject(hdc, hbrOld);
	DeleteObject(hbr); 	// 생성한 브러쉬 삭제
}


