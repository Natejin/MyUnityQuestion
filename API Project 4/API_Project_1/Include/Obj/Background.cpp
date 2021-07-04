#include "BackGround.h"
#include "../Component/Sprite.h"
#include "../Core/Core.h"

Background::Background(const Background& obj)
	:MonoBehavior(obj)
{
}

Background::~Background()
{
}

Background::Background()
	:MonoBehavior()
{
}

bool Background::Enable()
{
	return true;
}

bool Background::Disable()
{
	return true;
}

bool Background::Init()
{
	SetPos(Vector2(0, 0));
	SetSize(Vector2(1920, 1080));
	SetPivot(Vector2(0, 0));

	SetSprite("Background1", TEXT("BackGround_Forest_BG_01.bmp"));

	//SetSpeed(400);
	return true;
}

void Background::Input(double deltaTime)
{
	MonoBehavior::Input(deltaTime);
}

int Background::Update(double deltaTime)
{
	MonoBehavior::Update(deltaTime);
	return 0;
}

int Background::LateUpdate(double deltaTime)
{
	MonoBehavior::LateUpdate(deltaTime);
	return 0;
}

void Background::Collision(double deltaTime)
{
	MonoBehavior::Collision(deltaTime);
}

void Background::Render(HDC hdc, double deltaTime)
{
	//MonoBehavior::Render(hdc, deltaTime);
	Vector2 pos = this->pos - scale * pivot;
	BitBlt(hdc, (int)(pos.x), int(pos.y), 
		GETRESOLUTION.width, 
		GETRESOLUTION.height, pSprite->GetDC(), 0, 0, SRCCOPY);
} 

Background* Background::Clone()
{
	return new Background(*this);
}
