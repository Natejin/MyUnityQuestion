#include "Component.h"
#include "../InputManager.h"



#define INPUT InputManager::GetSingleton()

class MonoBehavior : public Component {
protected:

	MonoBehavior(const MonoBehavior& obj);
	virtual ~MonoBehavior();

private:

	//해당 씬에서 사용하는 모든 GameObject 
	static list<MonoBehavior*> m_Monolist;
	static unordered_map<TAG, MonoBehavior*> m_Prefabmap;

public:
	MonoBehavior();
	static void AddMono(MonoBehavior* pMono);
	static MonoBehavior* FindObject(const TAG& tag);
	static void EraseMono(MonoBehavior* pMono);
	static void EraseMono();
	static void EraseMono(const TAG& tag);


protected:
	//오브젝트가 속한 씬의 포인터
	class Scene* m_pScene;
	//오브젝트가 속한 씬의 레이어
	class Layer* m_pLayer;

public:
	//씬 설정
	void SetScene(class Scene* pScene) { this->m_pScene = pScene; }
	//레이어 설정
	void SetLayer(class Layer* pLayer) { this->m_pLayer = pLayer; }

	class  Scene* GetScene() const { return m_pScene; }
	class  Layer* GetLayer() const { return m_pLayer; }

protected:
	//TODO: MonoBehavior 안의 좌표 크기 피봇을 추후 Transform 으로 이동하기!!

	//GameObject의 태그
	TAG tag;
	//GameObject의 좌표
	Vector2 pos;
	//GameObject의 크기
	Vector2 scale;
	//GameObject의 피봇
	Vector2 pivot;
	//GameObject의 각도 (추후 rotation으로 교체)
	float angle; //TODO: 추후 로테이션으로 교체하자

public:
	void SetTag(const TAG& tag) {
		this->tag = tag;
	}


	TAG GetTag() { return tag; }


	void SetPos(const Vector2& pos) {
		this->pos = pos;
	}

	void SetSize(const Vector2& size) {
		this->scale = size;
	}

	void SetPos(const double x, const double y) {
		this->pos.x = x;
		this->pos.y = y;
	}

	void SetSize(const double x, const double y) {
		this->scale.x = x;
		this->scale.y = y;
	}

	Vector2 GetPos() { return pos; }
	Vector2 GetSize() { return scale; }

	void SetAngle(float angle) { this->angle = angle; }
	float GetAngle() { return angle; }

public:
	virtual bool Enable();
	virtual bool Disable();
	virtual bool Init() = 0;
	virtual void Input(float deltaTime);
	virtual int Update(float deltaTime);
	virtual int LateUpdate(float deltaTime);
	virtual void Collision(float deltaTime);
	virtual void Render(HDC hdc, float deltaTime);
	virtual MonoBehavior* Clone() = 0;

public:
	template<typename T>
	static T* CreateMono(const TAG& tag, Layer* player = NULL);
	static MonoBehavior* CreateClone(const TAG& tagKey, const TAG& tag, class Layer* pLayer = NULL);
	

public:
	template<typename T>
	static T* CreatePrefab(const TAG& tagKey);

	static void ErasePrefab();
	static void ErasePrefab(const TAG& tag);

public:
	static MonoBehavior* FindPrefab(const TAG& tag);


public:
	void DrawRect(HDC hdc);
	void DrawRect(HDC hdc, Color rgb);
	void DrawEllipse(HDC hdc);
	void DrawEllipse(HDC hdc, Color rgb);
};

template<typename T>
static	T* MonoBehavior::CreatePrefab(const TAG& tagKey)
{
	T* pMono = new T;
	pMono->SetTag(tagKey);
	if (!pMono->Init())
	{
		SAFE_RELEASE(pMono);
		return NULL;
	}

	pMono->AddRef();
	m_Prefabmap.insert(make_pair(tagKey, pMono));
	return pMono;

}



template<typename T>
static T* MonoBehavior::CreateMono(const TAG& tag, Layer* pLayer)
{
	T* pMono = new T;
	pMono->SetTag(tag);
	if (!pMono->Init())
	{
		SAFE_RELEASE(pMono);
		return NULL;
	}

	if (pLayer)
	{
		pLayer->AddMono(pMono);
	}

	//생성된 GameObject를 추가
	AddMono(pMono);
	return pMono;
}


//static MonoBehavior* MonoBehavior::CreateClone(const TAG& tagKey, const TAG& tag)
//{
//	MonoBehavior* pPrefab = FindPrefab(tagKey);
//
//	if (!pPrefab) 
//	{
//		return NULL;
//	}  
//
//	pMono->SetTag(tag);
//	if (!pMono->Init())
//	{
//		SAFE_RELEASE(pMono);
//		return NULL;
//	}
//
//	if (pLayer)
//	{
//		pLayer->AddMono(pMono);
//	}
//
//	//생성된 GameObject를 추가
//	AddMono(pMono);
//	return pMono;
//}