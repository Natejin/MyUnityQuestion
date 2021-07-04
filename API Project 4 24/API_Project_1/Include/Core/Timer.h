#pragma once
#include "Singleton.h"

class Timer : public Singleton<Timer>
{
private:
	LARGE_INTEGER m_tSecond;
	LARGE_INTEGER m_tTime;
	
	double m_fDeltaTime;
	double m_fTimeScale;
	double m_fFPS;
	double m_fFPSTime;
	int m_iFrameMax;
	int m_iFrame;

public:
	double GetDeltaTime() const {
		return m_fDeltaTime;
	}

	double GetFPS() const {
		return m_fFPS * m_fTimeScale;
	}

	double GetTimeScale() { return m_fTimeScale; }
	double SetTimeScale(double timeScale) { m_fTimeScale = timeScale; }

public:
	Timer();
	~Timer();
	bool Init();
	void Update();
};

