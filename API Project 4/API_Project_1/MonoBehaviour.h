#include "../Game.h"
#include "../Ref.h"
#include "../Scene/Layer.h"
#include <Windows.h>

class Obj : public Ref {
protected:
	Obj();
	Obj(const Obj& monoBehavilour);
	virtual ~Obj();

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
	TAG tag;
	Vector2 pos;
	Vector2 size;
	Vector2 pivot;
	

public:
	void SetTag(const TAG& tag) {
		this->tag = tag;
	}

	void SetPos(const Vector2& pos) {
		this->pos = pos;
	}

	void SetSize(const Vector2& size) {
		this->size = size;
	}

	void SetPos(const float x, const float y) {
		this->pos.x = x;
		this->pos.y = y;
	}

	void SetSize(const float x, const float y) {
		this->size.x = x;
		this->size.y = y;
	}

	TAG GetTag() { return tag; }
	Vector2 GetPos() { return pos; }
	Vector2 GetSize() { return size; }

public:
	virtual bool Enable();
	virtual bool Disable();
	virtual bool Init() = 0;
	virtual void Input(float deltaTime);
	virtual int Update(float deltaTime);
	virtual int LateUpdate(float deltaTime);
	virtual void Collision(float deltaTime);
	virtual void Render(HDC hdc, float deltaTime);

public:
	template<typename T>
	static T* CreateObj(const TAG& tag, Layer* player = NULL)
	{
		T* pMonoBehavilour = new T;
		if (!pMonoBehavilour->Init())
		{
			SAFE_RELEASE(pMonoBehavilour);
			return NULL;
		}

		if (player)
		{
			player->AddObject(pMonoBehavilour);
		}
		pMonoBehavilour->AddRef();
		return pMonoBehavilour;
	}


public:
	void DrawRect(HDC hdc);
	void DrawRect(HDC hdc, Color rgb);

};

