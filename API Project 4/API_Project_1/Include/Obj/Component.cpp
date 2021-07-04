#include "Component.h"
#include "../Component/Sprite.h"
#include "../Component/Transform.h"
#include "../Component/RigidBody.h"
#include "../Component/Collider.h"
#include "../Core/ResourceManager.h"
//#include "../Component/.h"

Component::Component()
	:Object(), pSprite(NULL), speed(DEFAULT_SPEED)
{
}

Component::Component(const Component& obj)
{
	*this = obj;
	angle = obj.angle;
	speed = obj.speed;
	if (pSprite)
	{
		pSprite->AddRef();
	}
	
}

Component::~Component()
{
	SAFE_RELEASE(pSprite);
	SAFE_RELEASE(pRigidBody);
	SAFE_RELEASE(pTransform);
	SAFE_RELEASE(pCollider);
}


void Component::Translate(double x, double y)
{
    pos.x += x;
    pos.y += y;
}

void Component::Translate(double x, double y, double deltaTime)
{
    pos.x += x * deltaTime;
    pos.y += y * deltaTime;
}

void Component::Translate(const Vector2& vec)
{
    pos += vec;
}

void Component::Translate(const Vector2& vec, double deltaTime)
{
    pos += vec * deltaTime;
}

void Component::TranslateX(double x)
{
    pos.x += x;
}

void Component::TranslateX(double x, double deltaTime)
{
    pos.x += x * deltaTime;
}

void Component::TranslateY(double y)
{
    pos.y += y;
}

void Component::TranslateY(double y, double deltaTime)
{
    pos.y += y * deltaTime;
}

void Component::TranslateXInTime(double deltaTime, MOVE_DIR dir)
{
    pos.x += speed * deltaTime * (double)dir;
}

void Component::TranslateYInTime(double deltaTime, MOVE_DIR dir)
{
    pos.y += speed * deltaTime * (double)dir;
}

void Component::TranslateAngle()
{
    pos.x += cosf((float)angle) * speed;
    pos.y += sinf((float)angle) * speed;
}

void Component::TranslateAngle(double deltaTime)
{
    pos.x += cosf((float)angle) * speed * deltaTime;
    pos.y += sinf((float)angle) * speed * deltaTime;
}











void Component::Render(HDC hdc, double deltaTime)
{
	if (pSprite)
	{
		Vector2 pos = this->pos - scale * pivot;
		BitBlt(hdc, (int)(pos.x), int(pos.y), int(scale.x), int(scale.y), pSprite->GetDC(), 0, 0, SRCCOPY);
		//pSprite->Render(hdc, (int)(pos.x), int(pos.y));
	}
}

void Component::SetSprite(class Sprite* _pSprite) {
	SAFE_RELEASE(pSprite);
	pSprite = _pSprite;
	if (pSprite)
	{
		pSprite->AddRef();

	}
}

void Component::SetSprite(const string& strKey, const wchar_t* pFileName, const string& strPathKey)
{
	SAFE_RELEASE(pSprite);
	pSprite = SINGLETON(ResourceManager)->LoadSprite(strKey, pFileName, strPathKey);
}

void Component::SetSprite(const string& strKey, const int _width, const int _height, const wchar_t* pFileName,
	bool isTrans,
	COLORREF transColor,
	const string& strPathKey)
{
	SAFE_RELEASE(pSprite);
	pSprite = SINGLETON(ResourceManager)->LoadSprite(strKey, pFileName, _width, _height, isTrans, transColor, strPathKey);
}

