#pragma comment(lib, "winmm.lib")


#include<Windows.h>
#include <string>
#include <windef.h>
#include <stdint.h>
#include <vector>
using namespace std;

// �ü��
HINSTANCE m_hInstance;

// ������ �ڵ鷯
HWND m_hWnd;

// �»���� Ÿ��Ʋ �ؽ�Ʈ
LPTSTR m_lpszClass = TEXT("�ȳ�");
int oh = 0;


// �ݹ��Լ�
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

void DrawAppleLogo(HDC& hdc, const HWND& hWnd, PAINTSTRUCT& ps);

// �ν��Ͻ� �ڵ� ���� �ν��Ͻ� �ڵ�, ������� �̷���� , ���α׷��� ���۵� �ൿ
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpszCmdParam, int nCmdShow)
{
    m_hInstance = hInstance;

    //������â�� ������ �����ϴ� Ŭ����
    WNDCLASS wndClass;

    //�����쿡�� ����ϴ� �����ʹ����� ����Ʈ�� ����
    wndClass.cbClsExtra = 0;

    //�����޸𸮿��� ����ϴ� ������ �޸�
    wndClass.cbWndExtra = 0;

    //������ �۾������� ĥ�� ��� �귯��
    wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);

    //Ŀ�� ����
    wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);

    //Ÿ��Ʋ���� �»�� ������, �ּ�ȭ ������
    wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);

    // �������α׷��� �ν��Ͻ� �ڵ鷯
    wndClass.hInstance = hInstance;

    // �޼��� ó���ϴ� �Լ�
    wndClass.lpfnWndProc = (WNDPROC)WndProc;

    //����ϰ����ϴ� �����콺 �̸�
    wndClass.lpszClassName = m_lpszClass;

    //������ Ŭ���� ����
    wndClass.lpszMenuName = NULL;

    // ������ ��Ÿ�� ����
    wndClass.style = CS_HREDRAW | CS_VREDRAW;

    // ������ Ŭ���� ����
    RegisterClass(&wndClass);




    m_hWnd = CreateWindow(m_lpszClass, m_lpszClass, WS_OVERLAPPEDWINDOW,
        100, 100, 1024, 768, NULL, NULL, hInstance, NULL);

    ShowWindow(m_hWnd, nCmdShow);

    // �ü������ �߻��ϴ� �޼��� ������ �����ϱ� ���� ����ü
    MSG message;

    //GetMessage: ������
    while (GetMessage(&message, 0, 0, 0))
    {
        // Ű���� �Է� �޼��� ó�����
        TranslateMessage(&message);
        // ������ ���ν����� ���޵� �޼����� ���� �����쿡 ����
        DispatchMessage(&message);
    }

    return message.wParam;
}

static RECT rcHead = { 25,25,50,50 };
int dir[4] = { 0, 0, 1, 1 };
vector<RECT> rc;
//�޼��� ��ȣ, Ű���� ����Ű,  ���콺 ����
//������ ���ν��� : �޼����� �ü���� �����Ѵ�. ������ �ü���� ȣ��
//hWnd : �����찡 �߻��� �޼������� ����
//imessage : �޼��� ���� ��ȣ

//wParam : ���콺 ��ư�� ����, Ű���� ����Ű�� ���¸� �����Ѵ�.
//iParam : ���콺 Ŭ����ǥ ���¸� �����Ѵ�.



LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
    //DC : device context ->��¿� ���� �ɼ��� ����Ʈ�� ����

    //DC �� ����ϱ� ���� HDC, DC�� �ڵ� �̿�

    //GDI ��⿡ ���� ����

    //GDI ȭ�� ó���� �׷��� ����� �Ѵ�.

    //HDC ��¿� �ʿ��� ������ ������ ������ ����ü (��ǥ,���� ����� �ʿ��� ��������� ������ �ִ�)


    // ��¿� ���� ������ ���� �������� ����ü ��ǥ ���� �� ��
    //HDC hdc;

    //PAINTSTRUCT : ������ Ŭ���̾�Ʈ ������ �׸��� ���� ������ ������ ����ü
 /*   PAINTSTRUCT ps;*/


    
    PAINTSTRUCT ps;
    HDC hdc;
    float speed = 1;
    static int time = 0;
    char* szTime[128];
    static float m_fStartTime = 0;
    float NowTime = 0;

    //���� 
    
    //int StartTick
   
    //rc.top += speed * 1;
    //rc.bottom += speed * 1;
    switch (iMessage)
    {
        // ������ ��������� �ѹ� ȣ��Ǵ� �޼���
    case WM_CREATE:
        //���ۺκ�
        //m_fStartTime = (float)timeGetTime() * 0.001f;   //�ʴ����� �ٲ���
        SetTimer(hWnd, 0, 1000, NULL);


        break;
    case WM_TIMER:
        time++;
       //NowTime = (float)timeGetTime() * 0.001f;    //�ʴ����� �ٲ���

       // if (NowTime - m_fStartTime >= 0.01f)   // ���⼭ 0.1 �� 0.1�ʸ��� ������ �ǹ�
       // {

       //     if (rcHead.left + speed * dir[1] > 0 &&
       //         rcHead.right + speed * dir[0] < 500 &&
       //         rcHead.top + speed * dir[2] > 0 &&
       //         rcHead.bottom + speed * dir[3] < 500)
       //     {
       //         rcHead.left += speed * dir[1];
       //         rcHead.right += speed * dir[0];
       //         rcHead.top += speed * dir[2];
       //         rcHead.bottom += speed * dir[3];
       //     }
       // }

       // m_fStartTime = NowTime;
        InvalidateRect(hWnd, NULL, true);
        break;
    case WM_KEYDOWN:

        switch (wParam)
        {
        case VK_RIGHT:
            dir[0] = 1;
            dir[1] = 1;
            dir[2] = 0;
            dir[3] = 0;
            break;
        case VK_LEFT:
            dir[0] = -1;
            dir[1] = -1;
            dir[2] = 0;
            dir[3] = 0;
            break;
        case VK_DOWN:
            dir[2] = 1;
            dir[3] = 1;
            dir[1] = 0;
            dir[0] = 0;
            break;
        case VK_UP:
            dir[2] = -1;
            dir[3] = -1;
            dir[1] = 0;
            dir[0] = 0;
            break;
        case VK_RETURN:

            break;
        default:
            break;
        }
        break;
    case WM_PAINT: // �׸��׸��� ��
        ////DrawAppleLogo(hdc, hWnd, ps);
        hdc = BeginPaint(hWnd, &ps);
        //sprintf(szTime, "%d �� �������ϴ�.", time);

        //TextOut(hdc, 100, 100, szTime, strlen(szTime));

        //Rectangle(hdc, rcHead.left, rcHead.top, rcHead.right, rcHead.bottom);
        EndPaint(hWnd, &ps);


        break;
        // ���� ���콺 Ŭ����
    case WM_LBUTTONDOWN:

        rcHead.left += 50;



        break;
    case WM_DESTROY: // ������ ����� 
        KillTimer(hWnd, 1);

        PostQuitMessage(0);
        return 0;
    }
    return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}






void DrawAppleLogo(HDC& hdc, const HWND& hWnd, PAINTSTRUCT& ps)
{
    HBRUSH brush, oBrush;


    POINT pt = { 100,100 };
    POINT pline1[14] = {
100,170,
380,170,
377,178,
374,186,
371,194,
368,202,
365,210,
362,218,
88,218,
90,210,
92,202,
94,194,
96,186,
98,178
    };
    Polygon(hdc, pline1, 14);
    brush = CreateSolidBrush(RGB(255, 255, 0));
    oBrush = (HBRUSH)SelectObject(hdc, brush);
    SelectObject(hdc, oBrush);
    DeleteObject(brush);



    ////�ؽ�Ʈ
    //TextOut(hdc, 300, 500, L"�����ڽľ�!!", lstrlen(L"�����ڽľ�!!"));

    //����
    //SetTextColor(hdc, RGB(255, 0, 0));
    //TextOut(hdc, 100, 100, L"���� �̰;�!!", lstrlen(L"���� �̰;�!!"));

    EndPaint(hWnd, &ps);
}

//
//
//
//void UpdateFPS()
//{
//
//    static DWORD frameCount = 0;            //������ ī��Ʈ��
//    static float timeElapsed = 0.0f;            //�帥 �ð�
//    static DWORD lastTime = timeGetTime();   //������ �ð�(temp����)
//
//    DWORD curTime = timeGetTime();      //���� �ð�
//    float timeDelta = (curTime - lastTime) * 0.001f;        //timeDelta(1�������� �帥 �ð�) 1�ʴ����� �ٲ��ش�.
//
//    timeElapsed += timeDelta;
//
//    frameCount++;
//
//    if (timeElapsed >= 1.0f)         //�帥�ð��� 1���̻��̸� ���� �ϰ������ ó��
//    {
//        float fps = (float)frameCount / timeElapsed;
//        sprintf_s(pFPS, sizeof(pFPS), TEXT("���Ӽӵ� FPS: %f"), fps);     //FPS��� �ϴ� �ҽ�
//
//        frameCount = 0;
//        timeElapsed = 0.0f;
//    }
//    else
//    {
//        //�帥 �ð��� 1�ʰ� �ȵǸ� ������  
//        //Sleep() �ص��ǰ� ���ص� �Ǳ�~ 
//    }
//
//
//    lastTime = curTime;
//}