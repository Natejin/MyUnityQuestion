#include "BulletUIManager.h"



HRESULT BulletUIManager::init()
{
	m_gaugeFront = RectMakeCenter(WINSIZEX / 2 + 300, 100, 400, 50);
	m_gaugeBack = RectMakeCenter(WINSIZEX / 2 + 300, 100, 400, 50);

	m_red = 0;
	m_green = 255;
	return S_OK;
}

void BulletUIManager::release()
{
}

void BulletUIManager::update()
{
	GaugeDraw();
}

void BulletUIManager::render(HDC hdc)
{
	UFUNC->DrawRect(hdc, m_gaugeFront);
	UFUNC->DrawRect(hdc, m_gaugeBack, Color(m_red, m_green, 0));
}

void BulletUIManager::GaugeDraw()
{
	if (m_gaugeFront.right - m_gaugeFront.left <= 200)
	{
		m_red = 200;
	}
	if (m_gaugeFront.right - m_gaugeFront.left <= 80)
	{
		m_red = 255;
		m_green = 0;
	}
}
