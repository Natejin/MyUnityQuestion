#include "../Game.h"
#include "../Ref.h"
#include <Windows.h>

class Obj : public Ref {
protected:
	Obj();
	Obj(const Obj& obj);
	virtual ~Obj();

protected:
	class Scene* pScene;
	class Layer* pLayer;

public:
	void SetScene(class Scene* pScene) { this->pScene = pScene; }
	void SetLayer(class Layer* pLayer) { this->pLayer = pLayer; }

	class  Scene* GetScene() const { return pScene; }
	class  Layer* GetLayer() const { return pLayer; }

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
	static T* CreateObj(const TAG& tag, class Layer* layer = NULL);

public:
	void DrawRect(HDC hdc);
	void DrawRect(HDC hdc, Color rgb);

};

template<typename T>
inline T* Obj::CreateObj(const TAG& tag, Layer* layer)
{
	T* pObj = new T;
	if (!pObj->Init())
	{
		SAFE_RELEASE(pObj);
		return NULL;
	}

	if (pLayer)
	{
		pObj->AddObject(pObj);
	}
	pObj->AddRef();
	return pObj;
}
