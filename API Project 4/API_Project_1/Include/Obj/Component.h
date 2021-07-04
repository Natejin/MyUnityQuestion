#pragma once
#include "Object.h"

//양방향 참조를 방지하기위해 선언
class Sprite;
class Transform;
class RigidBody;
class Collider;
class Component : public Object
{
	//TODO: MonoBehavior 안의 좌표 크기 피봇을 추후 Transform 으로 이동하기!!
	//TODO: 나중에 Transform에 넣어야함
protected:
	//GameObject의 좌표
	Vector2 pos;
	//GameObject의 크기
	Vector2 scale;
	//GameObject의 피봇
	Vector2 pivot;
	//GameObject의 각도 (추후 rotation으로 교체)
	double angle; //TODO: 추후 로테이션으로 교체하자
public:
	void SetPos(const Vector2& pos) {
		this->pos = pos;
	}
	void SetPos(const double x, const double y) {
		this->pos.x = x;
		this->pos.y = y;
	}

	void SetSize(const Vector2& size) {
		this->scale = size ;
	}

	void SetSize(const double x, const double y) {
		this->scale.x = x;
		this->scale.y = y;
	}

	void SetPivot(const Vector2& pivot) {
		this->pivot = pivot;
	}

	void SetPivot(const double x, const double y) {
		this->pivot.x = x;
		this->pivot.y = y;
	}

	void SetAngle(double angle) { this->angle = angle; }




	Vector2 GetPos() { return pos; }
	Vector2 GetSize() { return scale; }
	Vector2 GetPivot() { return pivot; }
	double GetAngle() { return angle; }

protected:

	double speed;

public:
	void SetSpeed(double speed) { this->speed = speed; }
	double GetSpeed() { return speed; }
public:
	void Translate(double x, double y);
	void Translate(double x, double y, double deltaTime);
	void Translate(const Vector2& vec);
	void Translate(const Vector2& vec, double deltaTime);

	void TranslateX(double x);
	void TranslateX(double x, double deltaTime);


	void TranslateY(double y);
	void TranslateY(double y, double deltaTime);

	void TranslateXInTime(double deltaTime, MOVE_DIR dir);
	void TranslateYInTime(double deltaTime, MOVE_DIR dir);

	void TranslateAngle(); //TODO 회전함수 추후 벡터로 변경
	void TranslateAngle(double deltaTime);


///////////////////////////////////////////////////////////////////////


	//Component 관련
protected:

	Component(const Component& obj);
	virtual ~Component();

protected:
	Transform*	pTransform;
	RigidBody*	pRigidBody;
	Sprite*		pSprite;
	Collider*	pCollider;

private:
	//Component* transform;
	//Component* rigidbody;
	//Component* collider;
	//Component* sprite;

public:
	Component();
	Transform* Get_transform() { return pTransform; }
	RigidBody* Get_rigidbody() { return pRigidBody; }
	Sprite*  Get_sprite() { return pSprite; }
	Collider* Get_collider() { return pCollider; }
	//virtual bool Enable();
	//virtual bool Disable();
	//virtual bool Init() = 0;
	//virtual int Update(double deltaTime);
	//virtual int LateUpdate(double deltaTime);
	//virtual void Collision(double deltaTime);

	//Sprite가 사용함
	virtual void Render(HDC hdc, double deltaTime);
public:
	//template <typename T = Component>
	//T* GetComponent();
public:
	void SetSprite(class Sprite* pSprite);
	//void SetSprite(const string& strKey, const wchar_t* pFileName = NULL, const string& strPathKey = TEXTURE_PATH);
	void SetSprite(const string& strKey, const wchar_t* pFileName = NULL, const string& strPathKey = TEXTURE_PATH);

	void SetSprite(const string& strKey, const int _width, const int _height, const wchar_t* pFileName = NULL,
		bool isTrans = false,
		COLORREF transColor = RGB(255, 0, 255),
		const string& strPathKey = TEXTURE_PATH);

};

