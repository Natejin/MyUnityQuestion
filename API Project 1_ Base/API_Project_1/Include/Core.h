
#include "Singleton.h"
class Core : public Singleton<Core>
{
private:
	HINSTANCE hInst;
	HWND hWnd;
	RESOLUTION typeResolution;
	static bool loop;

public:
	bool Init(HINSTANCE hinst);
	int Run();

private:
	ATOM MyRegisterClass();
	BOOL Create();

public :
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};


