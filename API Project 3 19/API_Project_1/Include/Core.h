
#include "Singleton.h"
class Core : public Singleton<Core>
{
private:
	HINSTANCE hInst;
	HWND hWnd;
	HDC hdc;
	RESOLUTION typeResolution;
	static bool loop;

public:
	RESOLUTION GetResolution() const {return typeResolution;	}
public:
	bool Init(HINSTANCE hinst);
	int Run();
	Core();
	~Core();

private:
	void Logic();

private:
	ATOM MyRegisterClass();
	BOOL Create();

private:
	void InputManager(float deltaTime);
	int Update(float deltaTime);
	int LateUpdate(float deltaTime);
	void Collision(float deltaTime);
	void Render(float deltaTime);

public :
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};


