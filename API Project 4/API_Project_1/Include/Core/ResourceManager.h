#pragma once
#include "Singleton.h"
#include "../Component/Sprite.h"

class ResourceManager : public Singleton<ResourceManager>
{
private:
	unordered_map<string, class Sprite*> imageMap;
	HINSTANCE hInst;
	HDC hdc;

public:
	ResourceManager() ;
	~ResourceManager();


	bool Init(HINSTANCE hInst, HDC hdc);

	class Sprite* CreateSprite(const string& strKey, int width, int height);

	class Sprite* LoadSprite(const string& strKey, const wchar_t* pFileName,
		const string& strPathKey = TEXTURE_PATH);

	class Sprite* LoadSprite(const string& strKey, const wchar_t* pFileName,
		const int _width, const int _height,
		bool isTrans = false,
		COLORREF transColor = RGB(255, 0, 255),
		const string& strPathKey = TEXTURE_PATH);
	class Sprite* FindSprite(const string& strKey);

	//¹é¹öÆÛ
private:
	Sprite* pBackBuffer;
public:
	Sprite* GetBackBuffer() const;
};

 