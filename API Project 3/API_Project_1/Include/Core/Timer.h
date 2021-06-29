#pragma once
#include "../Singleton.h"

class Timer : public Singleton<Timer>
{
private:
	LARGE_INTEGER m_tSecond;
	LARGE_INTEGER m_tTime;
	float m_fDeltaTime;
	float m_fFPS;
	float m_fFPSTime;
	int m_iFrameMax;
	int m_iFrame;

public:
	float GetDeltaTime() const {
		return m_fDeltaTime;
	}

	float GetFPS() const {
		return m_fFPS;
	}

public:
	Timer();
	~Timer();
	bool Init();
	void Update();
};

