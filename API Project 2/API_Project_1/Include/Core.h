
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
	Core();
	~Core();

private:
	ATOM MyRegisterClass();
	BOOL Create();
	void Logic();

public :
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};


