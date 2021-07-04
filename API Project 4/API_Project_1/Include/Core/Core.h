
#include "Singleton.h"

#include <xinput.h>
#pragma comment(lib, "xinput.lib")
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
	void Input(double deltaTime);
	int Update(double deltaTime);
	int LateUpdate(double deltaTime);
	void Collision(double deltaTime);
	void Render(double deltaTime);

public :
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};

#define CORE			Core::GetSingleton()
#define GETRESOLUTION	Core::GetSingleton()->GetResolution()
