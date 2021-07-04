#include "Component.h"
#include "../InputManager.h"



#define INPUT InputManager::GetSingleton()

class MonoBehavior : public Component {
protected:

	MonoBehavior(const MonoBehavior& obj);
	virtual ~MonoBehavior();

private:

	//�ش� ������ ����ϴ� ��� GameObject 
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
	//������Ʈ�� ���� ���� ������
	class Scene* m_pScene;
	//������Ʈ�� ���� ���� ���̾�
	class Layer* m_pLayer;

public:
	//�� ����
	void SetScene(class Scene* pScene) { this->m_pScene = pScene; }
	//���̾� ����
	void SetLayer(class Layer* pLayer) { this->m_pLayer = pLayer; }

	class  Scene* GetScene() const { return m_pScene; }
	class  Layer* GetLayer() const { return m_pLayer; }

protected:
	//TODO: MonoBehavior ���� ��ǥ ũ�� �Ǻ��� ���� Transform ���� �̵��ϱ�!!

	//GameObject�� �±�
	TAG tag;
	//GameObject�� ��ǥ
	Vector2 pos;
	//GameObject�� ũ��
	Vector2 scale;
	//GameObject�� �Ǻ�
	Vector2 pivot;
	//GameObject�� ���� (���� rotation���� ��ü)
	float angle; //TODO: ���� �����̼����� ��ü����

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

	//������ GameObject�� �߰�
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
//	//������ GameObject�� �߰�
//	AddMono(pMono);
//	return pMono;
//}